---
title: 分IP统计访问次数案例
date: 2017-04-19 16:26:07
tags:
- Web
- demo
toc: true
---
# 原理
通过过滤器检查全站信息，将IP和访问次数放进一个Map中，这个Map在Listener的初始化方法中创建并放入ServletContext域中。
<!--more-->
# Listener
```
@WebListener("/*")
public class Alistener implements ServletContextListener {

    public void contextDestroyed(ServletContextEvent arg0)  { 
   
    }

    public void contextInitialized(ServletContextEvent arg0)  { 
     	//创建Map放进ServletContext域
     	Map<String, Integer> map = new LinkedHashMap<String, Integer>();
    	ServletContext application = arg0.getServletContext();
    	application.setAttribute("map", map);
    }
}
```
# Filter
```
@WebFilter("/*")
public class AFilter implements Filter {
	private  FilterConfig config;
	
	public void destroy() {
		
	}
	
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
		ServletContext app = config.getServletContext();
		Map<String, Integer> map = (Map<String, Integer>) app.getAttribute("map");
		
		String ip = request.getRemoteAddr();
		
		if(map.containsKey(ip)){//ip存在
			int cnt = map.get(ip);
			map.put(ip, cnt+1);
		}else{//ip不存在
			map.put(ip, 1);
		}
		app.setAttribute("map", map);
		chain.doFilter(request, response);
	}

	public void init(FilterConfig fConfig) throws ServletException {
		this.config = fConfig;
	}
}
```
# 结果输出页面
```
<table align="center" width="60%" border="1">
	<tr>
		<th>IP</th>
		<th>count</th>
	</tr>
<s:forEach items="${applicationScope.map }" var="entry">
	<tr>
		<td>${entry.key }</td>
		<td>${entry.value }</td>
	</tr>
</s:forEach>
</table>
```