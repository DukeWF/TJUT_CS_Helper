<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
                        "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP声明语句</title>
</head>
<%!
	int a = 1, b = 2; //定义两个变量a,b
%>
<%!
   public String print() { //定义print方法
	    String str = "itcast"; //方法内定义的变量str
		return str;
	}
%>
<body>

	<%
 		out.println(a + b); //输出两个变量的和 -->
	%> 
 	<br /> 
	<%
		out.println(print());//调用print()方法，输出其返回值 
	%> 
	<br /> 
	<%=a+b %><br />
	<%=print() %>
</body>
</html>