---
title: JS学习笔记2
date: 2017-03-20 12:09:08
tags:
- JS
- Web
toc: true
---


String,Array,Date,Math等
<!--more-->
# JS的String对象
	1.与html相关的方法
		bold(): 加粗
		fontcolor(): 设置字符串的颜色
		fontsize(): 设置字体的大小
		link(): 将字符串显示成超链接
			str.link("hello.html")
		sub() sup(): 下标和上标
	2.与Java相似的方法
		concat(): 连接字符串
		charAt(): 返回指定位置的字符
		indexOf(): 返回字符的位置
		split(): 切分字符串为数组
			var str = "a-b-c-d";
			var arr = str.split("-");
		replace(): 替换字符串
			var str2 = "abc";
			str2.replace("a","A");
				//str2为"Abc"
		substr()和substring()
			str.substr(1,2);
				//从第1位开始，向后截取2位
			str.substring(1,3)
				//从第1位开始到第3位结束，不包含最后一位
# JS的Array对象
	concat(): 数组的连接
	join(): 根据指定的字符分割数组（默认为","）
	push(): 向数组末尾添加元素，返回数组的新的长度
		//如果push的是一个数组,这个时候会把数组看成1个字符串添加进去
	pop(): 删除最后一个元素，返回删除的那个元素
	reverse(): 颠倒数组
# JS的Date对象
	1.JS获取当前时间
		var date = new Date();
		document.write(date);
		document.write(date.toLocaleString());//转换为常见格式
	2.JS的方法
		getFullYear(): 得到当前的年
		getMonth(): 得到当前的月(0-11)
		getDay(): 星期(0-6)
		getDate(): 当前的天
		getHours(): 小时	
		getMinutes(): 分钟
		getSeconds(): 秒
		getTime(): 毫秒
# JS的Math对象
	同Java
# JS的全局函数
	eval(): 执行JS代码
		eval("alert('123');");
	encodeURI(): 对字符进行编码
	decodeURI(): 对字符进行解码
	isNaN(): 判断当前字符串是否是数字
	parseInt(): 类型转换
# JS的函数重载
	JS不存在函数重载
	通过arguments数组模拟重载