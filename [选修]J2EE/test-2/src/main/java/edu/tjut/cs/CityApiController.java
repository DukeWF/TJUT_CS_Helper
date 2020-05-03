package edu.tjut.cs;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;

@RestController
public class CityApiController {
	
	@Autowired
	private CityService cityService;
	
    public CityApiController() {
    }

    @ApiOperation(httpMethod="GET", notes="列出所有国家", value="打开首页")
    @ApiResponse(message="index视图模板", code = 200)
    @GetMapping("/api/zzz")
    public List<String> index() {
    	return cityService.findAllCountries();
    }
    
    @ApiOperation(httpMethod="POST", notes="列出所有城市", value="打开城市页")
    @ApiResponse(message="city视图模板", code = 200)
    @PostMapping("/api/aaa")
    public List<City> city(@RequestParam("a_country") String country_name) {
    	return cityService.findByCountry(country_name);
    }
}
