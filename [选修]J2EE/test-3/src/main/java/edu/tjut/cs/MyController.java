package edu.tjut.cs;

import javax.servlet.http.HttpSession;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;

@RestController
public class MyController {
	
	@ApiOperation(httpMethod="GET", notes="返回hello world", value="第一个演示")
	@GetMapping("/")
	public String hello() {
		return "hello world";
	}
	
	@ApiOperation(httpMethod="POST", notes="返回hello", value="第二个演示")
	@ApiImplicitParam(name="who", value="姓名", paramType="query", dataType="String")
	@PostMapping("/aaa")
	public String hello2(@RequestParam("who") String who) {
		return "你好，" + who;
	} 
	
	@ApiOperation(httpMethod="POST", notes="返回hello", value="第三个演示")
	@ApiImplicitParam(name="who", value="姓名", paramType="path", dataType="String")
	@PostMapping("/api/{who}")
	public String hello1(@PathVariable("who") String who) {
		return "hello " + who;
	}
	
	@ApiOperation(httpMethod="POST", notes="返回学生", value="第四个演示")
	@ApiImplicitParam(name="student", value="学生", paramType="body", dataType="Student")
	@PostMapping("/")
	public Student echo(@RequestBody Student s, HttpSession session) {
		System.out.println(session.getId());
		System.out.println(s);
		return s;
	}
}
