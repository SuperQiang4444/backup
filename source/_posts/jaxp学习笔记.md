---
title: jaxp学习笔记
date: 2017-03-22 19:25:53

tags:
- Web
- jaxp
- XML
toc: true
---
Jaxp是java的xml解析器
<!--more-->
# 两种解析方式
## dom方式解析
		DocumentBuilder
			抽象类,此类的实例从DocumentBuilderFactory.newDocumentBuilder()方法获取
			parse("xml路径");返回的是Document整个文档
			getElementsByTagName(String tagname);返回集合Nodelist
			createElement(String tagname);创建标签
			createTextNode(String data);创建文本
			appendChild(Node newChild);把文本添加到标签下面
			removeChild(Node oldChild);删除节点
			getParentNode();获取父节点
			NodeList list
				getLength()得到集合的长度
				item(int index)下标取到具体的值
				for(int i=0;i<list.getLength();i++){
				list.item(i);
				}
			getTextContent();获取元素具体的值
			setTextContent();修改元素的值
			回写xml
				TransformerFactory tff = TransformerFactory.newInstance();
				Transformer tf = tff.newTransformer();
				tf.transform(new DOMSource(document),new StreamResult("xml路径"));
		DocumentBuilderFactory
			抽象类,此类的实例从newInstance()获取
## sax方式解析
		sax只能查询,不能执行增删改操作
		解析过程
			当解析到开始标签时自动执行startElement();
			当解析到文本时自动执行characters();
			当解析到结束标签时自动执行endElement();
		SAXParser
			实例从SAXParserFactory.newSAXParser()方法获得
			parse("xml路径","事件处理器");
			创建一个类继承事件处理器类DefaultHandler并重写三个方法
		SAXParserFactory
			实例从newInstance()方法获得