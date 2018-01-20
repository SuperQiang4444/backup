---
title: struts2_02
toc: true
date: 2017-06-12 11:11:49
tags:
- Java基础
---
数据操作
<!--more-->
```
<!-- 全局结果页面配置 -->
<global-results>
	<result name="success">/hello.jsp</result>
</global-results>
```
# result标签里的type属性
默认为转发dispatcher
其它还有
重定向redirect
chain:重定向到action(因为缓存一般不用)
redirectAction:重定向到action
# 获取表单数据
使用ActionContext获取
```
//获取ActionContext对象
ActionContext context = ActionContext.getContext();
		
Map<String, Object> map = context.getParameters();
		
Set<String> keys = map.keySet();
for (String key : keys) {
		Object[] obj = (Object[]) map.get(key);
		System.out.println(Arrays.toString(obj));
	}
```
使用ServletActionContext获取
```
//使用ServletActionContext获取表单数据
HttpServletRequest request = ServletActionContext.getRequest();
		
String username = request.getParameter("username");
String password = request.getParameter("password");
String address = request.getParameter("address");
		
System.out.println(username+":"+password+":"+address);
```
使用接口注入获取
```
public class Form3DemoAction extends ActionSupport implements ServletRequestAware{
	//接口注入获取表单数据
	private HttpServletRequest request;
	@Override
	public void setServletRequest(HttpServletRequest request) {
		this.request = request;
	}
	
	@Override
	public String execute() throws Exception {
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String address = request.getParameter("address");
		System.out.println(username+":"+password+":"+address);
		
		return NONE;
	}
}
```
# action操作域对象
```
//action操作三个域对象
//1 request域
HttpServletRequest request = ServletActionContext.getRequest();
request.setAttribute("req", "reqValue");

//2 session域
HttpSession session = request.getSession();
session.setAttribute("sess", "sessValue");

//3 ServletContext域
ServletContext context = ServletActionContext.getServletContext();
context.setAttribute("contextname", "contextValue");
```
# 属性封装
```
public class DataDemo1Action extends ActionSupport{
	//属性封装
	private String username;
	private String password;
	private String address;
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
	
	@Override
	public String execute() throws Exception {
		System.out.println(username+":"+password+":"+address);
		return NONE;
	}
}
```
# 模型驱动封装
```
public class DataDemo2Action extends ActionSupport implements ModelDriven<User> {
	//模型驱动封装
	private User user = new User();
	@Override
	public User getModel() {
		return user;
	}
	
	@Override
	public String execute() throws Exception {
		System.out.println(user);
		return NONE;
	}
}
```
# 表达式封装
```
public class DataDemo3Action extends ActionSupport {
	//表达式封装
	private User user;

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}
	
	@Override
	public String execute() throws Exception {
		System.out.println(user);
		return NONE;
	}
}
```
表单name属性写法
```
name="user.username"
name="user.password"
name="user.address"
```
# 封装到list，map
list
```
public class ListAction extends ActionSupport {
	private List<User> list;

	public List<User> getList() {
		return list;
	}

	public void setList(List<User> list) {
		this.list = list;
	}
	
	@Override
	public String execute() throws Exception {
		System.out.println(list);
		return NONE;
	}
}
```
```
username:<input type="text" name="list[0].username"/>
<br/>
password:<input type="text" name="list[0].password" />
<br/>
address:<input type="text" name="list[0].address" />
```
Map
```
public class MapAction extends ActionSupport{
	private Map<String, User> map;
	
	public Map<String, User> getMap() {
		return map;
	}
	
	public void setMap(Map<String, User> map) {
		this.map = map;
	}
	
	@Override
	public String execute() throws Exception {
		System.out.println(map);		
		return NONE;
	}
}
```
```
username:<input type="text" name="map['one'].username"/>
<br/>
password:<input type="text" name="map['one'].password" />
<br/>
address:<input type="text" name="map['one'].address" />
```
