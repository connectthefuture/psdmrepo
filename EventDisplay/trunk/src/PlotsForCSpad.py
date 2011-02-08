#--------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  Module PlotsForCSpad...
#
#------------------------------------------------------------------------

"""Plots for CSpad detector in the EventeDisplay project.

This software was developed for the SIT project.  If you use all or 
part of it, please give an appropriate acknowledgment.

@see RelatedModule

@version $Id: template!python!py 4 2008-10-08 19:27:36Z salnikov $

@author Mikhail S. Dubrovin
"""

#------------------------------
#  Module's version from CVS --
#------------------------------
__version__ = "$Revision: 4 $"
# $Source$

#--------------------------------
#  Imports of standard modules --
#--------------------------------
import sys
import matplotlib.pyplot as plt
import time
from numpy import *  # for use like       array(...)
import numpy as np

#-----------------------------
# Imports for other modules --
#-----------------------------

import ConfigParameters as cp

#---------------------
#  Class definition --
#---------------------
class PlotsForCSpad ( object ) :
    """Plots for CSpad detector in the EventeDisplay project.

    @see BaseClass
    @see OtherClass
    """

    #----------------
    #  Constructor --
    #----------------
    def __init__ ( self ) :
        """Constructor initialization.
        """

        print '\n Initialization of the PlotsForCSpad'
        #print 'using MPL version: ', matplotlib.__version__
        #self.fig1_window_is_open = False

    #-------------------
    #  Public methods --
    #-------------------

    def plotCSpadV1Image( self, arr1ev, fig, plot=8 ):
        """Plot 2d image from input array. V1 for run ~546, array for entire detector"""
        self.quad=cp.confpars.cspadQuad
        arr1quad = arr1ev[self.quad,...] 

        if plot ==  1     : self.plotCSpadPairImage   ( arr1quad, fig )
        if plot ==  8     : self.plotCSpad08PairsImage( arr1quad, fig )
        if plot == 'Quad' : self.plotCSpadQuadImage   ( arr1quad, fig )

    def plotCSpadV2Image( self, arr1ev, fig, plot=8 ):
        """Plot 2d image from input array. V2 for run ~900 contain array for quad 2"""
        self.quad=cp.confpars.cspadQuad
        pair00 = 8*self.quad
        pair08 = pair00 + 8
        arr1quad = arr1ev[pair00:pair08,...]
        #arr1quad = np.zeros( (8,185,388) )
        #arr1quad[0:8, 0:185, 0:388] += arr1ev[pair00:pair08, 0:185, 0:388]

        print 'arr1quad.shape=',arr1quad.shape
        print 'arr1quad.size =',arr1quad.size
        print 'arr1quad.dtype=',arr1quad.dtype
        print 'arr1quad.ndim =',arr1quad.ndim
        arr1quad = arr1ev
        if plot ==  1     : self.plotCSpadPairImage   ( arr1quad, fig )
        if plot ==  8     : self.plotCSpad08PairsImage( arr1quad, fig )
        if plot == 'Quad' : self.plotCSpadQuadImage   ( arr1quad, fig )
        if plot == 'Det'  : self.plotCSpadQuadImage   ( arr1ev,   fig )


    def plotCSpadV1Spectrum( self, arr1ev, fig, plot=16 ):
        """Plot 2d image from input array. V1 for run ~546, array for entire detector"""
        self.quad=cp.confpars.cspadQuad
        arr1quad = arr1ev[self.quad,...] 
        if plot ==  8 : self.plotCSpadQuad08SpectraOf2x1( arr1quad, fig )
        if plot == 16 : self.plotCSpadQuad16Spectra( arr1quad, fig )

    def plotCSpadV2Spectrum( self, arr1ev, fig, plot=16 ):
        """Plot 2d image from input array. V2 for run ~900 contain array for quad 2"""
        self.quad=cp.confpars.cspadQuad
        pair00 = 8*self.quad
        pair08 = pair00 + 8
        arr1quad = arr1ev[pair00:pair08,...]
        #arr1quad = arr1ev        
        if plot ==  8 : self.plotCSpadQuad08SpectraOf2x1( arr1quad, fig )
        if plot == 16 : self.plotCSpadQuad16Spectra( arr1quad, fig )




    def plotCSpad08PairsImage( self, arr1quad, fig ):
        """Plot 2d image of 8 2x1 pairs of ASICs' from input array."""

        #print 'plot_CSpadQuad()'       

        str_event = 'Event ' + str(cp.confpars.eventCurrent)
        #plt.title(str_event,color='r',fontsize=40) # pars like in class Text

        fig.canvas.set_window_title('CSpad image ' + str_event)
        plt.clf() # clear plot


        arrgap=zeros( (185,4) ) # make additional 2D-array of 0-s for the gap between two 1x1 pads
        
        for pair in xrange(8): # loop for pair = 0,1,2,...,7
            #print 'pair=', pair
        
            asic1x2  = arr1quad[pair,...]
            #asic1x2  = arr1ev[quad,pair,...]
            #print 'asic1x2=',asic1x2    
        
            asics    = hsplit(asic1x2,2)
            arr      = hstack((asics[0],arrgap,asics[1]))
        
            panel = 421+pair
            pantit='ASIC ' + str(2*pair) + ', ' + str(2*pair+1)

            plt.subplot(panel)
            plt.imshow(arr,  origin='down', interpolation='nearest') # Just a histogram
            plt.clim(cp.confpars.cspadImageAmin,cp.confpars.cspadImageAmax)

            plt.title(pantit,color='r',fontsize=20) # pars like in class Text

            #subp1 = self.fig1.add_subplot(panel)
            #subp1.imshow(arr, origin='upper', interpolation='nearest') # Just a histogram
            #subp1.title(pantit,color='r',fontsize=20) # pars like in class Text
            #plt.xlabel('X pixels')
            #plt.ylabel('Y pixels')
            #plt.margins(x=0.05,y=0.05,tight=True)
            #plt.rc('lines', linewidth=2, color='r') # Set the current default parameters
        
            #plt.savefig("my-image-hdf5.png")

            if pair==0 :
                plt.text(370, 192, str_event, fontsize=24)




    def plotCSpadQuadImage( self, arr1quad, fig ):
        """Plot 2d image of the quad from input array."""

        #print 'plot_CSpadQuad()'       

        str_event = 'Event ' + str(cp.confpars.eventCurrent)
        #plt.title(str_event,color='r',fontsize=40) # pars like in class Text

        fig.canvas.set_window_title('CSpad image ' + str_event)
        plt.clf() # clear plot

        arr2dquad = np.zeros( (1000,1000) )
        print 'arr2dquad.shape=',arr2dquad.shape

        #arr1quad[0:8, 0:185, 0:388] += arr1ev[pair00:pair08, 0:185, 0:388]

        print 'arr1quad.shape=',arr1quad.shape
        print 'arr1quad.size =',arr1quad.size
        print 'arr1quad.dtype=',arr1quad.dtype
        print 'arr1quad.ndim =',arr1quad.ndim

        arrgap=zeros( (185,4) ) # make additional 2D-array of 0-s for the gap between two 1x1 pads
        
        for pair in xrange(8): # loop for pair = 0,1,2,...,7
            #print 'pair=', pair
        
            asic1x2  = arr1quad[pair,...]
            #asic1x2  = arr1ev[quad,pair,...]
            #print 'asic1x2=',asic1x2    
        
            asics    = hsplit(asic1x2,2)
            arr      = hstack((asics[0],arrgap,asics[1]))
        
            panel = 421+pair
            pantit='ASIC ' + str(2*pair) + ', ' + str(2*pair+1)

            plt.subplot(panel)
            plt.imshow(arr,  origin='down', interpolation='nearest') # Just a histogram
            plt.clim(cp.confpars.cspadImageAmin,cp.confpars.cspadImageAmax)

            plt.title(pantit,color='r',fontsize=20) # pars like in class Text

            #subp1 = self.fig1.add_subplot(panel)
            #subp1.imshow(arr, origin='upper', interpolation='nearest') # Just a histogram
            #subp1.title(pantit,color='r',fontsize=20) # pars like in class Text

            #plt.xlabel('X pixels')
            #plt.ylabel('Y pixels')
        
            #plt.margins(x=0.05,y=0.05,tight=True)
            #plt.rc('lines', linewidth=2, color='r') # Set the current default parameters
        
            #plt.savefig("my-image-hdf5.png")

            if pair==0 :
                plt.text(370, 192, str_event, fontsize=24)


    def plotCSpadQuad08SpectraOf2x1( self, arr1quad, fig ):
        """Amplitude specra from 2d array."""

        fig.canvas.set_window_title('CSpad Quad Specra of 2x1')
        plt.clf() # clear plot
        #plt.title('Spectra',color='r',fontsize=20)
        fig.subplots_adjust(left=0.10, bottom=0.05, right=0.98, top=0.95, wspace=0.2, hspace=0.1)

        t_start = time.clock()
        
        for pair in xrange(8): # loop for pair = 0,1,2,...,7

            #print 20*'=',' Pair =', pair

            asic1x2  = arr1quad[pair,...]
            #print 'asic1x2.shape =', asic1x2.shape
            arrdimX,arrdimY = asic1x2.shape
            asic1d = asic1x2

            #asic1d.shape=(arrdimX*arrdimY,1)  
            asic1d.resize(arrdimX*arrdimY)            

            plt.subplot(421+pair)
            plt.hist(asic1d, bins=cp.confpars.cspadSpectrumNbins, range=(cp.confpars.cspadSpectrumAmin,cp.confpars.cspadSpectrumAmax))

            xmin, xmax = plt.xlim()
            plt.xticks( arange(int(xmin), int(xmax), int((xmax-xmin)/3)) )
            ymin, ymax = plt.ylim()
            plt.yticks( arange(int(ymin), int(ymax), int((ymax-ymin)/3)) )

            pantit='ASIC ' + str(2*pair) + ', ' + str(2*pair+1)
            ax = plt.gca()
            plt.text(0.04,0.84,pantit,color='r',fontsize=20,transform = ax.transAxes)

            if pair==0 :
                str_event = 'Event ' + str(cp.confpars.eventCurrent)
                plt.text(0.8,1.05,str_event,color='b',fontsize=24,transform = ax.transAxes)

        print 'Time to generate all histograms (sec) = %f' % (time.clock() - t_start)


    def plotCSpadQuad16Spectra( self, arr1quad, fig ):
        """Amplitude specra from 2d array."""

        fig.canvas.set_window_title('CSpad Quad Specra of 2x1')
        plt.clf() # clear plot
        #plt.title('Spectra',color='r',fontsize=20)
        fig.subplots_adjust(left=0.10, bottom=0.05, right=0.98, top=0.95, wspace=0.35, hspace=0.3)

        t_start = time.clock()
        
        for pair in xrange(8): # loop for pair = 0,1,2,...,7
            #print 20*'=',' Pair =', pair
            asic1x2  = arr1quad[pair,...]
            #print 'asic1x2.shape =', asic1x2.shape
            arrdimX,arrdimY = asic1x2.shape
            asic1d = asic1x2
            #print 'asic1d.shape =', asic1d.shape
            #asic1d.shape=(arrdimX*arrdimY,1)  
            asic1d.resize(arrdimX*arrdimY)            
            
            asics=hsplit(asic1d,2)

            for inpair in xrange(2) :
                asic = asics[inpair]
                #print 'asic.shape =', asic.shape
                plt.subplot(4,4,2*pair+inpair+1)
                #plt.xticks( arange(4), rotation=17 )
                #plt.yticks( arange(4) )
                #plt.hist(asic, bins=50, range=(0,1000))
                Amin  = cp.confpars.cspadSpectrumAmin
                Amax  = cp.confpars.cspadSpectrumAmax
                plt.hist(asic, bins=cp.confpars.cspadSpectrumNbins,range=(Amin,Amax))

                xmin, xmax = plt.xlim()
                plt.xticks( arange(int(xmin), int(xmax), int((xmax-xmin)/3)) )
                ymin, ymax = plt.ylim()
                plt.yticks( arange(int(ymin), int(ymax), int((ymax-ymin)/3)) )

                pantit='ASIC ' + str(2*pair+inpair)
                plt.title(pantit,color='r',fontsize=20)

                if pair==0 and inpair==1:
                    str_event = 'Event ' + str(cp.confpars.eventCurrent)
                    #ax = plt.gca()
                    plt.text(0.8,1.08,str_event,color='b',fontsize=24,transform = plt.gca().transAxes)

        print 'Time to generate all histograms (sec) = %f' % (time.clock() - t_start)




    def plotCSpadPairImage( self, arr1quad, fig ):
        """Plot 2d image from input array for a single pair"""

        print '(plotCSpadPairImage)'       

        self.fig = fig
        fig.canvas.set_window_title('CSpad image')
        plt.clf() # clear plot
        fig.subplots_adjust(left=0.10, bottom=0.05, right=0.95, top=0.95, wspace=0.1, hspace=0.1)        
        arrgap=zeros( (185,4) ) # make additional 2D-array of 0-s for the gap between two 1x1 pads
        
        self.pair=cp.confpars.cspadPair
        #print 'pair=', self.pair
        
        #For Image 
        asic1x2  = arr1quad[self.pair,...]
        asics    = hsplit(asic1x2,2)
        self.arr = hstack((asics[0],arrgap,asics[1]))

        #For spectrum
        arrdimX,arrdimY = asic1x2.shape
        self.asic1d = asic1x2
        self.asic1d.resize(arrdimX*arrdimY)            


        self.pantit =    'Event '   + str(cp.confpars.eventCurrent) 
        self.pantit += ( '   Quad ' + str(cp.confpars.cspadQuad) )
        self.pantit += ( '   Pair ' + str(cp.confpars.cspadPair) )          
        self.pantit += ( '   ASIC ' + str(2*self.pair) + ', ' + str(2*self.pair+1) )
        
        self.drawCSpadPairImage(cp.confpars.cspadImageAmin,cp.confpars.cspadImageAmax)



    def drawCSpadPairImage(self, Amin=None, Amax=None):
        """Plot 2d image from input array for a single pair"""

        plt.subplot(212)
        plt.hist(self.asic1d, bins=cp.confpars.cspadSpectrumNbins, range=(Amin, Amax))
        #plt.xticks( arange(int(Amin), int(Amax), int((Amax-Amin)/3)) )
        colmin, colmax = plt.xlim()
        coltickslocs, coltickslabels = plt.xticks()
        #print 'colticks =', coltickslocs, coltickslabels
        
        plt.subplot(211)
        self.axes = plt.imshow(self.arr, origin='down', interpolation='nearest') # Just a histogram, origin='upper'
        plt.title(self.pantit,color='r',fontsize=20) # pars like in class Text

        #plt.text(50, -20, pantit, fontsize=24)
        self.colb = plt.colorbar(self.axes, pad=0.10, orientation=2, fraction=0.10, shrink = 1, ticks=coltickslocs)

        plt.clim(colmin,colmax)
        #self.orglims = self.axes.get_clim()
           
        self.fig.canvas.mpl_connect('button_press_event', self.processMousButtonClick)

    def processMousButtonClick(self, event) :

       # can we open a dialogue box here?
       #print 'mouse click: button=', event.button,' x=',event.x, ' y=',event.y,
       #print ' xdata=',event.xdata,' ydata=', event.ydata
       if event.inaxes :
           lims = self.axes.get_clim()

           colmin = lims[0]
           colmax = lims[1]
           range = colmax - colmin
           value = colmin + event.xdata * range
           #print colmin, colmax, range, value

           # left button
           if event.button is 1 :
               if value > colmin and value < colmax :
                   colmin = value
                   print "new mininum: ", colmin
               else :
                   print "min has not been changed (click inside the color bar to change the range)"

           # middle button
           elif event.button is 2 :
               colmin, colmax = cp.confpars.cspadImageAmin, cp.confpars.cspadImageAmax
               print "reset"

           # right button
           elif event.button is 3 :
               if value > colmin and value < colmax :
                   colmax = value
                   print "new maximum: ", colmax
               else :
                   print "max has not been changed (click inside the color bar to change the range)"

           plt.clim(colmin,colmax)
           plt.clf()
           self.drawCSpadPairImage(colmin,colmax)
           plt.draw() # redraw the current figure



#
#  In case someone decides to run this module
#
if __name__ == "__main__" :
    # In principle we can try to run test suite for this module,
    # have to think about it later. Right now just abort.
    sys.exit ( "Module is not supposed to be run as main module" )
