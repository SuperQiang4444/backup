﻿---
title: Java学习笔记Map
date: 2017-03-10 15:23:49
tags:
- Java基础
toc: true

---


Map和Collections
<!--more-->
# Map(掌握)
	(1)将键映射到值的对象。一个映射不能包含重复的键；每个键最多只能映射到一个值。 
	(2)Map和Collection的区别?
		A:Map 存储的是键值对形式的元素，键唯一，值可以重复。
		B:Collection 存储的是单独出现的元素，子接口Set元素唯一，子接口List元素可重复。
	(3)Map接口功能概述(自己补齐)
		A:添加功能
		V put(K key,V value)
		B:删除功能
		void clear:移除所有键值对元素
		V remove(Object key):根据键删除键值y
		C:判断功能
		boolean containsKey(Object key):判断集合是否包含指定的键
		boolean containsValue(Object value)
		boolean isEmpty():判空
		D:获取功能
		Set<Map.Entry<K,V>> entrySet():返回键值对对象的集合
		V get(Object key):根据键获取值
		Set<K> keySet():获取集合中所有键的集合
		Collection<V> values():获取集合中所有值的集合
		E:长度功能
		int size()
	(4)Map集合的遍历
		A:键找值
			a:获取所有键的集合
			b:遍历键的集合,得到每一个键
			c:根据键到集合中去找值
		
		B:键值对对象找键和值
			a:获取所有的键值对对象的集合
			b:遍历键值对对象的集合，获取每一个键值对对象
			c:根据键值对对象去获取键和值
			
		代码体现：
			Map<String,String> hm = new HashMap<String,String>();
			
			hm.put("it002","hello");
			hm.put("it003","world");
			hm.put("it001","java");
			
			//方式1 键找值
			Set<String> set = hm.keySet();
			for(String key : set) {
				String value = hm.get(key);
				System.out.println(key+"---"+value);
			}
			
			//方式2 键值对对象找键和值
			Set<Map.Entry<String,String>> set2 = hm.entrySet();
			for(Map.Entry<String,String> me : set2) {
				String key = me.getKey();
				String value = me.getValue();
				System.out.println(key+"---"+value);
			}
	(5)HashMap集合的练习
		A:HashMap<String,String>
		B:HashMap<Integer,String>
		C:HashMap<String,Student>
		D:HashMap<Student,String>
	(6)TreeMap集合的练习		
		A:TreeMap<String,String>
		B:TreeMap<Student,String>
			
# Collections(理解)	
	(1)是针对集合进行操作的工具类
	(2)面试题：Collection和Collections的区别
		A:Collection 是单列集合的顶层接口，有两个子接口List和Set
		B:Collections 是针对集合进行操作的工具类，可以对集合进行排序和查找等
	(3)常见的几个小方法：
		A:public static <T> void sort(List<T> list)
		B:public static <T> int binarySearch(List<?> list,T key)
		C:public static <T> T max(Collection<?> coll)
		D:public static void reverse(List<?> list)
		E:public static void shuffle(List<?> list)
