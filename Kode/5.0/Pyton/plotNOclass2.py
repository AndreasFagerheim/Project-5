# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 13:19:46 2019

@author: Andreas
"""

import itertools
import numpy as np
import matplotlib.pyplot as plt
from textwrap import wrap

def Read_three_Column_File(file_name):
    with open(file_name, 'r') as data:
            t = []
            posX = []
            posY = []
            for line in itertools.islice(data, 1, None):
                p = line.split()
                t.append(float(p[0]))
                posX.append(float(p[1]))
                posY.append(float(p[2]))
    return t,posX,posY

plt.figure()
t,x,y = Read_three_Column_File('C:/Users/Andreas/Documents/Project 5/Project-5/Data/NoClass/EulerForward.txt')
t,x2,y2 = Read_three_Column_File('C:/Users/Andreas/Documents/Project 5/Project-5/Data/NoClass/verlet.txt')
plt.plot(x,y)
plt.plot(x2,y2)
#plt.xlim(-2,-1.6)
plt.title("\n".join(wrap('Orbit of Earth around the sun at rest', 60)))
plt.ylabel('Y ')
plt.xlabel('X')

plt.savefig('C:/Users/Andreas/Documents/Project 5/Project-5/Data/NoClass/plotXYpos.png')
plt.show()
plt.figure()