package edu.tjut.cs;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;

@Controller
public class CityController {
	
	@Autowired
	private CityService cityService;
	
    public CityController() {
    }

    @ApiOperation(httpMethod="GET", notes="列出所有国家", value="打开首页")
    @ApiResponse(message="index视图模板", code = 200)
    @GetMapping("/zzz")
    public ModelAndView index() {
    	List<String> countries = cityService.findAllCountries();
    	ModelAndView view = new ModelAndView("/index");
    	view.addObject("allcountries", countries);
    	return view;
    }
    
    @ApiOperation(httpMethod="POST", notes="列出所有城市", value="打开城市页")
    @ApiResponse(message="city视图模板", code = 200)
    @PostMapping("/aaa")
    public ModelAndView city(@RequestParam("a_country") String country_name) {
    	List<City> cities = cityService.findByCountry(country_name);
    	ModelAndView view = new ModelAndView("/city");
    	view.addObject("allcities", cities);
    	return view;
    }
}
