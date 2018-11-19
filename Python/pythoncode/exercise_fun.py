import math
def my_abs(a):
    if not isinstance(a,(int,float)):
        raise TypeError('bad operand type')  
    if a>0:
        print(a)
    else:
        print(-a)
my_abs(60.6)

def move(x,y,step,angle=0):
    nx=x+step*math.cos(angle)
    ny=y-step*math.sin(angle)
    return nx,ny
print(move(1,2,5,0))
x,y=move(100,100,60,math.pi/6)
print(x,y)

def quadratic(a,b,c):
    if (b*b-4*a*c)>=0:
        d=math.sqrt(b*b-4*a*c)
    else:
        return 'no answer'
    x1=(-b+d)/(2*a)
    x2=(-b-d)/(2*a)
    return x1,x2
print(quadratic(2,3,1),quadratic(1,3,14))

def add_end(L=[]):
    if L is []:
        L=[]
    L.append('end')
    return L
print(add_end(),add_end())#
print(add_end())
def add_end1(L=None):
    if L is None:
        L=[]
    L.append('end')
    return L
print(add_end1(),add_end1())
print(add_end1())
def count(*number):
    sum=0
    for a in number:
        sum+=a
    print(sum)
count(1,2,3,4)
S=[1,2,3,4,5,6]
count(*S)
def person(name,age,**others):
    print('name:',name,'age:',age,'others:',others)
person('tom',45,job='taxier')
def move(n,a,b,c):
    if n==1:
        print(a,'-->',c)
    else:
       move(n-1,a,c,b)
       move(1,a,b,c)
       move(n-1,b,a,c)
move(2,'A','B','C')

        