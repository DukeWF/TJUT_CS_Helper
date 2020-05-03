package cn.itcast.chapter08.filter;
import java.io.*;
import javax.servlet.*;
public class MyFilter01 implements Filter {
	public void init(FilterConfig fConfig) throws ServletException {
		// 过滤器对象在初始化时调用，可以配置一些初始化参数
	}
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		// 用于拦截用户的请求，如果和当前过滤器的拦截路径匹配，该方法会被调用
		PrintWriter out=response.getWriter();
		out.write("Hello MyFilter01<br />");
		chain.doFilter(request, response);
	}
	public void destroy() {
		// 过滤器对象在销毁时自动调用，释放资源
	}
}
