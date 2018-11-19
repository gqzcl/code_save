#!/usr/bin/env python3
# -*- coding: utf-8 -*-
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
print('hello')
print('..'.encode('utf-8'))
print(u'中文'.encode('utf-8'))
print(u'中文'.encode(encoding='utf-8',errors='strict'))
print(len('中文'))
print(len('中文'.encode('utf-8')))
name=input("please input a name")
a=input()
print('hi,boys,%s want lend %d'%(name,int(a)))
print('hi,boys,%s want lend %d'%(name,1000))
