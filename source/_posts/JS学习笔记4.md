---
title: JS学习笔记4
date: 2017-03-20 19:41:53
tags:
- JS
- Web
toc: true
---


element对象,Node对象,操作DOM树,innerHTML属性
<!--more-->
# element对象
	获取属性里面的值
		getAttribute("属性名称")
		var input1 = document.getElementById("inputid");
		alert(input1.getAttribute("value"));
	设置属性的值
		input1.setAttribute("class","haha");
	删除属性
		input1.removeAttribute("name");
		//不能删除value
	获取标签下面的子标签
		使用属性childNodes,但是这个属性兼容性很差
		获得标签下面子标签的唯一有效方法，使用getElementsByTagName方法

# Node对象
	nodeName
	nodeType
	nodeValue
	
	使用dom解析html时候,需要html里面的标签,属性和文本都封装成对象
	
	标签节点对应的值
		nodeName: 1
		nodeType: 大写标签名称 SPAN
		nodeValue: null
	属性节点对应的值
		nodeName: 2
		nodeType: 属性名称
		nodeValue: 属性的值
	文本节点对应的值
		nodeName: 3
		nodeType: 属性名称
		nodeValue: 属性的值
	
	父节点
		parentNode
	子节点
		childNodes: 得到所有子节点，但是兼容性很差
		
		firstChild: 获取第一个子节点
		lastChild: 获取最后一个子节点
		
	同辈节点
		nextSibling: 返回一个给定节点的下一个兄弟节点
		previousSibling: 返回一个给定节点的上一个兄弟节点
# 操作DOM树
	appendChild方法
		添加子节点到末尾
		特点: 类似于剪切粘贴
	insertBefore(newNode,oldNode)方法
		在某个节点之前插入一个新的节点
	removeChild方法: 删除节点
		通过父节点删除,不能自己删除自己
	replaceChild(newNode,oldNode)方法: 替换节点
		通过父节点替换,不能自己替换自己
	cloneNode(boolean): 复制节点
		true表示复制子节点
		false表示不复制子节点
# innerHTML属性
	不是DOM组成部分
	第一个作用: 获取文本内容
		var span1 = document.getElementById("sid");
		alert(span1.innerHTML);
	第二个作用: 向标签里面设置内容(可以使html代码)
		var div1 = document.getElementById("div1");
		div1.innerHTML = "<h1>AAAA</h1>";
	
