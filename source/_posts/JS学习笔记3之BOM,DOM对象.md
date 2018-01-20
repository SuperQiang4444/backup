---
title: JS学习笔记3之BOM，DOM对象
date: 2017-03-20 13:50:33
tags:
- JS
- Web
toc: true
---


BOM,DOM
<!--more-->
# JS的BOM对象
	navigator: 获取客户机的信息(浏览器的信息)
		document.write(navigator.appName);
	screen: 获取屏幕信息
		document.write(screen.width);
	location: 请求url地址
		document.write(location.href);//获取请求的url地址
		location.href = "hello.html";//设置请求的url地址
	history: 请求的url历史记录
		history.back();//history.go(-1);
		history.forward();//history.go(1);
	window: 顶层对象
		window.alert():
		confirm(): 确认框
			var flag = window.confirm("显示的内容");
		prompt(): 输入的对话框
			window.prompt("显示的内容","输入框的默认值");
		open(): 打开新的窗口
			window.open("hello.html","","width=200,height=200");
		close(): 关闭窗口
			window.close();
		setInterval(): 
			window.setInterval("JS代码","毫秒");
			//每多少毫秒执行1次
		setTimeout():
			window.setTimeout("JS代码","毫秒");
			//多少毫秒后执行1次
		clearInterval(): 清除setInterval
			var id = window.setInterval("JS代码","毫秒");
			clearInterval(id);
		clearTimeout(): 清除setTimeout
			同上
# JS的DOM对象
	document.write();
	getElementById();//返回指定ID的一个对象的引用
	getElementByName();//返回指定NAME的对象集合的引用
	getElementByTagName()://返回指定标签的对象集合