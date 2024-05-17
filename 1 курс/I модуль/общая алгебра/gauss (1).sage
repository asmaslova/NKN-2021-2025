# Gauss, ver. 1.5
def triangulation(S):
    T=[]
    n=0
    while S!=[]:
        m=max([s.lm() for s in S])
        L = [s for s in S if s.lm() == m]
        S = [s for s in S if s.lm() < m]
        g1=L[0]
        T.append(g1)
        for g in L[1:]:
            g=g1.lc()*g-g.lc()*g1
            if g.degree()==0:
                T.append(g)
                break  
            elif g.degree()==1:
                S.append(g)
    return T
    
def tsolve(T):
    f=T[-1]
    X=f.parent().gens()
    n=len(X)
    C=f.coefficients()
    if len(C)==2:
        [a,b]=C
    else:
        [a]=C
        b=0    
    S=[-b/a]  
    for i in range(n-1): 
        T=[t.subs({X[n-1-i]:-b/a}) for t in T]
        T=[t for t in T if t!=0]
        C=T[-1].coefficients()
        if len(C)==2:
            [a,b]=C
        else:
            [a]=C
            b=0
        S.append(-b/a)
    S.reverse()
    return S
