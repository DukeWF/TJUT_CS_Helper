package cn.itcast.chapter08.listener;
import javax.servlet.*;
import javax.servlet.http.*;
public class MyAttributeListener implements ServletContextAttributeListener,
		HttpSessionAttributeListener, ServletRequestAttributeListener {
	public void attributeAdded(ServletContextAttributeEvent sae) {
		String name = sae.getName();
		System.out.println("ServletContext添加属性：" + name + "="
				+ sae.getServletContext().getAttribute(name));
	}
	public void attributeRemoved(ServletContextAttributeEvent sae) {
		String name = sae.getName();
		System.out.println("ServletContext移除属性: " + name);
	}
	public void attributeReplaced(ServletContextAttributeEvent sae) {
		String name = sae.getName();
		System.out.println("ServletContext替换属性：" + name + "="
				+ sae.getServletContext().getAttribute(name));
	}
	public void attributeAdded(HttpSessionBindingEvent hbe) {
		String name = hbe.getName();
		System.out.println("HttpSession添加属性：" + name + "="
				+ hbe.getSession().getAttribute(name));
	}
	public void attributeRemoved(HttpSessionBindingEvent hbe) {
		String name = hbe.getName();
		System.out.println("HttpSession移除属性: " + name);
	}
	public void attributeReplaced(HttpSessionBindingEvent hbe) {
		String name = hbe.getName();
		System.out.println("HttpSession替换属性：" + name + "="
				+ hbe.getSession().getAttribute(name));
	}
	public void attributeAdded(ServletRequestAttributeEvent sra) {
		String name = sra.getName();
		System.out.println("ServletRequest添加属性：" + name + "="
				+ sra.getServletRequest().getAttribute(name));
	}
	public void attributeRemoved(ServletRequestAttributeEvent sra) {
		String name = sra.getName();
		System.out.println("ServletRequest移除属性: " + name);
	}
	public void attributeReplaced(ServletRequestAttributeEvent sra) {
		String name = sra.getName();
		System.out.println("ServletRequest替换属性：" + name + "="
				+ sra.getServletRequest().getAttribute(name));
	}
}
