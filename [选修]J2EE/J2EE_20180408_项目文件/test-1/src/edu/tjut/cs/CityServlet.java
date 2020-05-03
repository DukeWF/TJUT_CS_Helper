package edu.tjut.cs;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.web.context.WebApplicationContext;
import org.springframework.web.context.support.WebApplicationContextUtils;

@WebServlet("/aaa")
public class CityServlet extends HttpServlet {
	
	private CityService cityService;
	
    public CityServlet() {
        super();
    }

	@Override
	public void init(ServletConfig config) throws ServletException {
		super.init(config);
		WebApplicationContext ctx = WebApplicationContextUtils.getWebApplicationContext(config.getServletContext());
		cityService = (CityService) ctx.getBean("cityService");
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		List<String> countries = cityService.findAllCountries();
		request.setAttribute("allcountries", countries);
		request.getRequestDispatcher("/index.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String aaa = request.getParameter("a_country");
		List<City> cities = cityService.findCityByCountry(aaa);
		request.setAttribute("allcities", cities);
		request.getRequestDispatcher("/city.jsp").forward(request, response);
	}

}
