---
title: spring03
toc: true
date: 2017-06-30 10:25:48
tags: 
- Java基础
---
# aspectj注解aop操作
<!--more-->
* 1.创建对象
```
<!-- 配置对象 -->
<bean id="book" class="aop.Book"></bean>
<bean id="myBook" class="aop.MyBook"></bean>
```
* 2.开启aop操作
```
<!-- 开启aop自动代理 -->
<aop:aspectj-autoproxy></aop:aspectj-autoproxy>
```
* 3.在增强类上面使用注解完成aop操作
```
@Aspect
public class MyBook {
	//在方法上用注解进行增强配置
	@Before("execution(* aop.Book.*(..))")
	public void before() {
		System.out.println("before....");
	}
}
```
* 不同通知类型的注解
![](http://wx3.sinaimg.cn/large/005P8ayVgy1fh80voaasqj30e406l75u.jpg)
# jdbcTemplate
![](http://wx3.sinaimg.cn/large/005P8ayVgy1fh81w8xdpwj30g70bd0ug.jpg)
### 准备工作
导入jar包
```
spring-jdbc-4.0.6.RELEASE.jar
spring-tx-4.0.6.RELEASE.jar
mysql-connector-java-5.1.17-bin.jar
```
创建数据库和表
### 添加操作(删除,修改类似)
```
@Test
public void add() {
	//设置数据库信息
	DriverManagerDataSource dataSource = new DriverManagerDataSource();
	dataSource.setDriverClassName("com.mysql.jdbc.Driver");
	dataSource.setUrl("jdbc:mysql:///spring_day03");
	dataSource.setUsername("root");
	dataSource.setPassword("0000");
	
	//创建jdbcTemplate对象，设置数据源
	JdbcTemplate jdbcTemplate = new JdbcTemplate(dataSource);
	
	//调用jdbcTemplate对象里面的方法实现操作
	String sql = "insert into user values(?,?)";
	int rows = jdbcTemplate.update(sql,"tom","2501");
	System.out.println(rows);
}
```
### 查询操作
* 1.和dbutils的比较
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fh81w9k3enj30j909b403.jpg)
* 2.返回某个值
```
@Test
public void query() {
	//设置数据库信息
	DriverManagerDataSource dataSource = new DriverManagerDataSource();
	dataSource.setDriverClassName("com.mysql.jdbc.Driver");
	dataSource.setUrl("jdbc:mysql:///spring_day03");
	dataSource.setUsername("root");
	dataSource.setPassword("0000");
	
	//创建jdbcTemplate对象
	JdbcTemplate jdbcTemplate = new JdbcTemplate(dataSource);
	
	//调用方法
	String sql = "select count(*) from user";
	int rows = jdbcTemplate.queryForObject(sql, Integer.class);
	System.out.println(rows);
}
```
* 3.返回对象
```
@Test
public void testObject() {
	//设置数据库信息
	DriverManagerDataSource dataSource = new DriverManagerDataSource();
	dataSource.setDriverClassName("com.mysql.jdbc.Driver");
	dataSource.setUrl("jdbc:mysql:///spring_day03");
	dataSource.setUsername("root");
	dataSource.setPassword("0000");
			
	//创建jdbcTemplate对象
	JdbcTemplate jdbcTemplate = new JdbcTemplate(dataSource);
	
	//写sql语句，根据username查询
	String sql = "select * from user where username=?";
	//返回如果是list<User>的话，MyRowMapper()里面不用写循环
	User user = jdbcTemplate.queryForObject(sql, new MyRowMapper(), "lucy");
	System.out.println(user);
}
class MyRowMapper implements RowMapper<User> {
	@Override
	public User mapRow(ResultSet rs, int num) throws SQLException {
		//1.从结果集合得到数据
		String username = rs.getString("username");
		String password = rs.getString("password");
		
		//2.把得到的数据封装到对象里面
		User user = new User();
		user.setUsername(username);
		user.setPassword(password);
		
		return user;
	}
}
```
# spring配置c3p0连接池,dao使用jdbcTemplate
* 1.导入jar包
```
c3p0-0.9.2-pre1.jar
mchange-commons-java-0.2.7.jar
```
* 2.创建spring配置文件，配置连接池
```
<!-- 配置c3p0连接池 -->
<bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
	<!-- 注入属性值 -->
	<property name="driverClass" value="com.mysql.jdbc.Driver"></property>
	<property name="jdbcUrl" value="jdbc:mysql:///spring_day03"></property>
	<property name="user" value="root"></property>
	<property name="password" value="0000"></property>
</bean>
<!-- 创建service和dao对象，在service中注入dao对象 -->
<bean id="userService" class="c3p0.UserService">
	<!-- 注入dao对象 -->
	<property name="userDao" ref="userDao"></property>
</bean>
<bean id="userDao" class="c3p0.UserDao">
	<!-- 注入jdbcTemplate对象 -->
	<property name="jdbcTemplate" ref="jdbcTemplate"></property>
</bean>
<!-- 创建jdbcTemplate对象 -->
<bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
	<!-- 把dataSource传递到模板对象 -->
	<property name="dataSource" ref="dataSource"></property>
</bean>
```
* 3.UserService类
```
public class UserService {
	
	private UserDao userDao;

	public void setUserDao(UserDao userDao) {
		this.userDao = userDao;
	}
	
	public void add() {
		userDao.add();
	}
}
```
* 4.UserDao类
```
public class UserDao {
	//得到JdbcTemplate对象
	private JdbcTemplate jdbcTemplate;
	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}

	public void add() {
		String sql = "insert into user value(?,?)";
		jdbcTemplate.update(sql,"yasuo","4");
	}
}
```
# spring事务
1.编程式事务管理（以后再学）
2.声明式事务管理
xml配置文件实现
注解实现
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fh825xsiz5j30aq06f3ze.jpg)
![](http://wx1.sinaimg.cn/large/005P8ayVgy1fh825yneruj30j90cuad4.jpg)
### xml配置文件实现
OrdersDao类
```
public class OrdersDao {
	//注入jdbcTemplate
	private JdbcTemplate jdbcTemplate;
	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}
	
	public void lessMoney() {
		String sql = "update account set salary=salary-? where username=?";
		jdbcTemplate.update(sql,1000,"小王");
	}
	
	public void moreMoney() {
		String sql = "update account set salary=salary+? where username=?";
		jdbcTemplate.update(sql,1000,"小马");
	}
}
```
OrdersService类
```
public class OrdersService {
	//注入dao
	private OrdersDao ordersDao;
	public void setOrdersDao(OrdersDao ordersDao) {
		this.ordersDao = ordersDao;
	}
	
	public void accountMoney() {
		ordersDao.lessMoney();
		ordersDao.moreMoney();
	}
}
```
配置文件
```
	<!-- 配置c3p0连接池 -->
	<bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
		<!-- 注入属性值 -->
		<property name="driverClass" value="com.mysql.jdbc.Driver"></property>
		<property name="jdbcUrl" value="jdbc:mysql:///spring_day03"></property>
		<property name="user" value="root"></property>
		<property name="password" value="0000"></property>
	</bean>
	
	<!-- 1.配置事务管理器 -->
	<bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
		<!-- 注入dataSource -->
		<property name="dataSource" ref="dataSource"></property>
	</bean>
	<!-- 2.配置事务增强 -->
	<tx:advice id="txadvice" transaction-manager="transactionManager">
		<!-- 做事务操作 -->
		<tx:attributes>
			<!-- 设置进行事务操作的方法匹配规则 -->
			<tx:method name="account*"/>
		</tx:attributes>
	</tx:advice>
	<!-- 3.配置切面 -->
	<aop:config>
		<!-- 切入点 -->
		<aop:pointcut expression="execution(* service.OrdersService.*(..))" id="pointcut1"/>
		<!-- 切面 -->
		<aop:advisor advice-ref="txadvice" pointcut-ref="pointcut1"/>
	</aop:config>
	
	<bean id="ordersService" class="service.OrdersService">
		<property name="ordersDao" ref="ordersDao"></property>
	</bean>
	<bean id="ordersDao" class="dao.OrdersDao">
		<property name="jdbcTemplate" ref="jdbcTemplate"></property>
	</bean>
	
	<bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
		<property name="dataSource" ref="dataSource"></property>
	</bean>
```
### 注解实现
```
<!-- 1.配置事务管理器 -->
<bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
	<!-- 注入dataSource -->
	<property name="dataSource" ref="dataSource"></property>
</bean>
<!-- 2.开始注解事务 -->
<tx:annotation-driven transaction-manager="transactionManager"/>
```
```
@Transactional
public class OrdersService {
	//注入dao
	private OrdersDao ordersDao;
	public void setOrdersDao(OrdersDao ordersDao) {
		this.ordersDao = ordersDao;
	}
	
	public void accountMoney() {
		ordersDao.lessMoney();
		ordersDao.moreMoney();
	}
}
```



