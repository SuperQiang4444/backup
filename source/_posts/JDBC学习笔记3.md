---
title: JDBC学习笔记3
date: 2017-04-13 14:54:37
tags:
- Web
toc: true
---
dbutils
<!--more-->
# dbutils
```
		//执行增删查
		QueryRunner qRunner = new QueryRunner(JdbcUtils.getDataSource());
		String sql = "insert into user value(?,?)";
		Object[] params = {"123","123"};
		
		qRunner.update(sql, params);
		//执行查询
		QueryRunner qRunner = new QueryRunner(JdbcUtils.getDataSource());
		String sql = "select * from user where username=?";
		Object[] params = {"123"};
		
		User user = qRunner.query(sql, new BeanHandler<User>(User.class), params);
		System.out.println(user);
```
原理不写了,查day18.
<hr>
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fel2zqh20kj30vf0aagp7.jpg)
