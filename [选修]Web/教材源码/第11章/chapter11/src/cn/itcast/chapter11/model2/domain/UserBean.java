package cn.itcast.chapter11.model2.domain;
public class UserBean {
	private String name;            //定义用户名
	private String password;       //定义密码
	private String email;           //定义邮箱
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
}
