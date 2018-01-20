---
title: Java学习笔记之多线程1
date: 2017-03-15 13:38:40
tags:
- Java基础
toc: true
---

多线程
<!--more-->
# 多线程
## (1)多线程的实现方案(自己补齐步骤及代码	掌握)
		A:继承Thread类
		B:实现Runnable接口
## (2)线程的调度和优先级问题
		A:线程的调度
			a:分时调度
			b:抢占式调度 (Java采用的是该调度方式)
		B:获取和设置线程优先级
			a:默认是5
			b:范围是1-10
## (3)线程的控制(常见方法)
		A:休眠线程
		public static void sleep(long millis)
		B:加入线程
		public final void join()
		C:礼让线程
		public static void yield()
		D:后台线程
		public final void setDaemon(boolean on)
		E:终止线程(掌握)
		public final void stop()
		public void interrup()
## (4)同步解决线程安全问题
		A:同步代码块
			synchronized(对象) {
				需要被同步的代码;
			}
			
			这里的锁对象可以是任意对象。
			
		B:同步方法
			把同步加在方法上。
			
			这里的锁对象是this
			
		C:静态同步方法
			把同步加在方法上。
			
			这里的锁对象是当前类的字节码文件对象(反射再讲字节码文件对象)
## (5)回顾以前的线程安全的类
		A:StringBuffer
		B:Vector
		C:Hashtable
		D:如何把一个线程不安全的集合类变成一个线程安全的集合类
			用Collections工具类的方法即可。