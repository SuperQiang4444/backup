---
title: Java学习笔记正则表达式
date: 2017-03-07 14:56:04
tags:
- Java基础
toc: true
---


正则表达式的功能
<!--more-->
判断功能
```
public boolean matches(String regex)
```
分割功能
```
public String[] split(String regex)
```
替换功能
```
public String replaceAll(String regex,String replacement)
```
获取功能
Pattern和Matcher类的使用
```
//模式和匹配器的典型调用顺序
Pattern p = Pattern.compile("a*b");
Matcher m = p.matcher("aaaab");
boolean b= m.matches();

//fing()用来扫描输入序列以查找与该模式匹配的下一个子序列，group()返回匹配的子序列
while(m.find()){
			System.out.println(m.group());
		}
```