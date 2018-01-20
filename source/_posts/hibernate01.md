---
title: hibernate01
date: 2017-05-10 11:37:22
tags:
- Java基础
toc: true
---
hibernate入门
<!--more-->
# 概念
Hibernate是一种ORM框架,全程为Object-Relative Database-Mapping,对象关系映射。
应用于DAO层，用来管理数据库。
# 准备工作
需要导入的jar包
```
antlr-2.7.7.jar
dom4j-1.6.1.jar
geronimo-jta_1.1_spec-1.1.1.jar
hibernate-commons-annotations-5.0.1.Final.jar
hibernate-core-5.0.12.Final.jar
hibernate-entitymanager-5.0.12.Final.jar
hibernate-jpa-2.1-api-1.0.0.Final.jar
jandex-2.0.0.Final.jar
javassist-3.18.1-GA.jar
jboss-logging-3.3.0.Final.jar//以上为hibernate的包
junit-4.3.1.jar
log4j-1.2.16.jar
mysql-connector-java-5.1.17-bin.jar
slf4j-api-1.6.2.jar
slf4j-log4j12-1.6.2.jar
```
# 代码部分
### 实体类
```
public class User {
	private Integer uid;
	private String username;
	private String password;
	private String address;
	public Integer getUid() {
		return uid;
	}
	public void setUid(Integer uid) {
		this.uid = uid;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	
}
```
实体类配置文件(建议在实体类包下，命名为实体类名.hbm.xml)
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE hibernate-mapping PUBLIC
	"-//Hibernate/Hibernate Mapping DTD 3.0//EN"
	"http://hibernate.sourceforge.org/dtd/hibernate-mapping-3.0.dtd">
<hibernate-mapping package="entity">
								<!-- 实体类所在的包 -->
	<class name="User" table="t_user">		<!-- 实体类 -->
		<id name="uid" column="uid">		<!-- id主键 -->
			<generator class="native"></generator>		<!-- 数据库自增长 -->
		</id>
		<property name="username" column="username"></property>	<!-- 普通属性 -->
		<property name="password" column="password"></property>
		<property name="address" column="address"></property>
	</class>
</hibernate-mapping>
```
### 核心配置文件
要求：必须在src下，名字必须为hibernate.cfg.xml
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE hibernate-configuration PUBLIC
	"-//Hibernate/Hibernate Configuration DTD 3.0//EN"
	"http://hibernate.sourceforge.org/dtd/hibernate-configuration-3.0.dtd">
<hibernate-configuration>
	<session-factory>
		<!-- JDBC配置代码 -->
		<property name="hibernate.connection.driver_class">com.mysql.jdbc.Driver</property>
		<property name="hibernate.connection.url">jdbc:mysql:///hibernate_day01</property>
		<property name="hibernate.connection.username">root</property>
		<property name="hibernate.connection.password">0000</property>
		
		<!-- 指定使用mysql数据库格式的sql语句 -->
		<property name="hibernate.dialect">org.hibernate.dialect.MySQLDialect</property>
		<!-- 指定在控制台打印生成的sql语句 -->
		<property name="hibernate.show_sql">true</property>
		<!-- 指定在控制台打印生成的sql语句格式 -->
		<property name="hibernate.format_sql">true</property>
		<!-- 自动创建表 -->
		<property name="hibernate.hbm2ddl.auto">update</property>
		
		<!-- 不写可能会异常 -->
		<property name="current_session_context_class">thread</property>
		
		<!-- 把映射文件放到这里 -->
		<mapping resource="entity/User.hbm.xml"/>
	</session-factory>
</hibernate-configuration>
```
### 测试类
```
public class HibernateDemo {
	@Test
	public void testAdd() {
		//1.加载配置文件
		Configuration configuration = new Configuration();
		configuration.configure();
		
		//2.创建SessionFactory对象
		//在过程中根据映射关系，在数据库中创建表
		SessionFactory sessionFactory= configuration.buildSessionFactory();
		
		//3.使用SessionFactory创建session对象
		Session session = sessionFactory.openSession();
		
		//4.开启事务
		Transaction tx = session.beginTransaction();
		
		//5.具体crud操作
		//添加功能
		User user = new User();
		user.setUsername("小王");
		user.setPassword("123");
		user.setAddress("日本");
		//调用session添加
		session.save(user);
		
		//6.提交事务
		tx.commit();
		
		//7.关闭资源
		try {
			session.close();
			sessionFactory.close();
		} catch (Exception e) {
			throw new RuntimeException();
		}
		
	}
	
}
```
结果：
1.在数据库中为我们建了表
2.控制台输出为
Hibernate: 
    insert 
    into
        t_user
        (username, password, address) 
    values
        (?, ?, ?)