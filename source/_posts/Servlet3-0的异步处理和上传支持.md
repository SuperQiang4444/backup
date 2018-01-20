---
title: Servlet3.0的异步处理和上传支持
date: 2017-05-08 15:59:28
tags:
- Web
toc: true
---
Servlet3.0
异步处理和上传支持
<!--more-->
# 异步处理
![异步处理](http://wx4.sinaimg.cn/large/005P8ayVgy1ffe0j2iv48j30mh08y0xl.jpg)
```
//设置支持异步
@WebServlet(urlPatterns="/AServlet", asyncSupported=true)
public class AServlet extends HttpServlet {

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//必须设置编码问题
		response.setContentType("text/html;charset=utf-8");
		
		//IE必须大于512b才有异步效果
		for(int i = 0; i <= 512; i++) {
			response.getWriter().print("a");
		}
		response.getWriter().flush();
		
		//得到上下文异步
		AsyncContext aContext = request.startAsync(request, response);
		
		//开始测试
		aContext.start(new Runnable() {
			public void run() {
				try {
					response.getWriter().print("现在马上开始:<br/>");
					response.getWriter().flush();
					Thread.sleep(3000);
					for(char c = 'A'; c <= 'Z'; c++) {
						response.getWriter().print(c+"");
						response.getWriter().flush();
						Thread.sleep(250);
					}
				} catch (IOException | InterruptedException e) {
					
				}
				//通知线程已经结束
				aContext.complete();
			}
		});
	}
}
```
# 上传支持
![上传支持](http://wx1.sinaimg.cn/large/005P8ayVgy1ffe0j3i4l8j30ir09076s.jpg)
### Servlet代码
```
@WebServlet(urlPatterns="/BServlet")
@MultipartConfig//支持3.0上传部件
public class BServlet extends HttpServlet {
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		//获取文本
		String username = request.getParameter("username");
		//获取文件
		Part part = request.getPart("resume");
		//测试信息
		System.out.println(part.getContentType());
		System.out.println(part.getSize());
		System.out.println(part.getName());
		System.out.println(part.getHeader("Content-Disposition"));
		//保存文件
		part.write("D:/1234.jpg");
	}
}
```
### 前端表单
```
<h1>注册</h1>
<form action="<c:url value='/BServlet'/>" method="post" enctype="multipart/form-data">
用户名:<input type="text" name="username"/> <br/>
简历:<input type="file" name="resume" />
<input type="submit" value="注册" />
</form>
```
