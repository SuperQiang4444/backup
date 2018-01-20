---
title: JSTL标签库
date: 2017-04-07 11:00:38
tags:
- JSTL
- Web
toc: true
---
JSTL标签库
<!--more-->
# JSTL简介
	JSTL是apache对EL表达式的扩展，一共有四大标签库
	1.core核心标签库
	2.fmt格式化标签库
	3.sql//过时
	4.xml//过时
	使用前要通过taglib指令导入标签库
	<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %> 
<hr>
# core标签库常用标签
	<c:out>
		value:可以是字符串常量，也可是EL表达式
		default:默认输出值
		escapeXml:默认为true，表示转义

	<c:set>
		var：变量名
		value：变量值，也可是EL表达式
		scope：默认为page，可选值：page，request，session，application

	<c:remove>
		var：变量名
		scope：不给值，表示删除所有域中的该名称的变量。

	<c:url value="/index.jsp"/>,输出/项目名/index.jsp
		value:指定一个路径，它会在前面自动添加项目名。
		子标签<c:param>,用来给url后面添加参数，例如
		<c:url value="/index.jsp">
			<c:param name="username" value="张三"/> <!--可以对参数进行url编码!!-->
		</c:url>
		结果为：/项目名/index.jsp?username=%ED%2C....
		var:指定变量名，一旦添加了这个属性，那么url标签就不会再输出到页面，而是把生成url保存到域中。
		scope：它与var一起使用，用来保存url。

	<c:if test="boolean">...</c:if>

	<c:choose>
		<c:when test="">...</c:when>
		<c:when test="">...</c:when>
		<c:when test="">...</c:when>
		...
		<c:otherwise>...</c:otherwise>
	</c:choose>

	<c:forEach var="i" begin="1" end="10" step="2">
		${i}
	</c:forEach>
	<c:forEach items="${strs }" var="str">
		${str }<br/>
	</c:forEach>
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fee4jh1xnjj30hd06n75b.jpg)
<hr>
# fmt格式化库的标签
![](http://wx3.sinaimg.cn/large/005P8ayVgy1fee4meto24j30cd06vgmn.jpg)
<hr>
# 自定义标签
	需要一个标签处理类
	tld文件，它是一个xml
	页面中使用<%@taglib%>来指定tld文件的位置

	这里不多写，需要看就去查day13.

