#!/usr/bin/env python
#--------------------

import numpy as np
import matplotlib.pyplot as plt
import sys
import h5py

#--------------------
# Define graphical methods

def plot_image (arr, range=None, zrange=None) :    # range = (left, right, low, high), zrange=(zmin,zmax)
    fig = plt.figure(num=1, figsize=(12,12), dpi=80, facecolor='w',edgecolor='w',frameon=True)
    fig.subplots_adjust(left=0.10, bottom=0.08, right=0.98, top=0.92, wspace=0.2, hspace=0.1)
    figAxes = fig.add_subplot(111)
    imAxes = figAxes.imshow(arr, origin='upper', interpolation='nearest', aspect='auto',extent=range)
    #imAxes.set_clim(1300,2000)
    if zrange != None : imAxes.set_clim(zrange[0],zrange[1])
    colbar = fig.colorbar(imAxes, pad=0.03, fraction=0.04, shrink=1.0, aspect=40, orientation=1)

def plot_histogram(arr,range=(0,500),figsize=(5,5)) :
    fig = plt.figure(figsize=figsize, dpi=80, facecolor='w',edgecolor='w',frameon=True)
    plt.hist(arr.flatten(), bins=100, range=range)
    #fig.canvas.manager.window.move(500,10)
    
#--------------------
# Read and plot array

print ' sys.argv[0]: ', sys.argv[0]
print ' len(sys.argv): ', len(sys.argv)

if len(sys.argv) == 2 : fname = sys.argv[1]
else                  : fname = './image0_ev000115.txt'

print 'fname=', fname
arr = np.loadtxt(fname, dtype=np.float32)
print arr
print 'arr.shape=', arr.shape

#ampRange = (-20,100) # For subtracted pedestals
#ampRange = (1000,1500)
ampRange = (-100,500) # For subtracted pedestals

plot_image(arr, zrange=ampRange)
plt.get_current_fig_manager().window.move(10,10)

plot_histogram(arr,range=ampRange)
plt.get_current_fig_manager().window.move(950,10)

plt.show()

#--------------------
