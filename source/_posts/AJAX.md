---
title: AJAX
date: 2017-04-24 17:49:20
tags:
- Web
- AJAX
toc: true
---
AJAX的基本概念和案例
<!--more-->
# AJAX简介
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fgeqo4fsfkj30sl0c8wii.jpg)
# AJAX四步操作
![](http://wx3.sinaimg.cn/large/005P8ayVgy1fgeqo5r9c5j30i10ezn14.jpg)
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fgeqo6juxnj30ou0bsq7m.jpg)
# 省市联动
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fgeqo70sr8j30pe0c8jvg.jpg)
### ProvinceServlet
```
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		//创建解析器对象
		SAXReader reader = new SAXReader();
		InputStream inputStream = this.getClass().getResourceAsStream("/china.xml");
		try {
			//得到Document对象
			Document document = reader.read(inputStream);
			
			//查询所有的province的name元素，得到属性对象，循环遍历，连接成1个字符串发送给客户端
			List<Attribute> arrList = document.selectNodes("//province/@name");
			StringBuilder sBuilder = new StringBuilder();
			for(int i = 0; i < arrList.size(); i++) {
				sBuilder.append(arrList.get(i).getValue());
				if(i < arrList.size() - 1){
					sBuilder.append(",");
				}
			}
			response.getWriter().print(sBuilder);
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}
```
### CityServlet
```
protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/xml;charset=utf-8");
		
		//创建解析器对象
		SAXReader reader = new SAXReader();
		InputStream inputStream = this.getClass().getResourceAsStream("/china.xml");
		try {
			//得到Document对象
			Document document = reader.read(inputStream);
			
			//获取省份名称,得到<province>元素,转成字符串发送给客户端
			String pname = request.getParameter("pname");
			Element proEle = (Element) document.selectSingleNode("//province[@name='"+ pname +"']");
			String xmlStr = proEle.asXML();
			response.getWriter().print(xmlStr);
		} catch (Exception e) { 
			throw new RuntimeException(e);
		}
	}
```
### html
```
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
/*
 *1文档加载完时发送请求，得到所有省份名称，显示在<select name="province"/>中
 *2选择新的省份时，发送请求得到xml文档的province元素，解析xml文档，得到其中所有的<city>，在得到每个<city>元素的内容
 *生成option插入。
 */
 
 //得到request对象
function createXMLHttpRequest() {
	try{
		return new XMLHttpRequest();//大多数浏览器
	}catch (e) {
		try{
			return ActvieXObject("Msxm12.XMLHTTP");//IE6.0
		}catch (e) {
			try {
				return ActvieXObject("Microsoft.XMLHTTP");//IE5.5
			}catch (e) {
				alert("您用的什么浏览器？");
				throw e;
			}
		}
	}
}

//1文档加载完时发送请求，得到所有省份名称，显示在<select name="province"/>中
window.onload = function() {
	var xmlHttp = createXMLHttpRequest();
	xmlHttp.open("GET", "<c:url value='/ProvinceServlet'/>", true);
	xmlHttp.send(null);
	xmlHttp.onreadystatechange = function() {
		if(xmlHttp.readyState == 4 && xmlHttp.status == 200) {
			//获取服务器响应
			var text = xmlHttp.responseText;
			//使用逗号分隔
			var arr = text.split(",");
			
			//循环遍历每个省份名称，每个名称生成一个option对象，添加到<select>中
			for(var i =0; i <arr.length; i++) {
				var op = document.createElement("option");
				op.value = arr[i];
				var textNode = document.createTextNode(arr[i]);
				op.appendChild(textNode);
				
				document.getElementById("p").appendChild(op);
			}
		}
	};
	
	//给<select name="province">添加改变监听
	var proSelect = document.getElementById("p");
	proSelect.onchange = function(){
		var xmlHttp = createXMLHttpRequest();
		xmlHttp.open("POST", "<c:url value='/CityServlet'/>", true);
		xmlHttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		xmlHttp.send("pname=" + proSelect.value);
		xmlHttp.onreadystatechange = function() {
			if(xmlHttp.readyState == 4 && xmlHttp.status == 200) {
				//移除option
				var citySelect = document.getElementById("c");
				var optionEleList = citySelect.getElementsByTagName("option");
				
				while(optionEleList.length > 1){
					citySelect.removeChild(optionEleList[1]);
				}
				
				var doc = xmlHttp.responseXML;
				//循环遍历city元素
				var cityEleList = doc.getElementsByTagName("city");
				for(var i = 0; i < cityEleList.length; i++) {
					var cityEle = cityEleList[i];
					var cityName;
					if(window.addEventListener){//处理浏览器差异
						cityName = cityEle.textContent;//支持FireFox等浏览器
					}else{
						cityName = cityEle.text;//支持IE
					}
					
					//使用市名称创建option
					var op = document.createElement("option");
					op.value = cityName;
					
					var textNode =document.createTextNode(cityName);
					op.appendChild(textNode);
					
					var citySelect = document.getElementById("c");
					citySelect.appendChild(op);
				}
			}
		};
	};
};
</script>
</head>
<body>

<h1>省市联动</h1>
<select name="province" id="p">
	<option>===请选择省===</option>
</select>
&nbsp;&nbsp;&nbsp;&nbsp;
<select name="city" id="c">
	<option>===请选择市===</option>
</select>

</body>
</html>
```