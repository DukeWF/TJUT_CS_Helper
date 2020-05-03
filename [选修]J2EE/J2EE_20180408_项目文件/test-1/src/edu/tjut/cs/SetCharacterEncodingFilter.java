package edu.tjut.cs;

import java.io.IOException;
import java.io.UnsupportedEncodingException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;

@WebFilter("/*")
public class SetCharacterEncodingFilter implements Filter {
	// 处理中文乱码问题的过滤器
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain filterChain) {
		try {
			request.setCharacterEncoding("UTF-8");
			response.setCharacterEncoding("UTF-8");
			filterChain.doFilter(request, response);
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ServletException e) {
			e.printStackTrace();
		}
	}

	public void destroy() {
	}

	public void init(FilterConfig arg0) throws ServletException {
	}
}
