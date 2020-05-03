 	package cn.itcast.firstapp.servlet;
 	import javax.servlet.*;
 	public class HelloWorldServlet extends GenericServlet {
 		public void init(ServletConfig config) throws ServletException {
			System.out.println("init methed is called");
		}
 	public void service(ServletRequest request, ServletResponse response) throws ServletException {
 			System.out.println("Hello World");
 		}
 		public void destroy() {
 			System.out.println("destroy method is called");
 		}

 	}
