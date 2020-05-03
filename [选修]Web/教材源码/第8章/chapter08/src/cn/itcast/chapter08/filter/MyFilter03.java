package cn.itcast.chapter08.filter;
import java.io.*;
import javax.servlet.*;
public class MyFilter03 implements Filter {
	private String characterEncoding;
	FilterConfig fc;
	public void init(FilterConfig fConfig) throws ServletException {
		// 获取FilterConfig对象
		this.fc = fConfig;
	}
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		// 输出参数信息
		characterEncoding=fc.getInitParameter("encoding");
		System.out.println("encoding初始化参数的值为："+characterEncoding);
		chain.doFilter(request, response);
	}
	public void destroy() {
	}
}
