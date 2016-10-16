import time
def frasco(k,n,x): 
    N = 2**n
    x = int(x,2)
    s = N**(1./k)
    i = 0
    bot  = k
    while i<N:
        if x-i<s:
            if bot == 1:
                j = i
                while j<=i+s:
                    if j>= x:
                        return
                    j+=1
            else:
                i = i-s
                if i<0:
                    i = 0
                s = s**1./k
                bot -= 1
        i += s
    return
def count_time(f,k,n,x):
    timer = 0
    count = 0
    while timer < 10.0:
        c = time.clock()
        f(k,n,x)
        timer += (time.clock()-c)
        count+=1
    return count
def run(s,k):
    f = open(s)
    nbits, n = [int(x) for x in next(f).split()]
    print(k,nbits)
    for line in f:
        print(count_time(frasco,k,n,line))
k =2    
run("data/bignum_32_01.dat",k) 
