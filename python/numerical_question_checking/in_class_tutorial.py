def jacobi_converge(A):
    S = np.diag(np.diag(A))
    T = S - A
    SinvT = np.dot(np.inv(S), T)
    evals = linalg.eigval(SinvT)
    yes_or_no = np.amax(np.abs(evals)) < 1
    return yes_or_no
