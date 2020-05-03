<%@ page language="java" contentType="text/html; charset=utf-8"
pageEncoding="utf-8" import="java.util.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body>
	<c:choose>
	   <c:when test="${empty param.username}">
 		   unKnown user.
 	   </c:when>
	   <c:when test="${param.username=='itcast'}">
 		   ${ param.username} is manager.
 	   </c:when>
	   <c:otherwise>
  		   ${ param.username} is employee.
 	   </c:otherwise>
	</c:choose>
</body>
</html>
