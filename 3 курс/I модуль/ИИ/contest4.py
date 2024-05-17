
def lagrangePolinomial(X, Y, n, xx):
    for i in range(n+1):
        q = 1.0
        for j in range(n+1):
            if (j!=i): q = q*(xx-X[j])/X[i]-X[j]
        l = l+Y[i]*q
    return l


a = input()
X = []*len(a)
for i in range(len(a)+1):
    X[i] = a[i]
    print(X[i])
print(X)
