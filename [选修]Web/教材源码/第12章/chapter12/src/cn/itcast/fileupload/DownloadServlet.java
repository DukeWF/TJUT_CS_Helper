package cn.itcast.fileupload;
import java.io.*;
import java.net.URLEncoder;
import javax.servlet.*;
import javax.servlet.http.*;
public class DownloadServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public void doGet(HttpServletRequest request, HttpServletResponse 
		response) throws ServletException, IOException {
		//设置ContentType字段值
		response.setContentType("text/html;charset=utf-8");
		//设置相应消息编码
		response.setCharacterEncoding("utf-8");
		//设置请求消息编码
		request.setCharacterEncoding("utf-8"); 				
		//获取所要下载的文件名称
		String filename = request.getParameter("filename");		
		//对文件名称编码
		filename = new String(filename.trim().getBytes("iso8859-1"),"UTF-8");  
        //下载文件所在目录
        String folder = "/download/";
        // 通知浏览器以下载的方式打开
		response.addHeader("Content-Type", "application/octet-stream");
		response.addHeader("Content-Disposition", 
        		"attachment;filename="+URLEncoder.encode(filename,"utf-8"));
		// 通过文件流读取文件
		InputStream in = getServletContext().getResourceAsStream(
				folder+filename);
		// 获取response对象的输出流
		OutputStream out = response.getOutputStream();
		byte[] buffer = new byte[1024];
		int len;
		//循环取出流中的数据
		while ((len = in.read(buffer)) != -1) {
			out.write(buffer, 0, len);
		}

	}
  	public void doPost(HttpServletRequest request, HttpServletResponse 
  		response) throws ServletException, IOException {
		doGet(request, response);
	}
}