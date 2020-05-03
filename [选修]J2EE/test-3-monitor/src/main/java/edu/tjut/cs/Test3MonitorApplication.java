package edu.tjut.cs;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import de.codecentric.boot.admin.config.EnableAdminServer;

@SpringBootApplication
@EnableAdminServer
public class Test3MonitorApplication {

	public static void main(String[] args) {
		SpringApplication.run(Test3MonitorApplication.class, args);
	}
}
