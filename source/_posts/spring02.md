---
title: spring02
toc: true
date: 2017-06-29 11:01:05
tags:
- Java基础
---
# spring注解创建对象
<!--more-->
### 1.导入jar包
```
commons-logging-1.3.jar
log4j-1.2.16.jar
spring-beans-4.0.6.RELEASE.jar
spring-context-4.0.6.RELEASE.jar
spring-core-4.0.6.RELEASE.jar
spring-expression-4.0.6.RELEASE.jar
spring-aop-4.0.6.RELEASE.jar
```
### 2.创建类
```
@Component(value="user")//代替xml配置user类
@Scope(value="prototype")//多实例配置
public class User {
	public void add() {
		System.out.println("add.....");
	}
}
```

### 3.spring配置文件
```
<?xml version="1.0" encoding="UTF-8"?>
	<beans xmlns="http://www.springframework.org/schema/beans"
	xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
	xmlns:context="http://www.springframework.org/schema/context" xsi:schemaLocation="
	http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
	http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd"> <!-- bean definitions here -->
	<!-- 开启注解扫描 -->
	<context:component-scan base-package="anno"></context:component-scan>

	<!-- 只扫描属性上的注解 -->
	<!-- 	<context:annotation-config></context:annotation-config>-->
</beans>
```
### 4.测试类
```
@Test
public void testUser() {
	ApplicationContext context = 
			new ClassPathXmlApplicationContext("bean1.xml");
	User user = (User) context.getBean("user");
	user.add();
}
```
### NOTE:创建对象的注解
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fh1whkrrexj30fw06dt9z.jpg)
# spring注解注入属性
### userService类
```
@Service("userService")
public class Userservice {
	
//	//得到dao对象
//	@Autowired
//	private UserDao userDao;
//	//使用注解不需要set方法
	
	//得到dao对象
	@Resource(name="userDao")
	private UserDao userDao;
	//使用注解不需要set方法
	
	public void add() {
		System.out.println("service....");
		userDao.add();
	}
}
```
### userDao类
```
@Component("userDao")
public class UserDao {
	public void add() {
		System.out.println("dao....");
	}
}
```
# AOP
采用横向抽取机制，取代了传统纵向继承体系重复性代码
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fh1wz2rfguj30l70bv40h.jpg)
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fh1wz3vtzqj30e009xt9l.jpg)
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fh1x3egpzjj30ey09375s.jpg)
# aspectj
AspectJ是一个面向切面的框架，它扩展了Java语言。AspectJ定义了AOP语法，所以它有一个专门的编译器用来生成遵守Java字节编码规范的Class文件。
1.在spring里面进行aop操作，使用aspectj实现
aspectj不是spring的一部分，和spring一起使用进行aop操作
spring2.0以后新增了对aspectj的支持
2.使用aspectj实现aop有2中方式
xml配置和注解方式
<hr>
### 要导入的jar包
aopalliance-1.0-20100517.210215-13.jar
aspectjweaver-1.6.10.jar
spring-aop-4.0.6.RELEASE.jar
spring-aspects-4.0.6.RELEASE.jar
核心配置文件导入aop约束
### 使用表达式配置切入点
![](http://wx2.sinaimg.cn/large/005P8ayVgy1fh1xl1upsrj30da05jwf6.jpg)
### 被增强类
```
public class Book {
	
	public void add() {
		System.out.println("add....");
	}
}
```
### 增强类
```
public class MyBook {
	
	public void before1() {
		System.out.println("前置增强......");
	}
	
	public void after1() {
		System.out.println("后置增强....");
	}
	
	//环绕通知
	public void around1(ProceedingJoinPoint proceedingJoinPoint) throws Throwable {
		//方法之前
		System.out.println("方法之前....");
		
		proceedingJoinPoint.proceed();
		
		//方法之后
		System.out.println("方法之后....");
	}
}
```
### 配置文件
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:aop="http://www.springframework.org/schema/aop" xsi:schemaLocation="
        http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/aop http://www.springframework.org/schema/aop/spring-aop.xsd"> <!-- bean definitions here -->
	<!-- 配置对象 -->
	<bean id="book" class="aop.Book"></bean>
	<bean id="myBook" class="aop.MyBook"></bean>

	<!-- 配置aop操作 -->
	<aop:config>
		<!-- 配置切入点 -->
		<aop:pointcut expression="execution(* aop.Book.*(..))" id="pointcut1"/>
		<!-- 配置切面 -->
		<aop:aspect ref="myBook">
			<!-- 配置增强类型 -->
			<aop:before method="before1" pointcut-ref="pointcut1"/>
			
			<aop:after-returning method="after1" pointcut-ref="pointcut1"/>
		
			<aop:around method="around1" pointcut-ref="pointcut1"/>
		</aop:aspect>
	</aop:config>

</beans>
```






