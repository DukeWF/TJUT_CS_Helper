package cn.itcast.chapter04.response;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class PrintServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, 
        HttpServletResponse response)throws ServletException, IOException {
		    String data = "itcast";
		    // 获取字节输出流对象
//			OutputStream out = response.getOutputStream();
//			out.write(data.getBytes());// 输出信息
			//使用getWriter()方法发送消息体
			PrintWriter print = response.getWriter(); 
			print.write(data); // 输出信息

			
		}
		public void doPost(HttpServletRequest request, 
	        HttpServletResponse response)throws ServletException, IOException {
			doGet(request, response);
		}
	}
