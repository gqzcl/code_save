def triangles():
    n,L1,L2=0,[],[1]
    while n<=10:
        yield L2
        n+=1
        L2=[L1[i]+L1[i+1] for i in range(len(L1)-1) if len(L1)>=2]
        L2.append(1)
        L2.insert(0,1)
        L1=L2
s = 0
for t in triangles():
    print(t)
    s = s + 1
    if s == 10:
        break