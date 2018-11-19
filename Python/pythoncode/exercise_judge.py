# coding=gbk
age=3
if age>20:
    print('your age is ',age)
    print('adult')
elif age>5:
    print('your age is ',age)
    print('teenager')
else:
    print('you age is ',age)
    print('kid')
height=1.75
weight=80.5
BMI=weight/(height*height)
if BMI>32:
    print('严重超胖')
elif BMI>28:
    print('肥胖')
elif BMI>25:
    print('过重')
elif BMI>18.5:
    print('正常')
else:
    print('过轻')
if age>0:
    print('1')
    print('2')
else:
    print(1)