---
title: 'request,response学习笔记'
date: 2017-03-31 15:54:17
tags:
- Web
toc: true
---
request,response
<!--more-->
# response
## 状态码
		sendError(int sc)
		sendError(int sc, String msg)
		setStatus(int sc)
## 响应头
		setHeader(String name, String value)//单值的响应头
		addHeader(String name, String value)//多值的响应头
		setIntHeader(String name, int value)
		addIntHeader(String name, int value)
		setDateHeader(String name, long value)
		addDateHeader(String name, long value)
		<meta>标签可以代替响应头
		禁用浏览器缓存
			response.setHeader("Cache-Control", "no-cache");
			response.setHeader("pragma", "no-cache");
			response.setDateHeader("expires", -1);
## 响应体
		response的2个流
			ServletOutputStream out = response.getOutputStream();//字节
			PrintWriter writer = response.getWriter();//字符
			2个流不能同时使用
## 快速重定向
		response.sendRedirect(url);
# request
## 获取常用信息
		request.getRemoteAddr();//获取客户端IP
		request.getMethod();//获取请求方式
## 获取请求头
		String getHeader(String name)
		int getIntHeader(String name)
		long getDateHeader(String name)
		Enumeration<String> getHeaders(String name)
## 获取请求URL
		String getScheme();
		String getServerName();
		String getServerPort();
		String getContextPath();
		String getServletPath();
		String getQueryString();
		String getRequestURI();
		String getRequestURL();
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fe65bpqpaxj30hb0593zi.jpg)
## 获取请求参数
		String getParameter(String name);
		String[] getParameterValues(String name);
		Enumeration<String> getParameterNames();
		Map<String, String[]> getParameterMap();
## 请求转发和请求包含
		RequestDispatcher rd = request.getRequestDispatcher("/oneServlet");
		请求转发:rd.forward(request,response);//留头不留体
		请求包含:rd.include(request,response);//都留
		都是一个请求
## request域
		void setAttribute(String name, Object value)
		Object getAttribute(String name)
		用这2个方法来传值
# 编码问题
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fe65bqpxhvj30vp0digsl.jpg)