<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" errorPage="error.jsp"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
                        "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>exception object test</title>
</head>
<body>
	<%
		int a = 3;
		int b = 0;
	%>
	输出结果为：<%=(a / b)%><!--此处会产生异常  -->
</body>
</html>