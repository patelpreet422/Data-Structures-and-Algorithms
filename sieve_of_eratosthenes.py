def sieve(n):
    l = [x for x in range(n+1)]
    d = []
    k = 2
    while(k*k<=n):
        d.append(k)
        k += 1
    for x in d:
        for i in range(2, int(n/x)+1):
            l[i*x] = 0;
    primes = []
    for i in range(2, len(l)):
        if(l[i] != 0):
            primes.append(l[i])
    return primes
