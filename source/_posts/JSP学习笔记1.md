---
title: JSP学习笔记1
date: 2017-04-05 11:55:17
tags:
- Web
- JSP
toc: true
---

JSP

<!--more-->

# jsp的组成

	jsp = html + java脚本 + jsp标签(指令)

	jsp中有9大内置对象

	3中java脚本:

		<%...%>//java语句

		<%=...%>//java表达式，用来输出

		<%!...%>//声明，用来创建

# jsp原理

	jsp其实是一种特殊的Servlet

	当jsp页面第一次被访问的时候，服务器会把jsp编译成java文件(这个java其实是一个servlet类)

	然后再把java编译成.class

	然后创建该类对象

	最后调用它的service()方法

	第二次请求同一jsp时，直接调用service()方法。

	jsp注释:<%--...--%>