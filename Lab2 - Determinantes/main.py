def show(A):
    for i in A:
        print(i)
    print()

def findFirstNoNullRow(A,idx):
    for i in range(len(A)):
        if A[idx][i]:
            return i

def findFirstNoNullColumn(A,idx):
    for i in range(len(A[0])):
        if A[i][idx]:
            return i
    
def swapColumn(A,x,y):
    for i in range(len(A)):
        temp = A[i][x]
        A[i][x] = A[i][y]
        A[i][y] =  temp

def swapRow(A,x,y):
    temp = A[x]
    A[x] = A[y]
    A[y] = temp

def getMaxAbs(A,idx):
    t=A[0][idx]
    idx=0
    for i in range(len(A[0])):
        if t < A[i][idx]:
            t =  A[i][idx]
            idx = i
    return (t,i)
def escala(A):

    show(A)
    for i in range(len(A)):
        maxAbs = getMaxAbs(A,i)
        if maxAbs[0] == 0:
            continue
        else:
            swapRow(A,i,maxAbs[1])
            

        for k in range(i+1,len(A)):
            A[k] = [A[k][j] + A[i][j] * -(A[k][i]/A[i][i]) for j in range(len(A[0])) ]
        show(A)

def multiplicarDiagonal(A):
    res=1
    for i in range(len(A)):
        res*=A[i][i]
    return res


# A = [
#     [3,4,5,0,0],
#     [1,1,3,0,0],
#     [0,0,1,0,0],
#     [1,1,3,1,2],
#     [-1,-1,4,1,1]
# ]

# A = [
#     [0,0,1,10],
#     [0,10,1,1],
#     [1,3,4,4],
#     [2,1,1,1]
# ]

A = [
    [0,0,3,1],
    [0,0,3,1],
    [0,1,1,1],
    [0,2,3,1]
]

A = [
    [1,2,3,4],
    [2,4,6,8],
    [2,4,1,3],
    [1,2,1,1]
]
# A= [
#     [1,2,3],
#     [4,5,6],
#     [7,8,9]
# ]

print("mabs",getMaxAbs(A,1))
escala(A)
print("Determinante: ",multiplicarDiagonal(A))