---
title: 'Java学习笔记Vector,LinkedList,泛型,静态导入,可变参数,asList()'
date: 2017-03-09 15:02:43
tags:
- Java基础
toc: true
---
Vector,LinkedList,泛型,静态导入,可变参数,asList()
<!--more-->
# Vector
		A:有特有功能
			a:添加
				public void addElement(E obj)--	add()
			b:获取
				public E elementAt(int index)--	get()
				public Enumeration<E> elements()-- iterator()

# LinkedList
		A:有特有功能	
			a:添加
				addFirst()
				addLast()
			b:删除
				removeFirst()
				removeLast()
			c:获取
				getFirst()
				getLast()
# 泛型的前世今生
		A:泛型的由来
			Object类型作为任意类型的时候，在向下转型的时候，会隐含一个转型问题
		B:泛型类
		C:泛型方法
		D:泛型接口
		E:泛型高级通配符
			?
			? extends E
			? super E	
# 增强for循环(掌握)
	(1)是for循环的一种
	(2)格式：
		for(元素的数据类型 变量名 : 数组或者Collection集合的对象) {
			使用该变量即可，该变量其实就是数组或者集合中的元素。
		}
	(3)好处：
		简化了数组和集合的遍历
	(4)弊端
		增强for循环的目标不能为null。建议在使用前，先判断是否为null。
# 静态导入(了解)
	(1)可以导入到方法级别的导入
	(2)格式：
		import static 包名....类名.方法名;
	(3)注意事项：
		A:方法必须是静态的
		B:如果多个类下有同名的方法，就不好区分了，还得加上前缀。
			所以一般我们并不使用静态导入，但是一定要能够看懂。
	
# 可变参数(掌握)
	(1)如果我们在写方法的时候，参数个数不明确，就应该定义可变参数。
	(2)格式：
		修饰符 返回值类型 方法名(数据类型... 变量) {}
		
		注意：
			A:该变量其实是一个数组名
			B:如果一个方法有多个参数，并且有可变参数，可变参数必须在最后	
