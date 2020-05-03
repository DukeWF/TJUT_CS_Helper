<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<html>
<head></head>
<body>
	请求URI为：${pageContext.request.requestURI} <br />
	Content-Type响应头：${pageContext.response.contentType} <br /> 
	服务器信息为：${pageContext.servletContext.serverInfo} <br /> 
	Servlet注册名为：${pageContext.servletConfig.servletName} <br />
</body>
</html>
