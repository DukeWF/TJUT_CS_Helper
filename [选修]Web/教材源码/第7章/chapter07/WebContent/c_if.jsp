<%@ page language="java" contentType="text/html; charset=utf-8"
pageEncoding="utf-8" import="java.util.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body>
	<c:set value="1" var="visitCount" property="visitCount" />
	<c:if test="${visitCount==1 }">
		This is you first visit. Welcome to the site!
	</c:if>
</body>
</html>
