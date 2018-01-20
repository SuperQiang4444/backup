---
title: spring04
toc: true
date: 2017-07-07 13:34:59
tags:
- Java基础
---
ssh整合
<!--more-->
# struts和spring整合
### 1.目的
把action的创建交给spring
### 2.导入jar包
struts2-spring-plugin-2.3.24.jar
struts2和spring的jar
### 3.配置文件
spring配置文件
```
<!-- 配置action对象(不要忘记多实例的配置) -->
<bean id="userAction" class="action.UserAction" scope="prototype"></bean>
```
struts2配置文件
```
<package name="hellodemo" extends="struts-default" namespace="/">
	<!-- class里面写spring里面配置的id -->
	<action name="userAction" class="userAction"></action>
</package>
```
* 其他步骤这里省略
# hibernate和spring整合
### 1.目的
把sessionFactory的创建交给spring，在服务器启动时创建
### 2.导入jar包
spring-orm-4.0.6.RELEASE.jar
hibernate和spring的jar
### 3.配置文件
spring配置文件
```
<!-- 配置c3p0连接池 -->
<bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
	<!-- 注入属性值 -->
	<property name="driverClass" value="com.mysql.jdbc.Driver"></property>
	<property name="jdbcUrl" value="jdbc:mysql:///spring_day04"></property>
	<property name="user" value="root"></property>
	<property name="password" value="0000"></property>
</bean>
<!-- sessionFactory创建交给spring -->
<bean id="sessionFactory" class="org.springframework.orm.hibernate4.LocalSessionFactoryBean">
	<!-- 注入DataSource -->
	<property name="dataSource" ref="dataSource"></property>
	<!-- 指定hibernate配置文件 -->
	<property name="configLocations" value="classpath:hibernate.cfg.xml"></property>
</bean>
```
* hibernate的配置文件省略
# dao使用hibernateTemplate
spring配置文件需要添加的配置
```
<!-- 第一步配置事务管理器 -->
<bean id="transactionManager" class="org.springframework.orm.hibernate4.HibernateTransactionManager">
	<!-- 注入sessionFactory -->
	<property name="sessionFactory" ref="sessionFactory"></property>
</bean>
<!-- 第二步开启事务注解 -->
<tx:annotation-driven transaction-manager="transactionManager"/>
 
<!-- 配置action对象 -->
<bean id="userAction" class="action.UserAction" scope="prototype">
	<!-- 注入service -->
	<property name="userService" ref="userService"></property>
</bean>
<!-- 创建service对象 -->
<bean id="userService" class="service.UserService">
	<!-- 注入dao -->
	<property name="userDao" ref="userDaoImpl"></property>
</bean>
<!-- 创建实现类对象 -->
<bean id="userDaoImpl" class="dao.UserDaoImpl">
	<!-- 注入hibernateTemplate -->
	<property name="hibernateTemplate" ref="hibernateTemplate"></property>
</bean>
<!-- 创建hibernateTemplate对象 -->
<bean id="hibernateTemplate" class="org.springframework.orm.hibernate4.HibernateTemplate">
	<!-- 注入sessionFactory -->
	<property name="sessionFactory" ref="sessionFactory"></property>
</bean>
```
service
```
@Transactional
public class UserService {
	//注入dao对象
	private UserDao userDao;
	public void setUserDao(UserDao userDao) {
		this.userDao = userDao;
	}
	
	public void add(){
		System.out.println("service....");
		userDao.add();
	}
}
```
dao实现类
```
public class UserDaoImpl implements UserDao {
	//得到hibernateTemplate对象
	private HibernateTemplate hibernateTemplate;
	public void setHibernateTemplate(HibernateTemplate hibernateTemplate) {
		this.hibernateTemplate = hibernateTemplate;
	}

	public void add() {
		User user = new User();
		user.setUsername("yasuo");
		user.setAddress("zed");
		//调用save方法添加
		hibernateTemplate.save(user);
	}
}
```
# hibernateTemplate方法
添加
save(entity)
根据id查询
get(entity.class, id)
find方法查询所有记录
find("from User")
find方法条件查询
find("from User where username=?", "yasuo")
# 把hibernate配置文件写到spring配置文件中
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fhemlp792bj30hj082dif.jpg)
# spring分模块开发
引入其他xml文件
```
<import resource="classpath:user.xml"/>
```
