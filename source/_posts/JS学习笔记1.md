---
title: JS学习笔记1
date: 2017-03-17 16:01:18
tags:
- JS
- Web
toc: true
---


JS基础
<!--more-->
# JS的原始类型
	string	
	number
	boolean
	null
	undifined
		typeof();查看当前变量的数据类型
# JS的语句
	if判断语句
	switch语句
	循环语句 for while do-while
		以上同Java
# JS的运算符
	1.js里面不区分整数和小数
		var j = 123;
		alert(j/1000*1000);
			//Java里面结果为0
			//JS里面结果为123
	2.字符串加减操作
		var str = "123";
		alert(str+1);
				//同Java，结果为1231
		alert(str-1);
				//做减法运算，结果为122
	3.输出语句
		document.write("aaa");	//内容
		document.write("html语句");	//html语句
# JS的数组
	1.定义方式
		第一种: var arr = [1,2,3];	var arr = [1,"4",true];
		第二种: var arr1 = new Array(5);
			arr1[0] = "1";
		第三种: var arr2 = new Array(3,4,5);
	2.arr.length可以获取数组长度
# JS的函数
	1.方式一
		function 方法名(参数列表){
			方法体;
			返回值可有可无(根据实际需要);
		}
	2.方式二
		匿名函数
		var add = function(参数列表){
			方法体和返回值
		}	
	3.方式三
		new Function("参数列表","方法体和返回值");