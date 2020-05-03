package cn.itcast.chapter04.request;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class RequestParamsServlet extends HttpServlet {
	public void doGet(HttpServletRequest request,
        HttpServletResponse response)throws ServletException, IOException {
		//设置request对象的解码方式
		request.setCharacterEncoding("utf-8");
		String name = request.getParameter("username");
		name=new String(name.getBytes("iso8859-1"),"utf-8");
		String password = request.getParameter("password");
			System.out.println("用户名:" + name);
			System.out.println("密  码:" + password);
			// 获取参数名为“hobby”的值
			String[] hobbys = request.getParameterValues("hobby");
			System.out.print("爱好:");
			for (int i = 0; i < hobbys.length; i++) {
				System.out.print(hobbys[i] + ",");
			}
		}
		public void doPost(HttpServletRequest request,
	        HttpServletResponse response)throws ServletException, IOException {
			doGet(request, response);
		}
	}
