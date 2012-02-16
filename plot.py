import numpy
from mayavi.mlab import *
a_steps = 50;
a_start = 0.75;
delta_a = 0.01;

b_steps = 50;
b_start = 0.1;
delta_b = 0.01;

a, b, energy = numpy.loadtxt('VMC.dat', usecols=[0,1,2], unpack=True)
c = zeros(a_steps)
d = zeros(b_steps)

for i in range(a_steps):
   c[i] = a[i*a_steps]
   d[i] = b[i]

print min(energy)

x, y = numpy.mgrid[a_start:a_start + a_steps*delta_a:delta_a, b_start:b_start + b_steps*delta_b:delta_b]

f   = numpy.zeros([a_steps, b_steps]);

for i in range( a_steps ):
   for j in range( b_steps ):
      f[i][j] = energy[i*a_steps+j]

figure(1, size=(600, 400), fgcolor=(1, 1, 1), bgcolor=(0.5, 0.5, 0.5))

s = surf(x, y,f, colormap='Spectral');
outline(s, color=(.7, .7, .7))
axes(s, color=(.7, .7, .7), xlabel=r'$\alpha$', ylabel='Beta', zlabel='E');


title('VMC');

raw_input("Hei pa deg:");

# To run:
# ipython --pylab plot.py 

