---
title: spring01
toc: true
date: 2017-06-26 10:20:47
tags:
- Java基础
---
spring入门
<!--more-->
# spring概述
1.spring是开源轻量级框架
2.spring是一站式框架
web：springMVC
service：ioc
dao：jdbcTemplate
3.原理
aop面向切面编程
ioc控制反转
# IOC底层原理
1.用到的技术
xml配置文件
dom4j解析xml
工厂设计模式
反射
![IOC底层原理](http://wx4.sinaimg.cn/large/005P8ayVgy1fgyr6gao24j30mf0eatbj.jpg)
# IOC入门
### 1.导入jar包
```
commons-logging-1.3.jar
junit-4.3.1.jar
log4j-1.2.16.jar
spring-beans-4.0.6.RELEASE.jar
spring-context-4.0.6.RELEASE.jar
spring-core-4.0.6.RELEASE.jar
spring-expression-4.0.6.RELEASE.jar
```
### 2.创建类
```
public class User {
	private String username;
	 
	public User(String username) {
		this.username = username;
	}

	public void add(){
		 System.out.println("add.........");
	 } 
}
```
### 3.创建spring配置文件，配置创建类
spring核心配置文件名称和位置不是固定的
建议放到src下，名称为applicationContext.xml
引入schema约束
```
<beans xmlns="http://www.springframework.org/schema/beans"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
<!--  p名称空间  -->
<!-- xmlns:p="http://www.springframework.org/schema/p" -->
    xsi:schemaLocation="
        http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">
</beans>
```
核心配置文件
```
<!-- ioc入门 -->
<bean id="user" class="ioc.User"></bean>
```
### 4.写测试类
```
public class TestIoc {

	@Test
	public void testUser() {
		//1加载spring配置文件，根据创建对象
		ApplicationContext context = new ClassPathXmlApplicationContext("bean1.xml");
		//2得到配置创建的对象
		User user = (User) context.getBean("user");
		user.add();
	}
	
}
```
# bean实例化的三种方式
### 1.使用无参构造创建
```
<!-- ioc入门 -->
<bean id="user" class="ioc.User"></bean>
```
### 2.使用静态工厂创建
```
public class bean2 {
	public void add(){
		System.out.println("bean2........");
	}
}
```
```
public class Bean2Factory {
	//静态的方法，返回Bean2对象
	public static bean2 getBean2(){
		return new bean2();
	}
}
```
```
<!-- 使用静态工厂创建对象 -->
<bean id="bean2" class="bean.Bean2Factory" factory-method="getBean2"></bean>
```
### 3.使用实例工厂创建
```
public class Bean3 {
	public void add(){
		System.out.println("bean3........");
	}
}
```
```
public class Bean3Factory {
	//普通的方法，返回Bean3对象
	public Bean3 getBean3() {
		return new Bean3();
	}
}
```
```
<!-- 使用实例工厂创建对象 -->
<bean id="bean3Factory" class="bean.Bean3Factory"></bean>
<bean id="bean3" factory-bean="bean3Factory" factory-method="getBean3"></bean> 
```
# bean标签scope
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fgyr6h85ktj30nj0820uf.jpg)
# 有参数构造注入属性
```
public class PropertyDemo1 {
	private String username;

	public PropertyDemo1(String username) {
		this.username = username;
	}
	
	public void test() {
		System.out.println(username);
	}
}
```
```
<!-- 使用有参数构造注入属性 -->
<bean id="demo1" class="property.PropertyDemo1">
	<constructor-arg name="username" value="哈赛"></constructor-arg>
</bean>
```
# set方法注入属性
```
public class Book {
	private String bookname;

	public void setBookname(String bookname) {
		this.bookname = bookname;
	}
	
	public void demobook() {
		System.out.println(bookname);
	}
}
```
```
<!-- 使用set方法注入属性 -->
<bean id="book" class="property.Book">
	<property name="bookname" value="Java虚拟机"></property>
</bean>
```
# 注入对象类型属性
```
public class UserService {
	
	private UserDao userDao;
	
	public void setUserDao(UserDao userDao) {
		this.userDao = userDao;
	}
	
	public void add() {
		System.out.println("service....");
		userDao.add();
	}
}
```
```
public class UserDao {
	public void add() {
		System.out.println("dao....");
	}
}
```
```
<!-- 注入对象类型属性 -->
<bean id="userDao" class="property.UserDao"></bean>

<bean id="userService" class="property.UserService">
	<property name="userDao" ref="userDao"></property>
</bean>
```
# p名称空间注入和复杂类型属性注入
约束文件添加
xmlns:p="http://www.springframework.org/schema/p"
```
<!-- p名称空间注入 -->
<bean id="person" class="property.Person" p:pname="yasuo">
</bean>
<!-- 注入复杂类型属性值 -->
<bean id="person" class="property.Person">
	<!-- 数组 -->
	<property name="arrs">
		<list>
			<value>1</value>
			<value>2</value>
			<value>3</value>
		</list>
	</property>
	<!-- list -->
	<property name="list">
		<list>
			<value>4</value>
			<value>5</value>
			<value>6</value>
		</list>
	</property>
	<!-- map -->
	<property name="map">
		<map>
			<entry key="a" value="7"></entry>
			<entry key="b" value="8"></entry>
			<entry key="c" value="9"></entry>
		</map>
	</property>
	<!-- properties -->
	<property name="properties">
		<props>
			<prop key="driverclass">com.mysql.jdbc.Driver</prop>
			<prop key="username">root</prop>
		</props>
	</property>
</bean>
```
```
public class Person {
	public String pname;
	
	public void setPname(String pname){
		this.pname = pname;
	}
	
	private String[] arrs;
	private List<String> list;
	private Map<String, String> map;
	private Properties properties;
	
	public void setArrs(String[] arrs) {
		this.arrs = arrs;
	}
	public void setList(List<String> list) {
		this.list = list;
	}
	public void setMap(Map<String, String> map) {
		this.map = map;
	}
	public void setProperties(Properties properties) {
		this.properties = properties;
	}

	public void test1() {
		System.out.println("pname:"+pname);
		System.out.println("arrs:"+arrs);
		System.out.println("list:"+list);
		System.out.println("map:"+map);
		System.out.println("properties:"+properties);
	}
}
```
# spring将核心配置文件加载压力给服务器
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fgyrm09dq2j30kd0cwdjz.jpg)
### 1.导入jar包
spring-web-4.0.6.RELEASE.jar
### 2.配置监听器
在web.xml里面
```
<!-- 配置监听器 -->
<listener>
	<listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>
</listener>
```
### 3.指定spring配置文件位置
在web.xml里面
```
<!-- 指定spring配置文件位置 -->
<context-param>
	<param-name>contextConfigLocation</param-name>
	<param-value>classpath:bean1.xml</param-value>
</context-param>
```