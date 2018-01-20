---
title: JDBC学习笔记2
date: 2017-04-12 18:00:09
tags:
- Web
toc: true
---
主要讲连接池
<!--more-->
# 数据库连接池
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fek4hjzmcdj30iz0algmn.jpg)
<hr>
# dbcp连接池
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fek4hl9161j30fi09mgnn.jpg)
	dbcp连接池用的是装饰者模式
### 对象增强的方法
	1.继承
	被增强的对象固定
	增强的内容固定
	2.装饰者模式
	被增强的对象可以切换
	增强的内容固定
	3.动态代理
	被增强的对象可以切换
	增强的内容也可以切换
<hr>
# c3p0连接池
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fek4hlyquej30fz08xmyr.jpg)
	c3p0连接池用的是动态代理
### c3p0配置文件的使用
	配置文件的要求:
		文件名称:必须叫c3p0-config.xml
		文件位置:必须在src下
	配置文件细节就不写了，查看day18.
<hr>
# Tomcat配置JNDI资源
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fek4hmgxffj30io01dt8p.jpg)
### 在tomcat的\conf\Catalina\localhost下面新建-->项目名.xml内容如下
![](http://wx3.sinaimg.cn/large/005P8ayVgy1fek4hmzgdxj30dw088gmo.jpg)
### 获取JNDI资源
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fek4hjea3rj30ju08o75l.jpg)
<hr>
# ThreadLocal
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fek5n3ismfj30dk02jaaa.jpg)
### 底层实现
![](http://wx3.sinaimg.cn/large/005P8ayVgy1fek5n3wc37j30ep0a4ab5.jpg)
	ThreadLocal通常用在一个类的成员上。
	多个线程访问它时，每个线程都有自己的副本，互不干扰。
	Spring中把Connection放到了ThreadLocal中!
