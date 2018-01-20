---
title: hibernate03
date: 2017-05-15 11:58:55
tags:
- Java基础
toc: true
---
一对多和多对多的操作
<!--more-->
# 一对多
hibernate中多的一方用set集合表示

类中的关联
```
//一个客户有多个联系人
private Set<LinkMan> setLinkMan = new HashSet<LinkMan>();
//1个联系人属于1个客户
private Customer customer;
```
配置文件中的关联
```
<!-- 表示所有联系人 -->
<set name="setLinkMan" cascade="save-update,delete" inverse="true">
				<!-- cascade表示级联删除、添加和修改,inverse表示是否忽略维护外键(hibernate是双向维护外键的,让一的那一方不维护外键可以提高性能) --!>
	<key column="clid"></key>		<!-- 表示外键 --!>
	<one-to-many class="entity.LinkMan"/>
</set>
<!-- 表示所属客户 -->
<many-to-one name="customer" class="entity.Customer" column="clid"></many-to-one>
```
级联添加
```
//级联添加
Customer customer = new Customer();
customer.setCustName("百度");
customer.setCustLevel("vip1");
customer.setCustMobile("1120");
customer.setCustPhone("1220");
customer.setCustSource("网123络");
			
LinkMan linkMan = new LinkMan();
linkMan.setLkm_name("123lucky");
linkMan.setLkm_gender("男");
linkMan.setLkm_phone("5");
			
customer.getSetLinkMan().add(linkMan);
			
session.save(customer);
```
级联删除
```
Customer customer = session.get(Customer.class, 3);
session.delete(customer);
```
级联修改
```
Customer customer = session.get(Customer.class, 1);
LinkMan linkMan = session.get(LinkMan.class, 2);
			
customer.getSetLinkMan().add(linkMan);
linkMan.setCustomer(customer);
```
# 多对多
类中的关联
```
//一个用户多个角色
private Set<Role> setRole = new HashSet<Role>();
```
配置文件中的关联
```
<!-- 表示所有用户 -->
<set name="setUser" table="user_role"> <!-- table表示第三个表的名字 --!>
	<key column="roleid"></key>
	<many-to-many class="manytomany.User" column="userid"></many-to-many>
</set>
<!-- 表示所有角色 -->
<set name="setRole" table="user_role" cascade="save-update,delete">
	<key column="userid"></key>
	<many-to-many class="manytomany.Role" column="roleid"></many-to-many>
</set>
```
级联保存
```
User user1 = new User();
user1.setUser_name("lucky");
user1.setUser_password("123");
			
User user2 = new User();
user2.setUser_name("kack");
user2.setUser_password("1234");
			
Role r1 = new Role();
r1.setRole_name("总经理");
r1.setRole_memo("总经理");
			
Role r2 = new Role();
r2.setRole_name("秘书");
r2.setRole_memo("秘书");
			
Role r3 = new Role();
r3.setRole_name("保安");
r3.setRole_memo("保安");
			
user1.getSetRole().add(r1);
user1.getSetRole().add(r2);
			
user2.getSetRole().add(r2);
user2.getSetRole().add(r3);			
			
session.save(user1);
session.save(user2);
```
级联删除
```
User user = session.get(User.class, 1);
session.delete(user);
```
多对多的级联删除一般不会用，而是只去维护第3张表