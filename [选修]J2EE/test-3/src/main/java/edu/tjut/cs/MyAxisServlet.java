package edu.tjut.cs;

import javax.servlet.annotation.WebServlet;

import org.apache.axis.transport.http.AxisServlet;

/**
 * @author donghongchen
 * @create 2017-05-08 10:10
 **/

@WebServlet(urlPatterns = "/services/*", loadOnStartup = 1, name = "AxisServlet")
public class MyAxisServlet extends AxisServlet {
	private static final long serialVersionUID = -2656365063271595777L;
}
