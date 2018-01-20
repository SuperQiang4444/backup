---
title: JDBC学习笔记4
date: 2017-04-19 10:35:57
tags:
- Web
- 数据库
toc: true
---
方便操作的工具类
BaseServlet
JdbcUtils
<!--more-->
# BaseServlet
用1个Servlet来实现多个方法，用更简便的方法实现重定向和转发。
用法:以后写Servlet只要继承BaseServlet即可。
```
//一个servlet实现多个方法
public class BaseServlet extends HttpServlet {
	public void service(HttpServletRequest req, HttpServletResponse resp) 
			throws ServletException, IOException{
		req.setCharacterEncoding("utf-8");
		resp.setContentType("text/html;charset=utf-8");


		String methodName = req.getParameter("method");
		
		if(methodName == null || methodName.trim().isEmpty()) {
			throw new RuntimeException("您没有传递method参数!无法确定您想要调用的方法!");
		}
		
		Class c = this.getClass();
		Method method = null;
		try{
			method = c.getMethod(methodName,
					HttpServletRequest.class, HttpServletResponse.class);
		}catch(Exception e){
			System.out.println("您调用的方法" + methodName + ",它不存在!");
		}
		
		//调用method表示的方法
		try{
			String result = (String) method.invoke(this, req, resp);
			//获取返回的字符串,它表示转发或者重定向。r:/user/login.jsp
			
			//返回值为空,直接返回。
			if(result == null || result.trim().isEmpty()) {
				return;
			}
			
			if(result.contains(":")) {
				//使用冒号分割字符串
				int index = result.indexOf(":");
				String s = result.substring(0, index);
				String path = result.substring(index+1);
				if(s.equalsIgnoreCase("r")) {//表示重定向
					resp.sendRedirect(req.getContextPath() + path);
				}else if(s.equalsIgnoreCase("f")) {//表示转发
					req.getRequestDispatcher(path).forward(req, resp);
				}else{
					throw new RuntimeException("您指定的操作:" + s + "当前版本不支持");
				}
			} else {//默认为转发
				req.getRequestDispatcher(result).forward(req, resp);
			}
		}catch(Exception e){
			System.out.println("您调用的方法" + methodName + ",它内部抛出了异常!");
			throw new RuntimeException(e);
		}
		
	}
}
```
# JdbcUtils
使用c3p0连接池
支持事务
支持多线程
```
public class JdbcUtils {
	//配置文件为默认配置。必须给出c3p0-config.xml
	private static ComboPooledDataSource dataSource = new ComboPooledDataSource();
	
	//它是事务专用连接
	private static ThreadLocal<java.sql.Connection> tl = new ThreadLocal<java.sql.Connection>();
	
	
	//返回连接
	public static java.sql.Connection getConnection() throws SQLException{
		java.sql.Connection connection = tl.get();
		if(connection != null) return connection;
		return dataSource.getConnection();
	}
	
	//返回连接池对象
	public static ComboPooledDataSource getDataSource(){
		return dataSource;
	}
	
	//开启事务
	public static void beginTransaction() throws SQLException{
		java.sql.Connection connection = tl.get();
		if(connection != null) throw new SQLException("已经开启事务");
		connection = getConnection();
		connection.setAutoCommit(false);
		tl.set(connection);
	}
	
	//提交事务
	public static void commitTransaction() throws SQLException{
		java.sql.Connection connection = tl.get();
		if(connection == null) throw new SQLException("还没有开启事务");
		connection.commit();
		connection.close();
		tl.remove();
	}
	
	//回滚事务
	public static void rollbackTransaction() throws SQLException{
		java.sql.Connection connection = tl.get();
		if(connection == null) throw new SQLException("还没有开启事务");
		connection.rollback();
		connection.close();
		tl.remove();
	}
	
	//释放连接
	public static void releaseConnection(java.sql.Connection connection1) throws SQLException{
		java.sql.Connection connection = tl.get();
		if(connection == null) connection1.close();
		if(connection != connection1) connection1.close();
		
	}
	
}
```
# TxQueryRunner
继承QueryRunner
自己处理连接问题(通过JdbcUtils)
```
public class TxQueryRunner extends QueryRunner{

	@Override
	public int[] batch(String sql, Object[][] params) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		int[] result = super.batch(connection,sql, params);
		JdbcUtils.releaseConnection(connection);
		return result;
	}

	@Override
	public <T> T query(String sql, Object param, ResultSetHandler<T> rsh) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		T result = super.query(connection,sql, param,rsh);
		JdbcUtils.releaseConnection(connection);
		return result;	
		}

	@Override
	public <T> T query(String sql, Object[] params, ResultSetHandler<T> rsh) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		T result = super.query(connection,sql, params,rsh);
		JdbcUtils.releaseConnection(connection);
		return result;	
	}

	@Override
	public <T> T query(String sql, ResultSetHandler<T> rsh, Object... params) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		T result = super.query(connection,sql, rsh,params);
		JdbcUtils.releaseConnection(connection);
		return result;	
	}

	@Override
	public <T> T query(String sql, ResultSetHandler<T> rsh) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		T result = super.query(connection,sql, rsh);
		JdbcUtils.releaseConnection(connection);
		return result;	
	}

	@Override
	public int update(String sql, Object... params) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		int result = super.update(connection,sql,params);
		JdbcUtils.releaseConnection(connection);
		return result;	
	}

	@Override
	public int update(String sql, Object param) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		int result = super.update(connection,sql,param);
		JdbcUtils.releaseConnection(connection);
		return result;	
	}

	@Override
	public int update(String sql) throws SQLException {
		Connection connection = JdbcUtils.getConnection();
		int result = super.update(connection,sql);
		JdbcUtils.releaseConnection(connection);
		return result;	
	}
	
}
```