---
title: Session学习笔记
date: 2017-04-05 14:05:25
tags:
- Session
- Web
toc: true
---
Session
<!--more-->
# HttpSession概述
HttpSession是由JavaWeb提供的，用来会话跟踪的类。session是服务器端对象，保存在服务器。
HttpSession是Servlet三大域对象之一(request、session、application(ServletContext)),所以它有setAttribute()、getAttribute()、removeAttribute()
HttpSession底层依赖Cookie，或是URL重写!
<hr>
# HttpSession的作用
会话范围:会话范围是某个用户从首次访问服务器开始，到该用户关闭浏览器结束！
服务器会为每个客户端创建一个session对象,session就好比客户在服务器端的账户，他们被服务器保存在一个Map中，这个Map被称之为session缓存!
Servlet中得到session对象:HttpSession session = request.getSession();
Jsp中得到session对象:不用创建，是内置对象。
<hr>
# HttpSession原理
![](http://wx4.sinaimg.cn/large/005P8ayVgy1febtfb12h6j30vv06djxv.jpg)
# HttpSession其他方法:
String getId():获取sessionId;
int getMaxInactiveInterval():获取session可以的最大不活动时间(秒)，默认为30分钟。
void invalidate():让session失效。
boolean isNew():查看session是否为新。
web.xml中配置session的最大不活动时间
```
<session-config>
	<session-timeout>30</session-timeout>
</session-config>
```
<hr>
# URL重写
![](http://wx3.sinaimg.cn/large/005P8ayVgy1febu4yhcj7j30tw040768.jpg)


