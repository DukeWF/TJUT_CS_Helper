<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
<head>
<title>pageContext</title>
</head>
<body>
	<%
		//获取request对象
		HttpServletRequest req = (HttpServletRequest) pageContext.getRequest();
		//设置page范围内属性
		pageContext.setAttribute("str", "Java",pageContext.PAGE_SCOPE);
		//设置request范围内属性		
		req.setAttribute("str", "Java Web");
		//获得的page范围属性
		String str1 = (String)pageContext.getAttribute("str",pageContext.PAGE_SCOPE);
		//获得的request范围属性
		String str2 = (String)pageContext.getAttribute("str",pageContext.REQUEST_SCOPE);
	%>
	<%="page范围："+str1 %><br />
	<%="request范围："+str2 %><br />
</body>
</html>
