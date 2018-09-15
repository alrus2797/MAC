import numpy as np

def escala(A):

    for i in range(len(A)):
        for k in range(i+1,len(A)):
            A[k] = [A[k][j] + A[i][j] * -(A[k][i]/A[i][i]) for j in range(len(A[0])) ]

def multiplicarDiagonal(A):
    res=1
    for i in range(len(A)):
        res*=A[i][i]
    return res

def getDet(M):
    A = M.copy()
    escala(A)
    return multiplicarDiagonal(A)

def multiplicar(M,N):
    A = np.array(M)
    B = np.array(N)
    return A@B


def show(M):
    for i in M:
        for j in i:
            print ("\t",j,end="")
        print()
    print()

def AddIdentityMatrix(M):
    I = [ [0]*len(M) for i in range(len(M)) ]
    for i in range(len(M)):
        I[i][i] = 1
    
    
    for row in range(len(M)):
        M[row] += I[row]

def RemoveIdentityMatrix(M):
    #show(M)
    for i in range(len(M)):
        M[i] = [ M[i][j] for j in range(len(M[i])//2,len(M[i])) ]


def swapRow(M,x,y):
    temp = M[x]
    M[x] = M[y]
    M[y] = temp


def getInv(M):
    AddIdentityMatrix(M)
    for i in range(len(M)):
        ext = [ j for j in range(len(M)) if j != i ]

        if M[i][i] == 0:
            for j in ext:
                if M[j][i] != 0:
                    swapRow(M,i,j)
                    break     
        if M[i][i] == 0:
            raise Exception("Impossible")
        M[i] = [ j/M[i][i] for j in M[i] ]

        for j in ext:
            M[j] = [ M[j][k] - M[j][i]/M[i][i] * M[i][k] for k in range(len(M[0]))   ] 
        show(M)
    RemoveIdentityMatrix(M)
    show(M)

def getCofact(M,i,j):
    A = []
    X = [ x for x in range(len(M[0])) if x != i ]
    Y = [ y for y in range(len(M)) if y != j ]

    for x in X:
        t = []
        for y in Y:
            t.append(M[x][y])
        A.append(t)
    
    det = getDet(A)
    cof = det * (-1)**(i+j)
    return cof

def getTrans(M):
    T = []
    for i in range(len(M)):
        t = []
        for j in range(len(M[0])):
            t.append(M[j][i])
        T.append(t)
    return T


def getAdjMatrix(M):
    C = []
    for i in range(len(M)):
        t = []
        for j in range(len(M[0])):
            t.append( getCofact(M,i,j) )
        C.append(t)

    return getTrans(C)

def escM(M,c):
    A = M.copy()
    for i in range(len(M)):
        for j in range(len(M[0])):
            A[i][j] *= c
    return A

def getInvByAdj(M):
    Adj = getAdjMatrix(M)
    return  escM(Adj, 1/(getDet(M)))

M=[
    [1,2,3,4],
    [3,2,1,5],
    [1,1,0,6],
    [0,1,1,1]
]

print("Operaciones Elementales: ")
A=getInvByAdj(M)
show(multiplicar(A,M))
input("Con Adjunta")

getInv(M)
