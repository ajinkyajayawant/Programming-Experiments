from scipy import linalg as scalg
import numpy as np
import numpy.linalg as npla
import math
import inspect
from sympy import Matrix


def problem1():
    def get_matrix(x1, x2, x3, x4):
        mat = np.array([[1, -x1, -x1**2, -x1**3],
                        [1, x2, -x2**2, x2**3],
                        [-1, -x3, x3**2, -x3**3],
                        [1, -x4, -x4**2, -x4**3]])
        return mat
    M = get_matrix(-2, 3, 4, -5)

    print("The determinant of {0} is {1}".format(M, npla.det(M)))

    return


def problem4():
    print("Solved analytically")
    return


def problem5():
    print("Solved analytically with the help of problem 10 since matrix and operation in both questions is the same.")
    return


def problem7():
    A = np.array([[0,1,0,0,0,0],
                  [0,0,0,0,0,0],
                  [0,0,0,1,0,0],
                  [0,0,0,0,0,0],
                  [0,0,0,0,0,1],
                  [0,0,0,0,0,0]])
    N = np.shape(A)[0]
    def get_b(c):
        b = np.array([6+c, 5+c, 4+c, 3+c, 2+c, 1+c])
        return b

    def full_row_rank(A, b):
        A2 = npla.matrix_power(A, 2)
        A3 = npla.matrix_power(A, 3)
        A4 = npla.matrix_power(A, 4)
        A5 = npla.matrix_power(A, 5)
        A6 = npla.matrix_power(A, 6)

        combined_A = np.concatenate((np.identity(N),
                                     A,
                                     A2,
                                     A3,
                                     A4,
                                     A5), axis=1)
        combined_b = np.kron(np.identity(N), np.reshape(b, (-1, 1)))
        combined_Ab = np.dot(combined_A, combined_b)

        if npla.matrix_rank(combined_Ab)<N:
            full_row_rank = False
        else:
            full_row_rank = True

        return full_row_rank

    def controllable_or_not(truth_value):
        if truth_value == True:
            status = "controllable"
        else:
            status = "not controllable"
        return status

    options = [1,6,-1,-6,0]
    controllable_options = [controllable_or_not(full_row_rank(A, get_b(c))) for c in options]

    print("The matrices A and b for c = {0} are {1}".format(options, controllable_options))

    return


def problem8():
    V = np.array([[0,1,0,0],[0,0,1,0],[0,0,0,1],[3,0,-2,0]])
    eigvals_V = npla.eigvals(V)

    print("The eigenvalues of {0} are {1}".format(V, eigvals_V))

    return


def problem9():
    options = [5,4,-4,2,6]
    def get_matrix(x):
        mat = np.array([[2,1,0],[1,8,-x],[0,x,3]])
        return mat

    def check_evals_pos(mat):
        return np.all(npla.eigvals(mat) > 0)

    pd_or_not = [check_evals_pos(get_matrix(x)) for x in options]

    print("The matrices for the options are {0}".format(pd_or_not))

    ## This doesn't work because

    return


def problem10():
    A = np.array([[6, 2, 2],[-2, 2, 0],[0, 0, 2]])
    linit = [np.array([2, 1, 1]), np.array([1, 2, 1]), np.array([1, 1, 3])]

    t_final = 2
    lfin = [np.dot(scalg.expm(A*t_final), arr) for arr in linit]

    box = np.stack(lfin)
    vol_box = abs(npla.det(box))

    t_final_2 = 0.1*math.log(2)
    lfin_2 = [np.dot(scalg.expm(A*t_final_2), arr) for arr in linit]

    box_2 = np.stack(lfin_2)
    vol_box_2 = abs(npla.det(box_2))

    print("The volume of the box is {0}".format(vol_box))
    print("The volume of the second box is {0}".format(vol_box_2))

    # The eigenvectors seem to be dependent so we have to compute the jordan form

    Amat = Matrix(A)
    P,J = Amat.jordan_form()
    P_arr = np.array(P).astype(np.float64)
    P_inv = npla.inv(P_arr)
    exponent = np.array([[math.exp(4), 0, 0],[0,math.exp(8),math.exp(8)*2],[0, 0, math.exp(8)]])
    prod_us = np.dot(P_inv, np.dot(exponent, P_arr))
    vol2_box = npla.det(prod_us)

    print("The volume of the box is {0}".format(vol2_box))

    return


def main():
    problem9()
    problem10()
    return
