package cn.itcast.chapter08.filter;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class MyServlet extends HttpServlet {
	public void doGet(HttpServletRequest request,  
     HttpServletResponse response)
			throws ServletException, IOException {
		response.getWriter().write("Hello MyServlet ");
	}
	public void doPost(HttpServletRequest request, 
                           HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}
