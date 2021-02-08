import numpy as np

from viztracer import log_sparse


@log_sparse
def squarer():
    a5 = 1.0
    arr3 = np.zeros(10)
    
    for i in range(len(arr3)):        
        arr3[i] = a5
        a5 = a5**2
        
    return a5, arr3
