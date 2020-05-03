package cn.itcast.chapter05.session.example02;
import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.*;
public class LoginServlet extends HttpServlet {
	/**
	 * 未添加验证码
	 */
//	public void doGet(HttpServletRequest request, 
//                          HttpServletResponse response)
//			throws ServletException, IOException {
//		response.setContentType("text/html;charset=utf-8");
//		String username = request.getParameter("username");
//		String password = request.getParameter("password");
//		PrintWriter pw = response.getWriter();
//          //假设正确的用户名 是itcast 密码是123
//		if (("itcast").equals(username) && ("123").equals(password)) {
//			User user = new User();
//			user.setUsername(username);
//			user.setPassword(password);
//			request.getSession().setAttribute("user", user);
//			response.sendRedirect("/chapter05/IndexServlet");
//		} else {
//			pw.write("用户名或密码错误，登录失败");
//		}
//	}
	/**
	 * 添加了验证码
	 */
	public void doGet(HttpServletRequest request,HttpServletResponse response)
				throws ServletException, IOException {
			response.setContentType("text/html;charset=utf-8");
			String username = request.getParameter("username");
			String password = request.getParameter("password");
			String checkCode = request.getParameter("check_code");
			String savedCode = (String) request.getSession().getAttribute(
					"check_code");
			PrintWriter pw = response.getWriter();
			if (("itcast").equals(username) && ("123").equals(password)
					&& checkCode.equals(savedCode)) {
				User user = new User();
				user.setUsername(username);
				user.setPassword(password);
				request.getSession().setAttribute("user", user);
				response.sendRedirect("/chapter05/IndexServlet");
			} else if (checkCode.equals(savedCode)) {
				pw.write("用户名或密码错误，登录失败");
			} else {
				pw.write("验证码错误");
			}
		}	
	public void doPost(HttpServletRequest request, 
                           HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}
