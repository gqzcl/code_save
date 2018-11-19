# coding=gbk
s=set([1,2,3])
print(s)
L=[1,2,3,'abc']
s=set(L)
print(s)
s.add('adbole')
print(s)
s.remove('adbole')
print(s)
b=set([1,2,3])
print(s&b,s|b)
a=[1,2,2,3,5,5,4,6,8,9,7,5]
b=[2,3]
c=set(a)
print(c)
print(hex(16),hex(1000),int(0x3e8),int(0x01010))#其他进制前应加0x