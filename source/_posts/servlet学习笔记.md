---
title: servlet学习笔记
date: 2017-03-24 15:28:23

tags:
- Servlet
- Web

toc: true
---

Servlet
<!--more-->
# 实现Servlet的三种方式
![](http://wx3.sinaimg.cn/mw690/005P8ayVgy1fe15z3u24aj30ls0b3q7e.jpg)
# Servlet的概述
![](http://wx2.sinaimg.cn/mw690/005P8ayVgy1fe17yakmjqj30km08aaaw.jpg)
# 在web.xml中对Servlet进行配置
	<servlet>
  		<servlet-name>xxx</servlet-name>
  		<servlet-class>servlet1.AServlet</servlet-class>
  	</servlet>
  
  	<servlet-mapping>
  		<servlet-name>xxx</servlet-name>
  		<url-pattern>/AServlet</url-pattern>
  	</servlet-mapping>
# ServletConfig
![](http://wx4.sinaimg.cn/mw690/005P8ayVgy1fe18houaowj30o50dv40k.jpg)
# GenericServlet
	抽象类
	无参的init()方法
	private transient ServletConfig config;
# HttpServlet
	继承了GenericServlet
![](http://wx4.sinaimg.cn/mw690/005P8ayVgy1fe2be7mon2j30ip0a075s.jpg)
# Servlet细节
	不要在Servlet中创建成员!创建局部变量即可!
	可以创建无状态成员!
	可以创建有状态的成员,但状态必须为只读的!
	在服务器启动的时候就创建Servlet
		在web.xml的<servlet>
				<load-on-startup>0<load-on-startup>	
			</servlet>
		中写0代表优先级最高
	可以写多个URL在servletmapping中多写几个<url-pattern></url-pattern>即可
	<url-pattern>/servlet/*</url-pattern>前缀匹配
	<url-pattern>*.do</url-pattern>后缀匹配
	<url-pattern>/*</url-pattern>匹配所有url
# ServletContext
	一个项目只有一个ServletContext对象,负责给Servlet传递数据,和tomcat寿命一样
	ServletConfig中的getServletContext()
	GenericServlet中的getServletContext()可以得到ServletContext对象
![](http://wx4.sinaimg.cn/mw690/005P8ayVgy1fe2c5lyj0ej30ni0azacd.jpg)
![](http://wx1.sinaimg.cn/mw690/005P8ayVgy1fe2ccwsaihj30hz09m0u2.jpg)

	String realPath = servletContext.getRealPath("/a.txt")//得到真实路径
	InputStream in = servletContext.getResourceAsStream("/a.txt")//获取资源流
	Set set = context.getResourcePaths("/WEB-INF");//得到目录下所有资源路径
	获取类路径下的资源
		ClassLoader cl = this.getClass().getClassLoader();
		InputStream input = cl.getResourceAsStream("a.txt");