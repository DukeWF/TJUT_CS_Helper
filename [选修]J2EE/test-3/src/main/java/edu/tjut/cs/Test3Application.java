package edu.tjut.cs;

import javax.xml.namespace.QName;

import org.apache.axis.client.Call;
import org.apache.axis.client.Service;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.ServletComponentScan;
import org.springframework.context.annotation.Import;

@SpringBootApplication
@Import({SwaggerConfig.class})
@ServletComponentScan
public class Test3Application implements CommandLineRunner {

	public static void main(String[] args) {
		SpringApplication.run(Test3Application.class, args);
	}

	@Override
	public void run(String... args) throws Exception {
		try {
			Service service = new Service();
			Call call = (Call) service.createCall();
			call.setTargetEndpointAddress(new java.net.URL("http://localhost:8080/services/HelloService"));
			call.setOperationName(new QName("", "hello"));
			String ret = (String) call.invoke(new String[0]);
			System.out.println(ret);
		}
		catch (Exception e) {
			e.printStackTrace();
		}		
	}
}
