package cn.itcast.servlet;
import java.io.*;
import java.util.Properties;
import javax.servlet.*;
import javax.servlet.http.*;
public class TestServlet06 extends HttpServlet {
	/**
	 * 相对路径
	 */
//	public void doGet(HttpServletRequest request, 
//      HttpServletResponse response)throws ServletException, IOException {
//		ServletContext context = this.getServletContext();
//			PrintWriter out = response.getWriter();
//			//获取相对路径中的输入流对象
//			InputStream in = context
//				.getResourceAsStream("/WEB-INF/classes/itcast.properties");
//			Properties pros = new Properties();
//			pros.load(in);
//			out.println("Company=" + pros.getProperty("Company") + "<br>");
//			out.println("Address=" + pros.getProperty("Address") + "<br>");
//	}
	/**
	 * 绝对路径
	 */
	public void doGet(HttpServletRequest request, 
	      HttpServletResponse response)throws ServletException, IOException {
	 	PrintWriter out = response.getWriter();
	         ServletContext context = this.getServletContext();
	         //获取文件绝对路径
	 	String path = context
	                        .getRealPath("/WEB-INF/classes/itcast.properties");
	 	FileInputStream in = new FileInputStream(path);
	 	Properties pros = new Properties();
	 	pros.load(in);
	 	out.println("Company=" + pros.getProperty("Company") + "<br>");
	 	out.println("Address=" + pros.getProperty("Address") + "<br>");
	 }

	public void doPost(HttpServletRequest request, 
      HttpServletResponse response)throws ServletException, IOException {
		this.doGet(request, response);
	}
}
