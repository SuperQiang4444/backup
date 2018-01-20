---
title: AJAX2
date: 2017-04-25 16:58:49
tags:
- Web
- AJAX
toc: true
---
XStream
JSON,json-lib
<!--more-->
# XStream
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fgeqo7lnk4j30vt0b2jvb.jpg)
# JSON
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fgeqo85tc5j30ef07wab3.jpg)
# json-lib
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fgeqo8krgaj30ix07bq3t.jpg)
# ajaxutils.js
```
//创建request
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

function ajax(option) {
	//1.得到xmlHttp
	var xmlHttp = createXMLHttpRequest();
	//2.打开连接
	if(!option.method) {//默认get
		option.method = "GET";
	}
	if(option.asyn == undefined) {//默认异步
		option.asyn = true;
	}
	xmlHttp.open(option.method, option.url, option.asyn);
	//3.判断是否为POST
	if("POST" == option.method) {
		xmlHttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	}
	//4.发送请求
	xmlHttp.send(option.params);
	//5.注册监听
	xmlHttp.onreadystatechange = function() {
		if(xmlHttp.readyState == 4 && xmlHttp.status == 200) {
			var data;
			if(!option.type) {
				data = xmlHttp.responseText;
			} else if(option.type == "xml") {
				data = xmlHttp.responseXML;
			} else if(option.type == "text") {
				data = xmlHttp.responseText;
			} else if(option.type == "json") {
				var text = xmlHttp.responseText;
				data = eval("(" + text + ")");
			}
			
			option.callback(data);
			
		}
	};
};
```

