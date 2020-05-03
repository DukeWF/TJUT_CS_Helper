package edu.tjut.cs;

public class City {
	private Long id;
	private String country;
	private String map;
	private String name;
	private String state;
	
	public City() {
	}

	public City(Long id, String country, String map, String name, String state) {
		this.id = id;
		this.country = country;
		this.map = map;
		this.name = name;
		this.state = state;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getCountry() {
		return country;
	}

	public void setCountry(String country) {
		this.country = country;
	}

	public String getMap() {
		return map;
	}

	public void setMap(String map) {
		this.map = map;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getState() {
		return state;
	}

	public void setState(String state) {
		this.state = state;
	}

	@Override
	public String toString() {
		return name + ", " + country + ", " + state;
	}
	
}
