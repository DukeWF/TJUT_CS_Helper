package cn.itcast.chapter05.session.example02;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.*;
public class LogoutServlet extends HttpServlet {
public void doGet(HttpServletRequest request, 
                      HttpServletResponse response)
		throws ServletException, IOException {
     // 将Session对象中的User对象移除
		request.getSession().removeAttribute("user");
		response.sendRedirect("/chapter05/IndexServlet");
	}
	public void doPost(HttpServletRequest request, 
       HttpServletResponse response)throws ServletException, IOException {
		doGet(request, response);
	}
}
