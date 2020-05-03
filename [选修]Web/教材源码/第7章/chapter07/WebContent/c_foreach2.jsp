<%@ page language="java" contentType="text/html; charset=utf-8"
pageEncoding="utf-8" import="java.util.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body>
  colorsList集合（指定迭代范围和步长）<br />
	<%
		List colorsList=new ArrayList();
		colorsList.add("red");
		colorsList.add("yellow");
		colorsList.add("blue");
		colorsList.add("green");
		colorsList.add("black");
	%>
	<c:forEach var="color" items="<%=colorsList%>" begin="1" 
     end="3" step="2">
		${color}&nbsp;
	</c:forEach>
</body>
</html>
