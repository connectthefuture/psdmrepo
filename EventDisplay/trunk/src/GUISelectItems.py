#--------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  Module GUISelectItems...
#
#------------------------------------------------------------------------

"""Shows the HDF5 file tree-structure and allows to select data items

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
from PyQt4 import QtGui, QtCore

#-----------------------------
# Imports for other modules --
#-----------------------------
import HDF5TreeViewModel as h5model
import ConfigParameters as cp
import PrintHDF5        as printh5

#---------------------
#  Class definition --
#---------------------
#class GUISelectItems ( QtGui.QWidget ) :
class GUISelectItems ( QtGui.QMainWindow ) :
    """Shows the HDF5 file tree-structure and allows to select data items.

    @see BaseClass
    @see OtherClass
    """

    #----------------
    #  Constructor --
    #----------------
    def __init__(self, parent=None):
        #super(GUISelectItems, self).__init__(parent)
        QtGui.QWidget.__init__(self, parent)

        """Constructor."""
        self.parentGUIMain = parent

        self.setGeometry(10, 10, 350, 1000)
        self.setWindowTitle('Items selection')

        #layout = QHBoxLayout()

        self.icon_folder_open   = QtGui.QIcon("EventDisplay/src/icons/folder_open.gif")
        self.icon_folder_closed = QtGui.QIcon("EventDisplay/src/icons/folder_closed.gif")
        self.icon_data          = QtGui.QIcon("EventDisplay/src/icons/table.gif")
        self.icon_apply         = QtGui.QIcon("EventDisplay/src/icons/button_ok.png")
        self.icon_reset         = QtGui.QIcon("EventDisplay/src/icons/undo.png")
        self.icon_retreve       = QtGui.QIcon("EventDisplay/src/icons/redo.png")
        self.icon_exit          = QtGui.QIcon("EventDisplay/src/icons/exit.png")
        self.icon_expand        = QtGui.QIcon("EventDisplay/src/icons/folder_open.gif")
        self.icon_collapse      = QtGui.QIcon("EventDisplay/src/icons/folder_closed.gif")
        self.icon_expcoll       = self.icon_expand
        self.icon_expcheck      = QtGui.QIcon("EventDisplay/src/icons/folder_open_checked.png")
        self.icon_print         = QtGui.QIcon("EventDisplay/src/icons/contents.png")

        actExit         = QtGui.QAction(self.icon_exit,     'Exit',           self)
        actApply        = QtGui.QAction(self.icon_apply,    'Apply',          self)
        actReset        = QtGui.QAction(self.icon_reset,    'Reset',          self)
        actRetreve      = QtGui.QAction(self.icon_retreve,  'Retreve',        self)
        actExpand       = QtGui.QAction(self.icon_expand,   'Expand',         self)
        actCollapse     = QtGui.QAction(self.icon_collapse, 'Collapse',       self)
        self.actExpColl = QtGui.QAction(self.icon_expcoll,  'Expand tree',    self)
        actExpCheck     = QtGui.QAction(self.icon_expcheck, 'Expand checked', self)
        actPrint        = QtGui.QAction(self.icon_print,    'Print tree',     self)

        self.connect(actExit,         QtCore.SIGNAL('triggered()'), self.processExit)
        self.connect(actApply,        QtCore.SIGNAL('triggered()'), self.processApply)
        self.connect(actReset,        QtCore.SIGNAL('triggered()'), self.processReset)
        self.connect(actRetreve,      QtCore.SIGNAL('triggered()'), self.processRetreve)
        self.connect(actExpand,       QtCore.SIGNAL('triggered()'), self.processExpand)
        self.connect(actCollapse,     QtCore.SIGNAL('triggered()'), self.processCollapse)
        self.connect(self.actExpColl, QtCore.SIGNAL('triggered()'), self.processExpColl)
        self.connect(actExpCheck,     QtCore.SIGNAL('triggered()'), self.processExpCheck)
        self.connect(actPrint,        QtCore.SIGNAL('triggered()'), self.processPrint)
        #self.connect(actExit,  QtCore.SIGNAL('triggered()'), QtCore.SLOT('close()'))

        menubar = self.menuBar()
        optAct  = menubar.addMenu('&Actions')
        optAct.addAction(actApply)
        optAct.addAction(actReset)
        optAct.addAction(actRetreve)
        optAct.addAction(actExit)

        optView = menubar.addMenu('&View')
        optView.addAction(actExpand)
        optView.addAction(actCollapse)
        optView.addAction(actExpCheck)
        optView.addAction(actPrint)

        toolbar = self.addToolBar('Exit')
        toolbar.setMovable(True)
        toolbar.addAction(actExit)
        #toolbar.insertSeparator(....)
        toolbar.addSeparator()
        toolbar.addAction(actApply)
        toolbar.addAction(actReset)
        toolbar.addAction(actRetreve)
        toolbar.addSeparator()
        #toolbar.addAction(actExpand)
        #toolbar.addAction(actCollapse)
        toolbar.addAction(self.actExpColl)
        toolbar.addAction(actExpCheck)
        toolbar.addAction(actPrint)

        self.model = h5model.HDF5TreeViewModel()

        #self.view = QtGui.QListView()
        #self.view = QtGui.QTableView()
        self.view = QtGui.QTreeView()
        self.view.setModel(self.model)
        #print 'Root is decorated ? ', self.view.rootIsDecorated() # Returns True
        #self.view.setDragDropMode(QtGui.QAbstractItemView.InternalMove)
        #self.view.setExpanded(cp.confpars.indExpandedItem,True)
        self.view.setAnimated(True)
        self.setCentralWidget(self.view)

        #self.show()
        
        #self.connect(self.view.selectionModel(), QtCore.SIGNAL('selectionChanged(QItemSelection, QItemSelection)'), self.itemSelected)
        self.connect(self.view.selectionModel(), QtCore.SIGNAL('currentChanged(QModelIndex, QModelIndex)'), self.cellSelected)
        #self.view.clicked.connect(self.someMethod1)       # This works
        #self.view.doubleClicked.connect(self.someMethod2) # This works
        self.model.itemChanged.connect(self.itemChanged)
        self.view.expanded.connect(self.itemExpanded)
        self.view.collapsed.connect(self.itemCollapsed)

        self.processRetreve() # Set all check box states for current configuration
        if cp.confpars.treeViewIsExpanded :
            #self.processExpand()  # Expand the tree 
            self.processExpCheck() # Expand the tree for checked data items 
                
    #-------------------
    # Private methods --
    #-------------------

    #-------------------
    #  Public methods --
    #-------------------

    def closeEvent(self, event): # if the 'x' (in the top-right corner of the window) is clicked
        print 'closeEvent'
        self.processExit()

    def processExit(self):
        print 'Exit button is clicked'
        self.parentGUIMain.processDisplay() # in order to close this window as from GUIMain
        #cp.confpars.wtdWindowIsOpen = False
        #self.close()
        #self.display.setText('Open')

    def processApply(self):
        print 'Apply button is clicked, use all checked items in the tree model for display'
        cp.confpars.list_of_checked_item_names = self.model.get_list_of_checked_item_names_for_model()

    def processReset(self):
        print 'Reset button is clicked, uncheck all items'
        self.model.reset_checked_items()

    def processRetreve(self):
        print 'Retreve button is clicked,\n', \
        'retreve the list of checked items from config. pars. and use them in the tree model.'
        self.model.retreve_checked_items(cp.confpars.list_of_checked_item_names)

    def processExpCheck(self):
        print 'ExpandChecked button is clicked, expand the tree for checked items only.'
        self.processCollapse() # first, collapse the tree
        self.model.expand_checked_items(self.view)
        cp.confpars.treeViewIsExpanded = True       # Change status for expand/collapse button
        self.actExpColl.setIcon(self.icon_collapse)
        self.actExpColl.setText('Collapse tree')

    def processExpand(self):
        print 'Expand button is clicked'
        self.model.set_all_group_icons(self.icon_expand)
        self.view.expandAll()
        cp.confpars.treeViewIsExpanded = True

    def processCollapse(self):
        print 'Collapse button is clicked'
        self.model.set_all_group_icons(self.icon_collapse)
        self.view.collapseAll()
        cp.confpars.treeViewIsExpanded = False

    def processExpColl(self): # Flip/flop between Expand and Collaple the HDF5 tree
        print 'Expand/Collapse button is clicked :',
        if cp.confpars.treeViewIsExpanded == True :
            self.actExpColl.setIcon(self.icon_expand)
            self.actExpColl.setText('Expand tree')
            self.processCollapse()
        else :
            self.actExpColl.setIcon(self.icon_collapse)
            self.actExpColl.setText('Collapse tree')
            self.processExpand()
 
    def processPrint(self):
        print 'Print button is clicked'
        fname = cp.confpars.dirName+'/'+cp.confpars.fileName
        print 'Print structure of the HDF5 file:\n %s' % (fname)
        printh5.print_hdf5_file_structure(fname)

    def someMethod1(self):
        print '1-clicked!'

    def someMethod2(self):
        print '2-clicked!'

    def itemExpanded(self, ind): 
        item = self.model.itemFromIndex(ind)
        item.setIcon(self.icon_folder_open)
        print 'Item expanded : ', item.text()  

    def itemCollapsed(self, ind):
        item = self.model.itemFromIndex(ind)
        item.setIcon(self.icon_folder_closed)
        print 'Item collapsed : ', item.text()  

    def itemSelected(self, selected, deselected):
        print len(selected),   "items selected"
        print len(deselected), "items deselected"

    def cellSelected(self, ind_sel, ind_desel):
        #print "ind   selected row, col = ", ind_sel.row(),  ind_sel.column()
        #print "ind deselected row, col = ", ind_desel.row(),ind_desel.column() 
        #item       = self.model.itemFromIndex(ind_sel)
        #dsfullname = str(self.model.getFullNameFromItem(item))
        dsfullname = str(self.model.getFullNameFromIndex(ind_sel))
        print "Item with name '%s' is selected" % ( dsfullname )
        #print ' isEnabled=',item.isEnabled() 
        #print ' isCheckable=',item.isCheckable() 
        #print ' checkState=',item.checkState()
        #print ' isSelectable=',item.isSelectable() 
        #print ' isTristate=',item.isTristate() 
        #print ' isEditable=',item.isEditable() 
        #print ' isExpanded=',self.view.isExpanded(ind_sel)
        printh5.print_dataset_metadata_from_file(dsfullname)

    def itemChanged(self, item):
        state = ['UNCHECKED', 'TRISTATE', 'CHECKED'][item.checkState()]
        print "Item with full name %s, is at state %s\n" % (self.model.getFullNameFromItem(item), state)

#------------------
#  Main for test --
#------------------

def main():
    app = QtGui.QApplication(sys.argv)
    ex  = GUISelectItems()
    ex.show()
    app.exec_()

if __name__ == "__main__" :
    main()
    sys.exit ( "Module is not supposed to be run as main module" )

#------------------
