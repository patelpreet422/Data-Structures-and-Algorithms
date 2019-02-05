def gray(n):
    if(n == 1):
        return ['0', '1']
    gc = gray(n-1)
    zp = []
    op = []
    for i in range(len(gc)):
        zp.append('0'+gc[i])
        op.append('1'+gc[-(1+i)])
    return zp+op
