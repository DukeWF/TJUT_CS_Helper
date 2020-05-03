package cn.itcast.servlet;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class TestServlet02 extends HttpServlet {
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out = response.getWriter();
		// 获得ServletConfig对象
		ServletConfig config = this.getServletConfig();
		// 获得参数名为encoding对应的参数值
		String param = config.getInitParameter("encoding");
		out.println("encoding=" + param);
	}
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		this.doGet(request, response);
	}
}
