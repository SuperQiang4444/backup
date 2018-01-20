---
title: XML学习笔记
date: 2017-03-21 18:01:52
tags:
- XML
- Web
toc: true
---
XML基础
<!--more-->
# XML文档声明
	<?xml version="1.0" encoding="gbk"?>
	version: xml的版本1.0 1.1
	encoding: xml的编码
	standalone: 是否需要依赖其他文件 yes/no
# XML元素定义
	<preson id1="a" id2="b"></person>
# XML的注释
	<!-- ... --> //注释不能嵌套
# XML转义字符
	&	&amp;
	<	&lt;
	>	&gt;
	"	&quot;
	,	&apos;
# XML的CDATA区
	<![CDATA[  内容  ]]>
	转义字符很多的情况下使用
# XML的PI指令
	<?xml-stylesheet type="text/css" href="css的路径"?>
	可以在xml中设置样式
# XML的约束
## dtd约束
		1.xml中有几个元素，在dtd文件中写几个<!ELEMENT>
		2.判断元素是简单元素还是复杂元素
			复杂元素
				<!ELEMENT 元素名称 (子元素)>
			简单元素
				<!ELEMENT 元素名称 (#PCDATA)>
		3.需要在xml文件中引入dtd文件
			<!DOCTYPE 根元素名称 SYSTEM "dtd文件的路径">
#### dtd的三种引用方式
		1.引入外部的dtd文件
			<!DOCTYPE 根元素名称 SYSTEM "dtd路径">
		2.使用内部的dtd文件
			<!DOCTYPE 根元素名称 [
				<!ELEMENT person (name,age)>
				<!ELEMENT name (#PCDATA)>
				<!ELEMENT AGE (#PCDATA)>
			]>
		3.使用外部的dtd文件(网络上的dtd)
			<!DOCTYPE 根元素 PUBLIC "DTD名称" "DTD文档的URL">
		
#### dtd定义元素
		<!ELEMENT 元素名 约束>
		简单元素
			<!ELEMENT name (#PCDATA)>
				(#PCDATA): 约束name是字符串类型
				EMPTY: 元素为空
				ANY: 任意
		复杂元素
			<!ELEMENT person (name,age)>
				  : 表示子元素只能出现一次
				+ : 表示一次或者多次
				？: 表示零次或者一次
				* : 表示零次或者多次
				子元素用逗号隔开表示元素的出现顺序
				子元素用|隔开表示只能出现其中一个
	
#### dtd定义属性
		<!ATTLIST 元素名称 属性名称 属性类型 属性的约束>
		<!ATTLIST birthday ID1 CDATA #REQUIRED>
		属性类型
			CDATA:字符串
			枚举:出现其中一个
			ID:值只能是字母或者下划线开头
		属性的约束
			#REQUIRED:属性必须存在
			#IMPLIED:属性可有可无
			#FIXED:表示一个固定值
			直接值//不写属性直接使用值，写了属性使用设置的
#### dtd定义实体
		<!ENTITY 实体名称 "实体的值">
		使用实体 &实体名称
## schema约束
	创建一个schema文件,后缀名是 .xsd
	根节点为<schema>
	属性 xmlns="http://www.w3.org/2001/XMLSchema"
		//表示当前文件是xml文件的一个约束文件
	targetNamespace="URL"
		//表示通过地址引入约束文件
	elementFormDefault="qualified"
	复杂元素
		<element name="person">
			<complexType>
			<sequence>
				简单元素<element name="name" type="string"></element>
			</sequence>
			<complexType>
		</element>
	在被约束文件里引入约束文件
		<person xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
		xmlns="targetNamespace"	
		xsi:schemaLocation="targetNamespace 约束文件的地址路径">
	<sequence>:表示元素出现的顺序
	<all>:元素只能出现1次
	<choice>:元素只能出现其中1个
	maxOccurs="unbounded":元素出现的次数
	<any></any>:任意元素
	可以约束元素
		写在复杂元素里面,</complexType>之前
		<attribute name="id1" type="int" use="required"></attribute>
			name:元素名称
			type:元素类型
			use:是否必须出现
# XML解析简介
	xml的解析方式: dom和sax
		dom:根据xml的的层级结构在内存中分配一个树形结构,把xml的标签,属性和文本都封装成对象
		缺点:如果文件过大,造成内存溢出
		优点:很方便实现增删改操作
		sax:采用事件驱动,边读边解析
			从上到下,一行一行的解析,解析到某一个对象,返回对象名称
		缺点:不能实现增删改操作
		优点:方便实现查询操作
		