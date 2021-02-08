import numpy as np


def doubler():
    a3 = 5
    arr2 = np.zeros(10)
    
    for i in range(len(arr2)):        
        arr2[i] = a3
        a3 = a3*2
        
    return a3, arr2
