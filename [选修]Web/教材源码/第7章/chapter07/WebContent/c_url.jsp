<%@ page language="java" contentType="text/html; charset=utf-8"
pageEncoding="utf-8" import="java.util.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body>
	使用绝对路径构造URL:<br />
	<c:url var="myURL" 
     value="http://localhost:8080/chapter07/register.jsp">
		<c:param name="username" value="张三" />
		<c:param name="country" value="中国" />
	</c:url>
	<a href="${myURL}">register.jsp</a><br />
	使用相对路径构造URL:<br />
	<c:url var="myURL" 
     value="register.jsp?username=Tom&country=France" />
	<a href="${ myURL}">register.jsp</a>
</body>
</html>
