---
title: dom4j学习笔记
date: 2017-03-22 19:26:05

tags:

- dom4j
- XML
- Web
toc: true
---
# dom4j
<!--more-->
	得到document
		SAXReader reader = new SAXReader();
		Document document = reader.read(url);
	document的父接口是Node
		getRootElement();返回根节点Element
	Element是接口，父接口是Node
		getParent();获取父节点
		addElement();添加标签
		element(qname);获取下面叫qname的第一个子标签
		elements(qname);获取下面qname的所有子标签(一层),返回的是List
		elements();获取下面的一层子标签
		getText();得到值
	回写xml
		OutputFormat format = OutputFormat.createPrettyPrint();//有缩进格式//createCompactFormat();无缩进
		XMLWriter xmlWriter = new XMLWriter(new FileOutputStream("路径"),format);
		xmlWriter.write(document);
		xmlWriter.close();
# XPATH
![](http://wx2.sinaimg.cn/mw690/005P8ayVgy1fdwunewkt4j30na08udht.jpg)
