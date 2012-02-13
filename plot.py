import numpy
from mayavi.mlab import *

a, b, energy = numpy.loadtxt('VMC.dat', usecols=[0,1,2], unpack=True)

x, y = numpy.meshgrid(a, b)
f   = numpy.zeros([10, 10]);

for i in range( 10 ):
   for j in range(10):
      f[i][j] = 10*energy[i+j]
print f     
s = surf( f)
#s = surf(x, y, f)

raw_input("Hei pa deg:");
