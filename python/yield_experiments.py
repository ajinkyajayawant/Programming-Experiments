import numpy as np


def generator_100():
    for i in np.linspace(1,100,100):
        yield i


def tuple_generator_100():
    for i in np.linspace(1,100,100):
        yield i, i+1


def adder_5(our_ints):
    for i5 in our_ints:
        yield i5+5


def tuple_adder_5():
    for i5, i12 in tuple_generator_100():
        yield i5+5, i12+12


def yield_caller():
    it_100 = generator_100()
    it_105 = adder_5(it_100)

    for y in it_105:
        print(y, end=" ")

def yield_tuple_caller():
    for y1, y2 in tuple_adder_5():
        print("({0}, {1})".format(y1, y2), end=" ")
