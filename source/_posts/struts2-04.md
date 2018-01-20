---
title: struts2_04
toc: true
date: 2017-06-16 14:21:54
tags:
- Java基础
---
拦截器和struts2标签
<!--more-->
# 拦截器概述
1.struts2封装的功能都在拦截器里面
2.struts2默认拦截器位置在struts2-core-2.3.24.jar下面的struts-default.xml里面
3.拦截器在action对象创建之后，action的方法执行之前执行
# 拦截器底层原理
1.aop思想
2.责任链模式
和过滤链很相似，一个过滤器放行后才能到下一个过滤器
一个拦截器放行后才能到下一个拦截器
# 自定义拦截器
1.继承MethodFilterInterceptor类
2.重写doIntercept()方法里面的逻辑，放行操作为return invocation.invoke();
3.注册拦截器
在要拦截的action标签所在的package标签里面声明拦截器
```
<!-- 声明拦截器 -->
<interceptors>
	<interceptor name="随便起" class="拦截器全路径">
</interceptors>
```
在action标签里使用声明的拦截器
```
<interceptor-ref name="随便起">
	<!-- 自定义拦截器会拦截所有方法，所以需要将不需要拦截的方法写在下面 -->
	<param name="excludeMethods">方法名1，方法名2</param>
</interceptor-ref>
```
默认拦截器会因为自定义拦截器不执行，所以需要手动使用
```
<interceptor-ref name="defaultStack"></interceptor-ref>
```
# struts2表单标签
对应html表单标签
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fgn3dwlhstj30tu0e2go0.jpg)
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fgn3dxbry8j30nr09qmya.jpg)
