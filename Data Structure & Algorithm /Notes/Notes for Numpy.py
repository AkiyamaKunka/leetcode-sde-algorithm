import numpy as np
import pandas as pd

# 这个as方便我们简写这个包的名字
myArray = np.array([[1, 2, 3],
                    [2, 3, 4]])  # 这个方法是创建了numpy自己支持的类型

print(myArray)
print('shape:', myArray.shape)
print('Size:', myArray.size)
print('Dimension:', myArray.ndim)  # 分别可以显示这个矩阵的形状，大小，维度

a = np.array([2, 23, 4], dtype=np.int32)  # 这里可以定义这个矩阵的大小，dtype = define type 就是规定里边元素的类型
# 当然这个时候一定要记得加入括号


print(a.dtype)  # 打印自己矩阵元素的类型

b = np.ones((4, 4))  # 这个方法非常奇特，是用ones把全部的元素都设定为一个值 类似的还有zeros
print(b)

c = np.arange(12).reshape(4, 3)  # 这个方法就是arange ，从0到11的全部元素 然后被重新reshape成了你自定义的各种大小的矩阵
print(c)

d = np.linspace(1, 10, 9).reshape(3, 3)  # 这个是把 1 - 10 的区间分割成9个数字
print(d)

f = np.dot(c, d) # 这个是矩阵乘法的两种方式 一定要用dot .dot(a,b) 或者换 a.dot(b) 都是可以的
f = c.dot(d)
print(f)

e = np.random.random((2, 4)) # 生成随机矩阵
print(e)
print("here are the sums")
print(np.sum(e, axis=0)) # axis = 0 是对一维元素求和， 1 顺着二维方向求和

print(e.mean()) # 求平均值
print(np.average(e)) # 求平均值
print(np.median(e)) # 中位数
print(np.var(e)) #方差

another = np.arange(3, 15).reshape(2, 6)  # 这个是一个很神奇的访问方式
print(another)
print(another[1][1])  # 这一行和下一行的效果是一样的
print(another[1, 1])

print(another[0:2, 1]) # 这个意思是打印 index = 1 的column 从第0个元素到第1个元素

for row in another:
    print(row)
for column in another.T: # 这里是把矩阵转制， 这样就可以输出column们了
    print(column)
print(another.flatten()) # 这里是把矩阵变成1 * n的矩阵 便于for循环打印
for item in another.flat:
    print(item)
