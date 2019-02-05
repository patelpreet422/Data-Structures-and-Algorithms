def permute(s):
    if(len(s) == 1):
        return [s]
    ps = []
    for i in range(len(s)):
        pp = permute(s[:i]+s[i+1:])
        for p in pp:
            ps.append(s[i]+p)
    return ps
