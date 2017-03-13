from math import *
import numpy as np

def f(mu, sigma2, x):
       part1 = 1/(pow(2*pi*sigma2,0.5))
       part2 = np.exp(-0.5*(pow(x-mu,2)/sigma2))
       #part2 = 1
       #part1 = 3
       print(part1)
       print(part2)
       return part1*part2

def update(mean1, var1, mean2, var2):
       new_mean = (var2*mean1 + var1*mean2)/(var1 +var2)
       new_var = 1/(1/var1 +1/var2)
       return [new_mean, new_var]

def predict(mean1, var1, mean2, var2):
	new_mean = mean1 + mean2
	new_var = var1 + var2
	return [new_mean, new_var]

measurements = [5., 6., 7., 9., 10.]
motion = [1., 1., 2., 1., 1.]
measurement_sig = 4.
motion_sig = 2.
mu = 0.
sig = 10000.

#Please print out ONLY the final values of the mean
#and the variance in a list [mu, sig]. 

for i in range(len(measurements)):
    [mu_new, sig_new]=update(mu,sig,measurements[i],measurement_sig)
    [mu, sig]=predict(mu_new,sig_new,motion[i],motion_sig)
    #print [mu_new, sig_new]
print ([mu, sig])


print(f(10.,4.,10))

print(update(2.,4.,8.,4.))

print(predict(10.,4.,12.,4.))
