a='123456'
for n in a:
    print(n)
d={'a':1,'b':2,'c':3}
for k,v in d.items():
    print(k,v)
for v in d.values():
    print(v)
print([x*x for x in range(1,11)])
print([x*x for x in range(1,11) if x%2==0])
print([x+y for x in 'ABC' for y in 'DEF'])
print([m+'='+str(n) for m,n in d.items()])
s=['HELLO','Boys']
print([a.lower() for a in s])
L1 = ['Hello', 'World', 18, 'Apple', None]
print([a.lower() for a in L1 if isinstance(a,str)])
g=(x*x for x in range(11))
print([n for n in g])
def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        print(b)
        a, b = b, a + b
        n = n + 1
    return 'done'
fib(6)
def fib1(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'
print(next(fib1(6)))
print([x for x in fib1(6)])
g=fib1(6)
while True:
    try:
        x = next(g)
        print('g:', x)
    except StopIteration as e:
        print('Generator return value:', e.value)
        break

    
