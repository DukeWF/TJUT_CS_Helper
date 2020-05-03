package cn.itcast.chapter04.request;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class IncludedServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, 
        HttpServletResponse response)throws ServletException, IOException {
		// 设置响应时使用的字符编码
	    response.setContentType("text/html;charset=utf-8");
		response.setCharacterEncoding("utf-8");
		PrintWriter out = response.getWriter();
		out.println("中国" + "<br>");
		out.println("URI:" + request.getRequestURI() + "<br>");
		out.println("QueryString:" + request.getQueryString() + "<br>");
		out.println("parameter p1:" + 
                       request.getParameter("p1") + "<br>");
	}
	public void doPost(HttpServletRequest request,
        HttpServletResponse response)throws ServletException, IOException {
		doGet(request, response);
	}
}
