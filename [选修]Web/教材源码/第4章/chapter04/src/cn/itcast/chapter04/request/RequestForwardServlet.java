package cn.itcast.chapter04.request;
import java.io.IOException;
import javax.servlet.*;
import javax.servlet.http.*;
public class RequestForwardServlet extends HttpServlet {
	public void doGet(HttpServletRequest request,
        HttpServletResponse response)throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		// 将数据存储到request对象中
			request.setAttribute("company", "北京传智播客教育有限公司");
			RequestDispatcher dispatcher = request
					.getRequestDispatcher("/ResultServlet");
			dispatcher.forward(request, response);
		}
		public void doPost(HttpServletRequest request,
	        HttpServletResponse response)throws ServletException, IOException {
			doGet(request, response);
		}
	}
