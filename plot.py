import numpy
from mayavi.mlab import *

a_start = 0.95;
b_start = 0.38;

a_steps = 50;
delta_a = 0.002;
    
b_steps = 50;
delta_b = 0.002;

a, b, energy = numpy.loadtxt('dist/Debug/GNU-Linux-x86/VMC_prf.dat', usecols=[0,1,2], unpack=True)
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

# Sur
s = surf(x, y, f, colormap='Spectral',warp_scale='auto' );
s_w = surf(x, y, f, representation='wireframe',  color=(.2, .2, .2), line_width=0.6, transparent=True, warp_scale='auto');

outline(s, color=(.7, .7, .7))
axes(s, color=(.7, .7, .7), xlabel=r'alpha', ylabel='Beta', zlabel='E', nb_labels=4);


colorbar(title='Energy', orientation='vertical', nb_labels=4)

#title('VMC');
show();
raw_input("Trykk en tast for a avslutte: ");

# To run:
# ipython --pylab plot.py 

