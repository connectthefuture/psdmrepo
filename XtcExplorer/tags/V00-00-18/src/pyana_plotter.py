#--------------------------------------------------------------------------
# File and Version Information:
#  $Id: template!pyana-module!py 1095 2010-07-07 23:01:23Z salnikov $
#
# Description:
#  Pyana user analysis module pyana_plotter...
#
#------------------------------------------------------------------------

"""User analysis module for pyana framework.

This software was developed for the LCLS project.  If you use all or 
part of it, please give an appropriate acknowledgment.

@see RelatedModule

@version $Id: template!pyana-module!py 1095 2010-07-07 23:01:23Z salnikov $

@author Ingrid Ofte
"""

#------------------------------
#  Module's version from SVN --
#------------------------------
__version__ = "$Revision: 1095 $"
# $Source$

#--------------------------------
#  Imports of standard modules --
#--------------------------------
import sys
import logging
import time

#import matplotlib 
#matplotlib.use('Qt4Agg')

# alternative 1: pyplot (matlab-like)
import matplotlib.pyplot as plt

## alternative 2: object oriented matplotlib
#import matplotlib as mpl
#from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
#from matplotlib.backends.backend_qt4agg import NavigationToolbar2QTAgg as NavigationToolbar
#from matplotlib.figure import Figure


#-----------------------------
# Imports for other modules --
#-----------------------------

#----------------------------------
# Local non-exported definitions --
#----------------------------------

# local definitions usually start with _

#---------------------
#  Class definition --
#---------------------
#class ImagePlot(FigureCanvas) :
#    def __init__(self, parent=None,
#                 width=10, height=8, dpi=100, bgcolor=None, num=1 ):
#        fig = Figure(figsize=(width,height),dpi=dpi,facecolor=bgcolor, edgecolor=bgcolor)
#        FigureCanvas.__init__(self, fig)
#        self.setParent(parent)
#        fig.suptitle("ImagePlot Changed")
#        self.axes = fig.add_subplot(111)
#        #self.toolbar = NavigationToolbar(self,self)

#    def draw_array(self,array):
#        self.axesim = self.axes.imshow( array, origin='lower' )
#        # axes image 
#        self.show()


class pyana_plotter (object) :
    """Class whose instance will be used as a user analysis module. """

    #--------------------
    #  Class variables --
    #--------------------
    
    # usual convention is to prefix static variables with s_
    s_staticVariable = 0

    #----------------
    #  Constructor --
    #----------------
    def __init__ ( self,
                   display_mode = "Interactive" ) :
        """Class constructor. The parameters to the constructor are passed
        from pyana configuration file. If parameters do not have default 
        values  here then the must be defined in pyana.cfg. All parameters 
        are passed as strings, convert to correct type before use.

        @param display_mode        Interactive (1) or SlideShow (2) or NoDisplay (0)
        """
        self.nevents = 0

        self.display_mode = None
        if display_mode == "NoDisplay" : self.display_mode = 0
        if display_mode == "Interactive" : self.display_mode = 1
        if display_mode == "SlideShow" :   self.display_mode = 2

    #-------------------
    #  Public methods --
    #-------------------

    def beginjob( self, evt, env ) :
        """This method is called once at the beginning of the job. It should
        do a one-time initialization possible extracting values from event
        data (which is a Configure object) or environment.

        @param evt    event data object
        @param env    environment object
        """

        # Preferred way to log information is via logging package
        logging.info( "pyana_plotter.beginjob() called" )

        # let the framework know what display_mode (Interactive = 1, SlideShow = 0)
        # was selected. The other modules will pick this up in their event functions
        evt.put(self.display_mode, 'display_mode')

        if self.display_mode == 0 :
            plt.ioff()
        if self.display_mode == 1 :
            plt.ioff()
        if self.display_mode == 2 :
            plt.ion()

        plt.ion()

    def beginrun( self, evt, env ) :
        """This optional method is called if present at the beginning 
        of the new run.

        @param evt    event data object
        @param env    environment object
        """

        logging.info( "pyana_plotter.beginrun() called" )

    def begincalibcycle( self, evt, env ) :
        """This optional method is called if present at the beginning 
        of the new calibration cycle.

        @param evt    event data object
        @param env    environment object
        """

        logging.info( "pyana_plotter.begincalibcycle() called" )

    def event( self, evt, env ) :
        """This method is called for every L1Accept transition.

        @param evt    event data object
        @param env    environment object
        """
        self.nevents += 1

        # if any module changed the display mode, pick it up (we're last)
        event_display_mode = evt.get('display_mode')
        if event_display_mode is not None and event_display_mode != self.display_mode :
            self.display_mode = event_display_mode
            print "pyana_plotter display mode changed: ", self.display_mode,
            if self.display_mode == 0:
                plt.ioff()
                print " (NoDisplay)" 
            if self.display_mode == 1:
                plt.ioff()
                print " (Interactive)" 
            if self.display_mode == 2:
                plt.ion()
                print " (SlideShow)" 
            print
        if self.display_mode == 1:
            # Interactive
            plt.ioff()
            plt.show()

        elif self.display_mode == 2:
            pass
            # SlideShow
            # plt.draw()            

    def endcalibcycle( self, env ) :
        """This optional method is called if present at the end of the 
        calibration cycle.
        
        @param env    environment object
        """
        
        logging.info( "pyana_plotter.endcalibcycle() called" )

    def endrun( self, env ) :
        """This optional method is called if present at the end of the run.
        
        @param env    environment object
        """        
        logging.info( "pyana_plotter.endrun() called" )


    def endjob( self, env ) :
        """This method is called at the end of the job. It should do 
        final cleanup, e.g. close all open files.
        
        @param env    environment object
        """
        
        logging.info( "pyana_plotter.endjob() called" )

        if self.display_mode > 0 :
            plt.ioff()
            plt.show()

        print "-------------------"
        print "Done running pyana."
        print "To run pyana again, edit config file if needed and hit \"Run pyana\" button again"
        print "Send any feedback on this program to ofte@slac.stanford.edu"
        print "Thank you!"
        print "-------------------"

