package edu.tjut.cs;

import java.sql.ResultSet;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

@Service
public class CityService {
	@Autowired
	private JdbcTemplate jdao;
	
	public CityService() {
	}

	public CityService(JdbcTemplate jdao) {
		this.jdao = jdao;
	}

	public List<City> findAll() {
		List<City> cities = jdao.query("select * from city", (ResultSet rs, int i) -> {
			City city = new City();
			city.setName(rs.getString("name"));
			city.setCountry(rs.getString("country"));
			city.setState(rs.getString("state"));
			return city;
		});
		return cities;
	}
	
	public List<City> findByCountry(String country) {
		List<City> cities = jdao.query("select * from city where country=?", new Object[] {country}, (ResultSet rs, int i) -> {
			City city = new City();
			city.setName(rs.getString("name"));
			city.setCountry(rs.getString("country"));
			city.setState(rs.getString("state"));
			return city;
		});
		return cities;
	}
	
	public List<String> findAllCountries() {
		List<String> countries = jdao.query("select distinct country from city", (ResultSet rs, int i) -> {
			return rs.getString("country");
		});
		return countries;
	}
}
