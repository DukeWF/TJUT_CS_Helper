 	package cn.itcast.firstapp.servlet;
 	import java.io.*;
 	import javax.servlet.*;
 	import javax.servlet.http.*;
 	public class RequestMethodServlet extends HttpServlet {
 		public void doGet(HttpServletRequest request, 
 	                          HttpServletResponse response)
 				throws ServletException, IOException {
 			PrintWriter out = response.getWriter();
 			out.write("this is doGet method");
 			}
 		public void doPost(HttpServletRequest request, 
 	                            HttpServletResponse response)
 				throws ServletException, IOException {
 			PrintWriter out = response.getWriter();
 			out.write("this is doPost method");
 		}
 	}
