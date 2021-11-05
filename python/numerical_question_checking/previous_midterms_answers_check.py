import math
import numpy as np


def find_maximum_abs_eval(A):

    return np.amax(np.abs(np.linalg.eigvals(A)))


def problem8():
    print("Problem 8")
    S = np.array([[1,0],[0,2]])
    T = lambda b: np.array([[0, -b-1/2],[-b+1/2, 0]])
    SinvT = lambda b: np.dot(np.linalg.inv(S), T(b))

    options = [-3, -2, -1.5, 1.5, 1.15, 2.3]

    for option in options:
        print("Maximum absolute eigen value is {0}".format(find_maximum_abs_eval(SinvT(option))))

    return


def problem9():
    print("Problem 9")
    A = np.array([[1,math.sqrt(5),0],[0,1,0],[0,0,5]])

    print("Euclidean norm of A is {0}".format(np.linalg.norm(A, ord=2)))

    return


def problem13():
    print("Problem 13")
    As = [np.array([[1,2],[3,4]]),
          np.array([[2,1],[3,4]]),
          np.array([[1,2],[4,3]]),
          np.array([[1,2],[3,2]]),
          np.array([[4,2],[3,1]]),
          np.array([[-4,2],[3,-1]])]

    def get_SinvT(A):
        S = np.tril(A)
        T = -np.triu(A, 1)
        return np.dot(np.linalg.inv(S), T)

    for A in As:
        print("Maximum absolute eigenvalue is {0}".format(find_maximum_abs_eval(get_SinvT(A))))

    return

def main():
    problem8()
    problem9()
    problem13()

    return

# Output
# Problem 8
# Maximum absolute eigen value is 2.091650066335189
# Maximum absolute eigen value is 1.3693063937629153
# Maximum absolute eigen value is 1.0
# Maximum absolute eigen value is 1.0
# Maximum absolute eigen value is 0.7322909257938405
# Maximum absolute eigen value is 1.5874507866387544
# Problem 9
# Euclidean norm of A is 5.0
# Problem 13
# Maximum absolute eigenvalue is 1.5
# Maximum absolute eigenvalue is 0.375
# Maximum absolute eigenvalue is 2.6666666666666665
# Maximum absolute eigenvalue is 3.0
# Maximum absolute eigenvalue is 1.5
# Maximum absolute eigenvalue is 1.5
