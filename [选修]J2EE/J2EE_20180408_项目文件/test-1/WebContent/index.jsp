<%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%><%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form action="/test-1/aaa" method="post">
		<form:select name="a_country" path="allcountries">
			<form:options items="${allcountries }"/>
		</form:select>
		<input type="submit">
	</form>
</body>
</html>