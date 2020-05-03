package cn.itcast.chapter04.request;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class RequestLineServlet extends HttpServlet {
	public void doGet(HttpServletRequest request,
        HttpServletResponse response)throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();
		// 获取请求行的相关信息
		out.println("getMethod : " + request.getMethod() + "<br>");
		out.println("getRequestURI : " + request.getRequestURI() + "<br>");
		out.println("getQueryString:"+request.getQueryString() + "<br>");
		out.println("getProtocol : " + request.getProtocol() + "<br>");
		out.println("getContextPath:"+request.getContextPath() + "<br>");
		out.println("getPathInfo : " + request.getPathInfo() + "<br>");
		out.println("getPathTranslated : "
                      + request.getPathTranslated() + "<br>");
		out.println("getServletPath:"+request.getServletPath() + "<br>");
		out.println("getRemoteAddr : " + request.getRemoteAddr() + "<br>");
		out.println("getRemoteHost : " + request.getRemoteHost() + "<br>");
		out.println("getRemotePort : " + request.getRemotePort() + "<br>");
		out.println("getLocalAddr : " + request.getLocalAddr() + "<br>");
		out.println("getLocalName : " + request.getLocalName() + "<br>");
		out.println("getLocalPort : " + request.getLocalPort() + "<br>");
		out.println("getServerName : " + request.getServerName() + "<br>");
		out.println("getServerPort : " + request.getServerPort() + "<br>");
		out.println("getScheme : " + request.getScheme() + "<br>");
		out.println("getRequestURL : " + request.getRequestURL() + "<br>");
	}
	public void doPost(HttpServletRequest request, 
        HttpServletResponse response)throws ServletException, IOException {
		doGet(request, response);
	}
}
