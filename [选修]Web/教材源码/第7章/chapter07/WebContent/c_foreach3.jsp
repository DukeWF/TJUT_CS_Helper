<%@ page language="java" contentType="text/html; charset=utf-8"
pageEncoding="utf-8" import="java.util.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body style="text-align: center;">
	<%
		List userList = new ArrayList();
		userList.add("Tom");
		userList.add("Make");
		userList.add("Lina");
	%>
	<table border="1">
		<tr>
			<td>序号</td>
			<td>索引</td>
			<td>是否为第一个元素</td>
			<td>是否为最后一个元素</td>
			<td>元素的值</td>
		</tr>
		<c:forEach var="name" items="<%=userList%>" varStatus="status">
			<tr>
				<td>${status.count}</td>
				<td>${status.index}</td>
				<td>${status.first}</td>
				<td>${status.last}</td>
				<td>${name}</td>
			</tr>
		</c:forEach>
	</table>
</body>
</html>
