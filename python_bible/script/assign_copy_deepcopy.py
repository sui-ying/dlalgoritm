import copy

a = [1, 2, 3, 4, ['a', 'b']]  # 原始对象

b = a  # 赋值，传对象的引用，同一个对象 
c = copy.copy(a)  # 对象拷贝，浅拷贝，
d = copy.deepcopy(a)  # 对象拷贝，深拷贝, 父对象和子对象完全独立

a.append(5)  # 修改对象a
a[4].append('c')  # 修改对象a中的['a', 'b']数组对象

print('a = ', a)
print('b = ', b)
print('c = ', c)
print('d = ', d)