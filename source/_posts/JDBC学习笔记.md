---
title: JDBC学习笔记
date: 2017-04-11 19:24:06
tags:
- Web
toc: true
---
Class.forName("com.mysql.jdbc.Driver");//加载驱动类
Connection con = DriverManager.getConnection(url,username,password);
Statement stmt = con.createStatement();
//Statement stmt = con.createStatement(int,int);
//这个带参数的语句决定ResultSet是否可滚动、是否敏感、是否可更新
<!--more-->
# ResultSet
![](http://wx2.sinaimg.cn/large/005P8ayVgy1feizipe9b0j30ix0crtar.jpg)
# 获取结果集元数据
![](http://wx1.sinaimg.cn/large/005P8ayVgy1feizipztf1j30cw03774m.jpg)
# 遍历
![](http://wx1.sinaimg.cn/large/005P8ayVgy1feiziqe105j30bz056q3e.jpg)
PrepareStatement
![](http://wx4.sinaimg.cn/large/005P8ayVgy1feizw9313bj30dd07idg9.jpg)
![](http://wx4.sinaimg.cn/large/005P8ayVgy1feizyxxpqlj30ht06iwev.jpg)
# sql时间和util时间的转换
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fej04ends3j30j70cvjsf.jpg)
java.util.Date-->java.sql.Date的转换：
```
	java.util.Date date = new java.util.Date();
	long l = date.getTime();
	java.sql.Date sqlDate = new java.sql.Date(l);
```	
# blob类型
这里就不写了
# 批处理
pstmt.addBatch();//添加批！
pstmt.executeBatch();//执行批！