## README

该章节主要介绍Python面试考点


### 1. [Python中的赋值、深拷贝与浅拷贝（内存地址)](script/assign_copy_deepcopy.py)
[ref1](https://blog.csdn.net/yanjiangdi/article/details/103228984)

#### 在Python中，对象可以分为可变对象（mutable）和不可变对象（immutable）两种类型

可变对象（Mutable objects）： 可变对象是指创建后可以修改其值或状态的对象。
当对可变对象进行修改时，它的内部状态可以改变，而对象的身份标识(id)保持不变即指向的地址不变。
常见的可变对象包括列表（list）、字典（dictionary）、集合（set）等

不可变对象（Immutable objects）： 不可变对象是指创建后不能修改其值或状态的对象。
当尝试修改不可变对象时，实际上是创建了一个新对象，而原始对象的身份标识保持不变。
常见的不可变对象包括整数（int）、浮点数（float）、字符串（string）、元组（tuple）等