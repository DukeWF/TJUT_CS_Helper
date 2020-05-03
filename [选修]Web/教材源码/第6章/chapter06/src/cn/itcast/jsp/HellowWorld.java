package cn.itcast.jsp;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.jasper.runtime.HttpJspBase;
/**
 * 可使用该类查看HttpJspBase类的源代码
 * @author admin
 *
 */
public class HellowWorld {
        HttpJspBase httpJspBase = new HttpJspBase() {
		@Override
		public void _jspService(HttpServletRequest arg0, HttpServletResponse arg1)
				throws ServletException, IOException {
		}
	};

}
