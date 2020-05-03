package cn.itcast.chapter08.filter;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class ForwardServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public void doGet(HttpServletRequest request,
           HttpServletResponse response)
			throws ServletException, IOException {
		request.getRequestDispatcher("/first.jsp").forward(request,
       response);
	}
	public void doPost(HttpServletRequest request, 
      HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}
