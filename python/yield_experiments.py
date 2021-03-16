import numpy as np


def generator_100():
    for i in np.linspace(1,100,100):
        yield i

       
def adder_5(our_ints):
    for i5 in our_ints:
        yield i5+5


def yield_caller():
    it_100 = generator_100()
    it_105 = adder_5(it_100)

    for y in it_105:
        print(y, end=" ")
