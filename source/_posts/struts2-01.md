---
title: struts2_01
date: 2017-06-08 10:19:37
tags:
- Java基础
toc: true
---
struts2的一些简单笔记
<!--more-->
# struts2概述
应用在web层的框架
struts2和struts1没有直接关系，内核为webwork2
web层的框架还有springMVC
# struts2入门
1.导入jar包
```
asm-3.3.jar
asm-commons-3.3.jar
asm-tree-3.3.jar
commons-fileupload-1.3.1.jar
commons-io-2.2.jar
commons-lang3-3.2.jar
freemarker-2.3.22.jar
javassist-3.11.0.GA.jar
log4j-api-2.2.jar
log4j-core-2.2.jar
ognl-3.0.6.jar
servlet-api.jar
struts2-core-2.3.24.jar
xwork-core-2.3.24.jar
```
2.创建action
访问action，默认执行里面的execute方法，类似于servlet的service方法。
```
public class HelloAction {
	
	public String execute() {
		return "ok";
	}
}
```
3.配置action的类访问路径
struts2核心配置文件位置必须在src下，名称为struts.xml
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE struts PUBLIC
	"-//Apache Software Foundation//DTD Struts Configuration 2.3//EN"
	"http://struts.apache.org/dtds/struts-2.3.dtd">
<struts>
<constant name="struts.i18n.encoding" value="utf-8"></constant><!-- 常量配置（还可以在src下面创建struts.properties进行配置，web.xml也可以） -->
	<package name="hellodemo" extends="struts-default" namespace="/">
		<action name="hello" class="action.HelloAction">
			<result name="ok">/hello.jsp</result>
		</action>
	</package>
</struts>
```
4.配合struts2的过滤器
web.xml加入
```
<filter>
        <filter-name>struts2</filter-name>
        <filter-class>org.apache.struts2.dispatcher.ng.filter.StrutsPrepareAndExecuteFilter</filter-class>
    </filter>

<filter-mapping>
        <filter-name>struts2</filter-name>
        <url-pattern>/*</url-pattern>
</filter-mapping>
```
5.访问
输入http://localhost:8080/项目名/hell.action
# struts2分模块开发
单独写配置文件，将配置文件引入到核心配置文件中。
```
<include file=""></include>
```
# action的3种编写方式
1.创建普通类
2.创建类,实现接口Action
3.创建类,继承类ActionSupport
# 访问action的方法的3种方式
1.使用action标签的method属性，在这个属性里面写执行的action方法
```
<action name="add" class="action.HelloAction" method="add"></action>
```
2.使用通配符方式
```
<action name="*" class="action.HelloAction" method="{1}"></action>
```
{1}代表第一个*号
3.动态访问实现
基本不用

