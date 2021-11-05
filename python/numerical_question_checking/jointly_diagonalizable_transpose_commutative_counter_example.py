import numpy as np

S = np.array([[1,1],[2,-1]])
Sinv = np.inv(S)

La = np.array([[3,0],[0,2]])
A = np.dot(S, np.dot(La, Sinv))

Lb = np.array([[4,0],[0,1]])
B = np.dot(S, np.dot(Lb, Sinv))

print(np.dot(np.transpose(A), B))
# This returns
# array([[6.        , 4.33333333],
#       [6.        , 8.33333333]])

print(np.dot(np.transpose(B), A))
# This returns
# array([[6.        , 6.        ],
#       [4.33333333, 8.33333333]])

# So A^T B != B^T A despite satisfying all conditions of the question
