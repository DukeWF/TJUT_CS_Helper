package cn.itcast.chapter04.response; 
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class LoginServlet extends HttpServlet {
	public void doGet(HttpServletRequest request,
        HttpServletResponse response)throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		// 用HttpServletRequest对象的getParameter()方法获取用户名和密码
			String username = request.getParameter("username");
			String password = request.getParameter("password");
			// 假设用户名和密码分别为：itcast和123
			if (("itcast").equals(username) &&("123").equals(password)) {
				// 如果用户名和密码正确，重定向到 welcome.html
	              response.sendRedirect("/chapter04/welcome.html");
			} else {
				// 如果用户名和密码错误，重定向到login.html
				response.sendRedirect("/chapter04/login.html");
			}
		}
		public void doPost(HttpServletRequest request, 
	        HttpServletResponse response)throws ServletException, IOException {
			doGet(request, response);
		}
	}
