import numpy as np

from viztracer_exp_2 import doubler
from viztracer_exp_3 import squarer

def main():
    b1 = 10.0
    m1, m2 = incrementer()
    m3, m4 = doubler()
    m5, m6 = squarer()
    return


def incrementer():
    a1 = 5
    arr1 = np.zeros(10)
    
    for i in range(len(arr1)):        
        arr1[i] = a1
        a1 = a1 + 1
        
    return a1, arr1

if __name__== "__main__":
    main()
