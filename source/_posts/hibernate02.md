---
title: hibernate02
date: 2017-05-11 15:12:10
tags:
- Java基础
toc: true
---
实体类的三种状态
Hibernate缓存
事务代码规范
Hibernate绑定session
Hibernate的api
<!--more-->
# 实体类的三种状态
1.瞬时态
对象里面没有ID，对象与session没关联

2.持久态
对象里面有ID，对象与session有关联

3.托管态
对象里面有ID，对象与session没关联
# Hibernate缓存
hibernate的一级缓存默认打开的
一级缓存的范围是session
一级缓存中存储数据必须是持久态数据

hibernate的二级缓存默认不打开，需要配置
二级缓存已经不使用了，替代技术为redis
二级缓存的范围为sessionFactory
### 一级缓存的特性
持久态数据的更新不需要update语句，提交事务会自动更新。
原理
![](http://wx4.sinaimg.cn/large/005P8ayVgy1ffhgawr1ltj30v00ed77t.jpg)
# 事务代码规范
```
try{
	开启事务
	提交事务
}catch(){
	回滚事务
}finally{
	关闭
}
```
# Hibernate绑定session
底层是threadLocal
1.在核心配置文件中配置
```
<property name="current_session_context_class">thread</property>
```
2.调用sessionFactory的方法
```
sessionFactory.getCurrentSession();
```
# Hibernate的api
Query
```
//4.使用query对象查询
//创建query
Query query = session.createQuery("from User");
//调用方法得到结果
List<User> list = query.list();
for (User user : list) {
	System.out.println(user);
}
```
Criteria
```
//4.使用criteria对象查询
//创建criteria
Criteria criteria = session.createCriteria(User.class);
//调用方法得到结果
List<User> list = criteria.list();
for (User user : list) {
	System.out.println(user);
}
```
SQLQuery
```
//创建SQLQuery对象
SQLQuery sqlQuery = session.createSQLQuery("select * from t_user");
//如果不设置，默认返回list为数组形式
sqlQuery.addEntity(User.class);
//调用方法得到结果
List<User> list = sqlQuery.list();
for (User user : list) {
	System.out.println(user);
}
```