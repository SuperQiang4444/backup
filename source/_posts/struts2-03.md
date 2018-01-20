---
title: struts2_03
toc: true
date: 2017-06-15 15:17:16
tags:
- Java基础
---
值栈
<!--more-->
# ognl
ognl是一种表达式，用来在struts2里面操作值栈数据
一般和struts2标签一起使用
ognl不是struts2的一部分
# 值栈
### 什么是值栈
值栈是action里面的存储空间
每个action对象只有1个值栈对象
### 如何获取值栈
```
//获取值栈
ActionContext context = ActionContext.getContext();
ValueStack stack = context.getValueStack();
```
### 值栈内部结构
root：结构为list结婚
context：结构为map集合
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fglxadhseqj310l0e6jv8.jpg)
### 向值栈放数据的3种方式
```
//set方法
ActionContext context = ActionContext.getContext();
ValueStack stack = context.getValueStack();
stack.set("username", "yasuo");
//push方法
stack.push("abcd");
//声明变量，生成get方法
private String name;
public String getName() {
		return name;
	}
```
### 从值栈获取数据
```
引用struts2的标签
<%@ taglib prefix="s" uri="/struts-tags" %>
<!-- 获取字符串 -->
<s:property value="username"/>
<!-- 获取对象 -->
<s:property value="user.username"/>
<s:property value="user.password"/>
<s:property value="user.address"/>
<!-- 获取list集合1 -->
<s:property value="list[0].username"/>
<s:property value="list[0].password"/>
<s:property value="list[0].address"/>
<br>
<s:property value="list[1].username"/>
<s:property value="list[1].password"/>
<s:property value="list[1].address"/>
<br>
<!-- 获取list集合2 -->
<s:iterator value="list">
	<s:property value="username"/>
	<s:property value="password"/>
	<s:property value="address"/>
</s:iterator>
<br>
<!-- 获取list集合3 -->
<s:iterator value="list" var="user"> 
	<!-- 遍历值栈list集合，得到每个user对象，放进context里面
		获取context里面的数据要加# -->
	<s:property value="#user.username"/>
	<s:property value="#user.password"/>
	<s:property value="#user.address"/>
</s:iterator>
<br>
<!-- 获取push方法设置的值,push的值会放到1个top数组里面 -->
<s:property value="[0].top"/>
```
# EL表达式获取值栈的值？
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fglxkc6708j30hl04uq3k.jpg)
# %使用
直接在struts2表单标签里面使用ognl表达式不识别，只有加上%才会识别。
```
<s:textfield name="username" value="%{#request.req}"></s:textfield>
```