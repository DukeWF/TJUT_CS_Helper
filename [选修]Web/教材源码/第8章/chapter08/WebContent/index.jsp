<%@ page language="java" contentType="text/html; charset=utf-8"
pageEncoding="utf-8" import="java.util.*"
%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<html>
<head>
<title>显示登录的用户信息</title>
</head>
<body>
	<br />
	<center>
		<h3>欢迎光临</h3>
	</center>
	<br />
	<br />
	<c:choose>
		<c:when test="${sessionScope.user==null }">
		   <a href="${pageContext.request.contextPath }/login.jsp">用户登录</a>
		</c:when>
		<c:otherwise>
  	  欢迎你，${sessionScope.user.username }!
           <a href="${pageContext.request.contextPath }/LogoutServlet">注销</a>
		</c:otherwise>
	</c:choose>
	<hr />
</body>
</html>
