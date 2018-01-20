---
title: 'Java学习笔记String'
date: 2017-03-08 11:37:36
tags:
- Java基础
toc: true
---


Scanner和String的构造方法和功能
<!--more-->
## Scanner的使用(了解)
	(1)在JDK5以后出现的用于键盘录入数据的类。
	(2)构造方法：
		A:讲解了System.in这个东西。
			它其实是标准的输入流,对应于键盘录入
		B:构造方法
			InputStream is = System.in;
			Scanner(InputStream is)
		C:常用的格式
			Scanner sc = new Scanner(System.in);
	(3)基本方法格式：
		A:hasNextXxx() 判断是否是某种类型的
		B:nextXxx()	返回某种类型的元素
	(4)要掌握的两个方法
		A:public int nextInt()
		B:public String nextLine()
	(5)需要注意的小问题
		A:同一个Scanner对象，先获取数值，再获取字符串会出现一个小问题。
		B:解决方案：
			a:重新定义一个Scanner对象
			b:把所有的数据都用字符串获取，然后再进行相应的转换
## 构造方法：
```
		A:public String()
		B:public String(byte[] bytes)
		C:public String(byte[] bytes,int offset,int length)
		D:public String(char[] value)
		E:public String(char[] value,int offset,int count)
		F:public String(String original)
```
## A:判断功能
			boolean equals(Object obj)
			boolean equalsIgnoreCase(String str)
			boolean contains(String str)
			boolean startsWith(String str)
			boolean endsWith(String str)
			boolean isEmpty()
## B:获取功能
			int length()
			char charAt(int index)
			int indexOf(int ch)
			int indexOf(String str)
			int indexOf(int ch,int fromIndex)
			int indexOf(String str,int fromIndex)
			String substring(int start)
			String substring(int start,int end)
## C:转换功能
			byte[] getBytes()
			char[] toCharArray()
			static String valueOf(char[] chs)
			static String valueOf(int i)
			String toLowerCase()
			String toUpperCase()
			String concat(String str)
## D:其他功能
			a:替换功能 
				String replace(char old,char new)
				String replace(String old,String new)
			b:去空格功能
				String trim()
			c:按字典比较功能
				int compareTo(String str)
				int compareToIgnoreCase(String str) 
