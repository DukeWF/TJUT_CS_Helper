package cn.itcast.chapter08.filter;
import java.io.IOException;
import javax.servlet.*;
import javax.servlet.http.*;
public class LogoutServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, 
             HttpServletResponse response)
			throws ServletException, IOException {
		// 用户注销
		request.getSession().removeAttribute("user");
		// 从客户端删除自动登录的cookie
		Cookie cookie = new Cookie("autologin", "msg");
		cookie.setPath(request.getContextPath());
		cookie.setMaxAge(0);
		response.addCookie(cookie);
		response.sendRedirect(request.getContextPath()+"/index.jsp"); 
	}
	public void doPost(HttpServletRequest request,
         HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}
