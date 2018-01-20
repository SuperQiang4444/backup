---
title: Java学习笔记List特有的功能

date: 2017-03-07 10:26:34
tags:
- Java基础
toc: true
---


List特有的方法和并发修改异常
<!--more-->
# List特有的方法
	void add(int index,Object element):在指定位置添加元素

	Object get(int index):获取指定位置的元素

	ListIterator listIterator():List集合特有的迭代器，可以逆向遍历，但是要先正向遍历，所以无意义，基本不使用。

	Object remove(int index):根据索引删除元素，返回被删除的元素

	Object set(int index,Object element):根据索引修改元素，返回被修改的元素


# 并发修改异常
		A:出现的现象
			迭代器遍历集合，集合修改集合元素
		B:原因
			迭代器是依赖于集合的，而集合的改变迭代器并不知道。
		C:解决方案
			a:迭代器遍历，迭代器修改(ListIterator)
				元素添加在刚才迭代的位置
			b:集合遍历，集合修改(size()和get())
				元素添加在集合的末尾
# List的子类特点
		ArrayList
			底层数据结构是数组，查询快，增删慢。
			线程不安全，效率高。
		Vector
			底层数据结构是数组，查询快，增删慢。
			线程安全，效率低。
		LinkedList
			底层数据结构是链表，查询慢，增删快。
			线程不安全，效率高。

