grade={'huang':0,'ge':10,'gu':100}
print(grade['huang'])
grade['gong']=80
grade['gong']=90
print(grade['gong'])
print(grade)
print('guo' in grade)
print(grade.get('guo'))
print(grade.get('guo',-1))
grade.pop('gong')
print(grade)
print(len(grade)-1)