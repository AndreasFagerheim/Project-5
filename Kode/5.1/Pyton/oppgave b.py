import time
from numpy import *
import matplotlib.pyplot as plt


def gravity(r1,r2,m1,m2):
    return G*m1*m2/linalg.norm(r1-r2)**3 * (r1-r2)

m1 = 1.0
m2 = 1.0
G = 1.0

T = 15.0
n = 700
h = T/n

#setter opp arrays
t = linspace(0,T,n)

r1 = ndarray((3,n))
r2 = ndarray((3,n))
v1 = ndarray((3,n))
v2 = ndarray((3,n))

r1[:,0] = asarray([0,0,0])
r2[:,0] = asarray([5,0,0])

v1[:,0] = asarray([0,-0.1,0])
v2[:,0] = asarray([0,0.1,0])

dt = t[1] -t[0]
t0 = time.time()

F_p =
