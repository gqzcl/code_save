# coding=gbk
n=123
f=456.789
s1='hello,world'
s2='hello,\'Adam\''
s3=r'hello,"Bart"'
s4=r'''hello,
Lisa'''
print(n,f,s1,s2,s3,s4)
print(ord('h'),chr(104),'\u4e2d')
print(u'����')
print('..'.encode('utf-8'))
print(u'����'.encode('utf-8'))
print(u'����'.encode(encoding='utf-8',errors='strict'))
print(len('����'))
print(len('����'.encode('utf-8')))
name=input("please input a name")
a=input('please input a number')
print('hi,boys,%s want lend %d'%(name,int(a)))
print('hi,boys,%s want lend %d'%(name,1000))
print(name+a)
print('%s %%,%s %%'%(1.25,1.251))