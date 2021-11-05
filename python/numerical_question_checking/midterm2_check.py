from scipy import linalg as scalg
import numpy as np
import math
import inspect


def problem1():
    print("{0}".format(inspect.stack()[0][3]))
    print(" It is not clear what contain all the terms means. For example the series expansion of e^t contains the t t^2 terms.")
    print("--------------------")
    return


def problem2():
    print("{0}".format(inspect.stack()[0][3]))
    A = np.array([[1, math.sqrt(8), 0],[2, 2*math.sqrt(8), 0],[0, 0, 1]])

    print("Singular values of middle matrix {0} are {1}".format(A, scalg.svdvals(A)))
    print("--------------------")

    return


def problem3():
    """ """
    print("{0}".format(inspect.stack()[0][3]))
    A = np.array([[1, math.sqrt(8)],[math.sqrt(5), 2*math.sqrt(10)]])

    Apow4 = np.linalg.matrix_power(A,4)

    alpha_1 = Apow4[0, 1]/A[0, 1]
    alpha_2 = Apow4[0, 0] - alpha_1*A[0, 0]

    print("A^4 = {0}".format(Apow4))
    print("For A={0} alpha1 is {1} and alpha2 is {2}".format(A, alpha_1, alpha_2))
    print("--------------------")

    return np.linalg.norm(A)


def problem6():
    print("{0}".format(inspect.stack()[0][3]))
    A = np.array([[2, 2, 3],[2, 1, 4],[3, 4, 5]])
    B = np.array([[5, 3, 3],[3, 3, 1],[3, 1, 1]])
    C = np.array([[2, 2, 3],[2, 3, 4],[3, 4, 4]])

    evals_A = scalg.eigvals(A)
    evals_B = scalg.eigvals(B)
    evals_C = scalg.eigvals(C)

    def pd_or_not(evals):
        if np.all(evals > 0):
            pd = True
        else:
            pd = False

        return pd

    print("A = {0} has evals {1} p.d is {2}, B = {3} has evals {4} is {5}, C = {6} has evals {7} is {8}.".format(A, evals_A, pd_or_not(evals_A), B, evals_B, pd_or_not(evals_B), C, evals_C, pd_or_not(evals_C)))
    print("--------------------")

    return scalg.pinv(A)


def problem8():
    print("{0}".format(inspect.stack()[0][3]))
    S = np.array([[-3, 3, 0],[0, -2, 0],[0, 0, 0]])
    U = np.array([[1/math.sqrt(3), 2/math.sqrt(8), 1/math.sqrt(6)],
                  [-1/math.sqrt(3), 0, 2/math.sqrt(6)],
                  [1/math.sqrt(3), -2/math.sqrt(8), 1/math.sqrt(6)]])

    UtU = np.dot(np.transpose(U), U)
    if np.all(UtU == np.identity(np.shape(U)[0])):
        orthonorm = "orthonormal"
    else:
        orthonorm = "not orthonormal"

    print("U is {0} and UtU = {1}".format(U, UtU))

    print("U is {0}".format(orthonorm))

    print("The eigenvalues and eigenvectors of S are {0}".format(scalg.eigvals(S)))

    # print("The solution x(t)={0}".format())
    print("--------------------")

    return


def problem9():
    print("{0}".format(inspect.stack()[0][3]))
    print("x should be there in the numerator norm.")
    print("Why is the norm defined with respect to a size 2 vector instead of with respect to a size 3 vector?")
    A = np.array([[1, math.sqrt(3), 0],[0, 1, 0],[0, 0, math.sqrt(5)]])

    print("The norm of = {0} A is {1}".format(A, np.linalg.norm(A, ord=2)))
    print("--------------------")

    return


def problem10():
    print("{0}".format(inspect.stack()[0][3]))
    print(" Need to specify that it is a Moore Penrose pseudo inverse.")
    A = np.array([[2, 0, 1, 1],[4, 0, 2, 2]])/math.sqrt(6)
    Apinv = scalg.pinv(A)

    AApinvA = np.dot(A, np.dot(Apinv, A))

    print(" The pseudo inverse of A = {0} is {1}.".format(A, Apinv))
    print("AApinvA = {0} and should be equal to A.".format(AApinvA))
    print("--------------------")
    return


def main():
    problem1()
    problem2()
    problem3()
    problem6()
    problem8()
    problem9()
    problem10()
    return
