
import numpy
from mayavi.mlab import *
a, b, energy, energy_sq = loadtxt('VMC.dat', usecols=[0,1,2,3], unpack=True)

x, y = numpy.mgrid[a, b]
s = surf(x, y, energy)
#cs = contour_surf(x, y, f, contour_z=0)


test_surf();
raw_input("Hei");
