---
title: JAVA学习笔记Collection基本功能
date: 2017-03-06 17:57:48
tags:
- Java基础
toc: true
---


Collection的一些方法和集合的继承体系结构
<!--more-->
# Collection的一些方法
	boolean add(Object obj):添加一个元素
	boolean addAll(Collection c):添加一个集合的元素
	void clear():移除所有元素
	boolean remove(Object o):移除一个元素
	boolean removeAll(Collection c):移除一个集合的元素(一个被移除就true)
	boolean contains(Object o):判断集合中是否包含指定的元素
	boolean containsAll(Collection c):判断集合中是否包含指定的集合元素(包含所有才true)
	boolean isEmpty():判断集合是否为空
	int size():元素的个数
	boolean retainAll(Collection c):两个集合的交际，调用方法的容器内容改变就true
	object[] toArray():把集合转换成数组
#### Iterator<E> iterator() 迭代器遍历容器
```
	Iterator it = c.iterator();
	while(it.hasNext()) {
	String s =(String) it.next();
	System.out.println(s);
	}
```
# 集合的继承体系结构
		由于需求不同，Java就提供了不同的集合类。这多个集合类的数据结构不同，但是它们都是要提供存储和遍历功能的，
		我们把它们的共性不断的向上提取，最终就形成了集合的继承体系结构图。
		
		Collection
			|--List
				|--ArrayList
				|--Vector
				|--LinkedList
			|--Set
				|--HashSet
				|--TreeSet
