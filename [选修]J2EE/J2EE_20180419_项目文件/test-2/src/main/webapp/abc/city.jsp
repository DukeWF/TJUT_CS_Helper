<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.*, edu.tjut.cs.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<table>
		<thead>
			<tr>
				<th>城市</th>
				<th>国家</th>
				<th>省（州）</th>
			</tr>
		</thead>

		<c:forEach items="${allcities }" var="city" varStatus="status">
			<c:choose>
				<c:when test="${status.index % 2 == 0}">
					<tr style="background-color: olive;">
						<td style="border: 1px solid #000;">${city.name }</td>
						<td style="border: 1px solid #000;">${city.country }</td>
						<td style="border: 1px solid #000;">${city.state }</td>
					</tr>
				</c:when>
				<c:when test="${status.index % 2 == 1}">
					<tr>
						<td style="border: 1px solid #000;">${city.name }</td>
						<td style="border: 1px solid #000;">${city.country }</td>
						<td style="border: 1px solid #000;">${city.state }</td>
					</tr>
				</c:when>
			</c:choose>
		</c:forEach>
	</table>
</body>
</html>