package cn.itcast.chapter07.javabean;
public class Student {
	private String sid;
	private String name;
	private int age;
	private boolean married;
	// age属性的getter和setter方法
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	// married属性的getter和setter方法
	public boolean isMarried() {
		return married;
	}
	public void setMarried(boolean married) {
		this.married = married;
	}
	// sid属性的getter方法
	public String getSid() {
		return sid;
	}
	// name属性的setter方法
	public void setName(String name) {
		this.name = name;
	}
	public void getInfo() {
		System.out.print("我是一个学生");
	}
}
