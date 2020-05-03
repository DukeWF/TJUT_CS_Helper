package cn.itcast.chapter04.request;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class IncludingServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, 
        HttpServletResponse response)throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();
		RequestDispatcher rd = request
					.getRequestDispatcher("/IncludedServlet?p1=abc");
			out.println("before including" + "<br>");
			rd.include(request, response);
			out.println("after including" + "<br>");
		}
		public void doPost(HttpServletRequest request,
	        HttpServletResponse response)throws ServletException, IOException {
			doGet(request, response);
		}
	}
