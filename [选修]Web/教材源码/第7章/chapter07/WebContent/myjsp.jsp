<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<html>
<head></head>
<body>
    
	用户名：<%=request.getAttribute("username")%><br /> 
	密 码：<%=request.getAttribute("password")%><br />	
	<hr>
	使用EL表达式:<br />
	用户名：${username}<br />
 	密 码：${password}<br />
	
</body>
</html>
