<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@page import="java.net.URLEncoder"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
                            "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>文件下载</title>
</head>
<body>
<!-- 	<a href="/chapter12/DownloadServlet?filename=1.jpg">文件下载 </a> -->
	    <a href="/chapter12/DownloadServlet?filename=<%=URLEncoder.encode("风景.jpg", "utf-8")%>">文件下载 </a>
</body>
</html>