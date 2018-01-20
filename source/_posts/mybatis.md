---
title: mybatis
toc: true
date: 2017-09-04 14:17:02
tags:
- Java基础
---
# mybatis简介
<!--more-->
mybatis是一个持久层的框架，是apache下的顶级项目。
mybatis托管到googlecode下，之后托管到github。
mybatis让程序将主要精力放到sql上，通过mybatis提供的映射方式，半自动化生成sql语句。
mybatis可以将向preparedStatement中的输入参数自动进行输入映射，将查询结果集映射成java对象(输出映射)。
# 入门程序
全局配置文件SqlMapConfig.xml
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
"http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
	<!-- 和spring整合后environments配置将废除 -->
	<environments default="development">
		<environment id="development">
			<transactionManager type="JDBC">
			</transactionManager>
			<!-- 数据库连接池 -->
			<dataSource type="POOLED">
				<property name="driver" value="com.mysql.jdbc.Driver"/>
				<property name="url" value="jdbc:mysql:///mybatis01"/>
				<property name="username" value="root"/>
				<property name="password" value="0000"/>
			</dataSource>
		</environment>
	</environments>
	<mappers>
		<mapper resource="sqlmap/User.xml"/>
	</mappers>
</configuration>
```
User.xml
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
"http://mybatis.org/dtd/mybatis-3-mapper.dtd">

<mapper namespace="test">
	<!-- 通过ID查找 -->
	<select id="findUserById" parameterType="int" resultType="mybatis.po.User">
		SELECT * FROM USER WHERE id=#{id}
	</select>
	<!-- 通过Name查找 -->
	<select id="findUserByName" parameterType="String" resultType="mybatis.po.User">
		SELECT * FROM USER WHERE username Like '%${value}%'
	</select>
	<!-- 插入用户 -->
	<insert id="insertUser" parameterType="mybatis.po.User">
		<!-- 如果主键自增，用这个方法可以返回主键 -->
		<selectKey keyProperty="id" order="AFTER" resultType="int">
			select LAST_INSERT_ID()
		</selectKey>
		insert into user(id,username,birthday,sex,address) value(#{id},#{username},#{birthday},#{sex},#{address})
	</insert>
</mapper>
```
User.java的PO省略
测试类
```
public class MybatisFirst {
	//根据ID查询用户信息
	@Test	
	public void findUserByIdTest() throws IOException {
		//得到配置文件流
		String resource = "SqlMapConfig.xml";
		InputStream inputStream = Resources.getResourceAsStream(resource);
		//创建会话工厂，传入mybatis配置文件信息
		SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
		//通过工厂得到SqlSession
		SqlSession sqlSession = sqlSessionFactory.openSession();
		
		User user = sqlSession.selectOne("test.findUserById", 1);
		
		System.out.println(user);
		
		sqlSession.close();
	}
	//根据NAME查询用户信息
	@Test	
	public void findUserByNameTest() throws IOException {
		//得到配置文件流
		String resource = "SqlMapConfig.xml";
		InputStream inputStream = Resources.getResourceAsStream(resource);
		//创建会话工厂，传入mybatis配置文件信息
		SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
		//通过工厂得到SqlSession
		SqlSession sqlSession = sqlSessionFactory.openSession();
		
		List<User> list = sqlSession.selectList("test.findUserByName", "小");
		
		System.out.println(list);
		
		sqlSession.close();
	}
	//添加用户信息
	@Test	
	public void insertUserTest() throws IOException {
		//得到配置文件流
		String resource = "SqlMapConfig.xml";
		InputStream inputStream = Resources.getResourceAsStream(resource);
		//创建会话工厂，传入mybatis配置文件信息
		SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
		//通过工厂得到SqlSession
		SqlSession sqlSession = sqlSessionFactory.openSession();
		
		User user = new User();
		user.setUsername("王小军");
		user.setBirthday(new Date());
		user.setSex("1");
		user.setAddress("河南");
		user.setId(2);
		
		sqlSession.selectOne("test.insertUser", user);
		
		sqlSession.commit();
		
		sqlSession.close();
	}
}
```
# mapper代理开发
开发规范
1.在mapper.xml中namespace等于mapper接口地址
2.mapper.java接口中的方法名和mapper.xml中statement的id一致
3.mapper.java接口中的方法输入参数类型和mapper.xml中statement的parameterType指定的类型一致
4.mapper.java接口中的方法返回值类型和mapper.xml中statement的resultType指定的类型一致
UserMapper.xml
```
<mapper namespace="mybatis.mapper.UserMapper">
	<select id="findUserById" parameterType="int" resultType="mybatis.po.User">
		SELECT * FROM USER WHERE id=#{id}
	</select>
</mapper>
```
UserMapper.java接口
```
public interface UserMapper {
	//根据id查询
	public User findUserById(int id) throws Exception;
}
```
测试类
```
public class UserMapperTest {
	
	private SqlSessionFactory sqlSessionFactory;
	
	@Before
	public void serUp() throws Exception {
		//得到配置文件流
		String resource = "SqlMapConfig.xml";
		InputStream inputStream = Resources.getResourceAsStream(resource);
		
		//创建会话工厂,传入mybatis的配置文件信息
		sqlSessionFactory = new SqlSessionFactoryBuilder()
				.build(inputStream);
	}
	
	@Test
	public void testFindUserById() throws Exception {
		
		SqlSession sqlSession = sqlSessionFactory.openSession();
		
		//创建UserMapper对象
		UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
		
		//调用userMapper的方法
		User user = userMapper.findUserById(1);
		System.out.println(user);
	}
}
```
# 别名
```
<!-- 别名定义 -->
<typeAliases>
	<!-- 单个别名定义 -->
	<typeAlias type="mybatis.po.User" alias="user"/>
	<!-- 定义整个包，别名就是类名 -->
	<package name="mybatis.po"/>
</typeAliases>
```
# resultMap
数据库查出的列名和pojo属性不一致的时候使用
```
<!-- resultMap的使用 -->
<resultMap type="user" id="userResultMap">
	<!-- 表示结果集中的唯一标识 -->
	<id column="id_" property="id"/>
	<!-- 表示普通属性 -->
	<result column="username_" property="username"/>
</resultMap>
```
# sql片段
where和if标签的使用
![](http://wx4.sinaimg.cn/mw690/005P8ayVly1fjb4obs6qkj30iu0a5abp.jpg)
sql片段
![](http://wx4.sinaimg.cn/mw690/005P8ayVly1fjb4oc7m2sj30ie06jdgu.jpg)
引用sql片段
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjb4ocmi79j30ha014gls.jpg)
foreach标签
![](http://wx1.sinaimg.cn/mw690/005P8ayVly1fjb4od0hrwj30jw08djsl.jpg)
# 一对一和一对多
association标签,collection标签，分别是一对一，一对多的关系
![](http://wx3.sinaimg.cn/mw690/005P8ayVly1fjkatqgcx7j30jd05bt92.jpg)
![](http://wx1.sinaimg.cn/mw690/005P8ayVly1fjkatqueo7j30jj035t8w.jpg)
# 延迟加载
association和collection标签里的select属性来指定延迟加载的statement的id
设置打开延迟加载
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjkb7fb3j8j30ik0aw0vc.jpg)
# 一级缓存和二级缓存
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjnl3onkquj30jq0aumxv.jpg)
![](http://wx1.sinaimg.cn/mw690/005P8ayVly1fjnl3p4z9xj30ki0bojsr.jpg)
![](http://wx4.sinaimg.cn/mw690/005P8ayVly1fjnl3pn6muj30jk054mxn.jpg)
![](http://wx3.sinaimg.cn/mw690/005P8ayVly1fjnl3qb8yxj30kh0auaav.jpg)
二级缓存需要实体类实现序列化
### mybatis和ehcache整合
mybatis无法实现分布式缓存，需要和其它分布式缓存框架进行整合。
mybatis提供了一个cache接口，如果要实现自己的缓存逻辑，实现cache接口开发即可。
首先要加入ehcache相关的jar包
在xml中配置
![](http://wx1.sinaimg.cn/mw690/005P8ayVly1fjoyjogf1fj30e9038t98.jpg)
引入ehcache的缓存配置文件
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjoyjp5nuuj30fu07j406.jpg)
# mybatis和spring整合
![](http://wx3.sinaimg.cn/mw690/005P8ayVly1fjoz7dffthj30jh03zglu.jpg)
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjoz7eabhmj30ii0a6410.jpg)
![](http://wx4.sinaimg.cn/mw690/005P8ayVly1fjoz7dva56j30k404et9o.jpg)
mapper代理开发的配置如下，dao开发省略
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjoz7er86ij30jr04j0tr.jpg)
![](http://wx2.sinaimg.cn/mw690/005P8ayVly1fjoz7fuvudj30is06nq4b.jpg)
# 逆向工程
先不学




