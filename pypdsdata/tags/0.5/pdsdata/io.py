#
# $Id$
#
# Copyright (c) 2010 SLAC National Accelerator Laboratory
# 

from _pdsdata import xtc
import logging
import os

_log = logging.getLogger("pdsdata.io")

#
# iterator which scans multiple chunk files
#
def _genXtcChunkIterator( files, bufsize=-1 ):
    """ helper generator object """
    for fname in files :
        dgiter = xtc.XtcFileIterator( open(fname, 'rb', bufsize) )
        count = 0
        for dg in dgiter :
            yield ( dg, fname, count )
            count += 1

class XtcChunkIterator (object) :
    
    """ Iterator class which returns sequential ordered datagrams from 
    multiple chunked files. Constructor takes the list of file names
    whcih will be scanned in the same order."""
    
    def __init__ ( self, files, bufsize=-1 ) :
        
        _log.debug("XtcChunkIterator: files=%s", files)
        self.m_gen = _genXtcChunkIterator( files, bufsize )

        self.m_fname = None
        self.m_dgindex = 0

    def __iter__ (self) :
        """ imagine we are iterator """
        return self

    def next(self):
        """ advance to next datagram possibly switching to next file """
        
        self.m_fname = None
        self.m_dgindex = 0
        
        dg, self.m_fname, self.m_dgindex = self.m_gen.next()
        return dg

    def fileName(self):
        """ get the name of the currently read file """
        return self.m_fname
        
    def basename(self):
        """ get the name of the currently read file """
        return os.path.basename(self.m_fname)
        
    def dgIndex(self):
        """ get the index of the last read histogram in a file """
        return self.m_dgindex
        

#
# iterator which merges multiple streams into one
#
class XtcStreamMerger(object) :

    """ Iterator class which merges datagrams from several separate streams.
    Constructor takes the list of the individual stream iterators, each iterator
    is supposed to return a sequence of time-ordered datagrams. """

    def __init__ (self, streamItreators, l1OffsetSec = 0):

        self.m_streams = streamItreators
        self.m_l1OffsetSec = l1OffsetSec
        
        # list of datagrams per stream
        self.m_dgs = []
        for stream in self.m_streams :
            try :
                dg = stream.next()
            except StopIteration :
                dg = None
            self.m_dgs.append( dg )

    def _dgramTime(self, dg):
        """ corrects datagram time for L1Accept transitions """
        if dg.seq.service == xtc.TransitionId.L1Accept :
            time = dg.seq.clock()
            return ClockTime( time.seconds()-self.m_l1OffsetSec, time.nanoseconds() )
        else :
            return dg.seq.clock()
            
    def __iter__ (self) :
        """ imagine we are iterator """
        return self

    def next(self):
        """ return next diagram in the time order """

        # find stream/datagram with minimal time
        ns = len(self.m_dgs)
        stream = -1
        for i in range(ns) :
            if self.m_dgs[i] :
                if stream < 0 or self._dgramTime(self.m_dgs[stream]) > self._dgramTime(self.m_dgs[i]) :
                    stream = i
                    
        if stream < 0 :
            # means no more non-empty streams left, stop iteration
            raise StopIteration

        nextdg = self.m_dgs[stream]

        # check the type of the datagram, for L1Accept give it to the caller,
        # all other datagram types must appear in all streams, return only one copy
        if nextdg.seq.service() == xtc.TransitionId.L1Accept :

            try :
                self.m_dgs[stream] = self.m_streams[stream].next()
            except StopIteration :
                self.m_dgs[stream] = None

        else :

            # check that all streams are in sync
            for i in range(ns) :
                dg = self.m_dgs[i]
                if dg and dg.seq.service() != nextdg.seq.service() :
                    try:
                        # this can throw if the iterator is not of XtcChunkIterator type
                        _log.error("streams desynchronized:" +
                                   "\n    stream[%d] = %s service = %s time = %s damage = %x " +
                                   "\n    stream[%d] = %s service = %s time = %s damage = %x",
                                    stream, self.m_streams[stream].basename(), nextdg.seq.service(), 
                                    nextdg.seq.clock(), nextdg.xtc.damage.value(),
                                    i, self.m_streams[i].basename(), dg.seq.service(), 
                                    dg.seq.clock(), dg.xtc.damage.value()
                                    )
                    except :
                        _log.error("streams desynchronized:" +
                                   "\n    stream = %d service = %s time = %s damage = %x " +
                                   "\n    stream = %d service = %s time = %s damage = %x",
                                    stream, nextdg.seq.service(), 
                                    nextdg.seq.clock(), nextdg.xtc.damage.value(),
                                    i, dg.seq.service(), 
                                    dg.seq.clock(), dg.xtc.damage.value()
                                    )
                    raise Error("streams desynchronized")

            # advance all iterators to next datagram
            for i in range(ns) :
                try :
                    self.m_dgs[i] = self.m_streams[i].next()
                except StopIteration :
                    self.m_dgs[i] = None
            
        return nextdg

#
# Class which can be used to extract run/stream/chunk from file name
#
def _cvt ( code, pfx ):
    if len(code)>1 and code[0] == pfx :
        try :
            return int(code[1:])
        except :
            pass
    return None
    

class XtcFileName(str) :
    """ Class representing file name. It is ordinary string with few 
    additional methods: expNum(), run(), stream(), chunk(). When
    file name has format [/dirname/]eNN-rMM-sKK-cLL.ext then those
    method will return corresponding numbers. Otherwise they all 
    return None. """

    partsSep = '-'

    def __init__ ( self, name ):
        
        str.__init__( self, name )
        
        # get all pieces
        self.m_expNum = None
        self.m_run = None
        self.m_stream = None
        self.m_chunk = None

        # get basename drop extension
        basename = os.path.basename(name).split('.')[0]
        
        # split into experiment-run-stream-chunk
        parts = basename.split(XtcFileName.partsSep)
        
        # name must look like eNN-rNN-sNN-cNN
        if len(parts) != 4 : return
        
        # convert to numbers
        parts = map( _cvt, parts, ['e', 'r', 's', 'c'] )        
        if None not in parts :
            self.m_expNum = parts[0]
            self.m_run = parts[1]
            self.m_stream = parts[2]
            self.m_chunk = parts[3]

    def expNum(self):
        return self.m_expNum

    def run(self):
        return self.m_run

    def stream(self):
        return self.m_stream

    def chunk(self):
        return self.m_chunk


#
# iterator which merges multiple streams into one
#
class XtcMergeIterator(XtcStreamMerger) :

    """ Iterator class which merges datagrams from several separate streams.
    Constructor takes the list of the file names acceptable by XtcFileName. """

    def __init__ (self, files, l1OffsetSec = 0, bufsize=-1):

        xfiles = [ XtcFileName(f) for f in files ]

        _log.debug("XtcMergeIterator: files=%s", xfiles)
        
        # check they all from the same experiment and run
        exp = set()
        runs = set()
        for file in xfiles :
            exp.add( file.expNum() ) 
            runs.add( file.run() )
        if len(exp)>1 or len(runs)>1 :
            raise Error("file names from different runs or experiments")

        # group by stream
        streams = {}
        for file in xfiles :
            chunks = streams.setdefault( file.stream(), [] )
            chunks.append( file )
        
        # make iterators for each stream
        streamIters = []
        for chunks in streams.itervalues() :
            chunks.sort( lambda x,y : cmp(x.chunk(), y.chunk()) )
            streamIters.append( XtcChunkIterator(chunks, bufsize) ) 

        # call base class ctor and give it all this
        XtcStreamMerger.__init__( self, streamIters, l1OffsetSec )
