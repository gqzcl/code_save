# coding=gbk
classmates=('huang','ge','ni','gu','gong','guo')
print(classmates)
stuple=(1)# 这里表示的是数字，不是元组
print(stuple)
print(tuple,list)
s=(1,)#这里是正常的元组
print(s)
L=["haha",'hehe']
gg=('a','b',L)
print(gg)
gg[2][0]="gogo"
gg[2][1]=123
print(gg)
gg[2].insert(1,'shen')
gg[2].append('guo')
print(gg)