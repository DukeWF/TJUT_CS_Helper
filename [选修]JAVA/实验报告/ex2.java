

public class Staff {
	public static void payDetail(StaffMember obj) {
		System.out.println(obj.toString());
	}
	public static void main(String[] args) {
		 StaffMember[] staffList= new StaffMember[6];
		 staffList[0] = new Manager("sam","123 Main Line","555-0469",2423.07,"123-45-6789",500);
		 staffList[1] = new Employee("Peter","456 Off Line","555-0101",1246.15,"987-65-4321");
		 staffList[2] = new Employee("Mary","789 Off Rocker","555-0690",1169.23,"010-20-3040");
		 staffList[3] = new Hourly("Cliff","678 Fifth Ave","555-0000",10.55,"958-47-3625",40);
		 staffList[4] = new Volunter("Al","987 Suds Ave","555-8374");
		 staffList[5] = new Volunter("Gus","321 Off Line","555-7282");
		 
		 for(int i = 0;i < staffList.length;i++){
			 payDetail(staffList[i]);
		 }
		 
	}
}



public class Manager extends Employee{
	double bonus = 0;
	public Manager(String name, String address, String phone,
			double payRate, String sociaISN, double bonus) {
		super(name, address, phone, payRate, sociaISN);
		this.bonus = bonus;
	}
	public void awardBonus(double bonus) {
		this.bonus += bonus;
	}
	public double pay(){
		return payRate + bonus;
	}
	public String toString() {
		return "姓名："+name+"\n地址："+address+"\n电话："+phone+"\n社区安全号："+sociaISN+"\n工资：$"+pay()+"\n------------------------";
	}
}


public class Hourly extends Employee{
	int hoursWorked = 0;
	public Hourly(String name, String address, String phone,
			double payRate, String sociaISN, int hoursWorked) {
		super(name, address, phone, payRate, sociaISN);
		this.hoursWorked = hoursWorked;
	}
	public void addHours(int hours) {
		this.hoursWorked += hours;
	}
	public double pay(){
		return payRate * hoursWorked;
	}
	public String toString() {
		return "姓名："+name+"\n地址："+address+"\n电话："+phone+"\n社区安全号："+sociaISN+"\n工作小时数："+hoursWorked+"\n工资：$"+pay()+"\n------------------------";
	}
}



public class Employee extends StaffMember{
	public String sociaISN;
	public double payRate;
	public Employee(String name, String address, String phone,
			double payRate, String sociaISN) {
		super(name, address, phone);
		this.payRate = payRate;
		this.sociaISN = sociaISN;
	}

	public double pay() {
		return payRate;
		}
	public String toString(){
		return "姓名："+name+"\n地址："+address+"\n电话："+phone+"\n社区安全号："+sociaISN+"\n工资：$"+pay()+"\n------------------------";
		}
}



class Volunter extends StaffMember{
	public Volunter(String name, String address, String phone) {
		super(name, address, phone);
	}

	public double pay(){
		return 0;
	}
	public String toString() {
		return "姓名："+name+"\n地址："+address+"\n电话："+phone+"\n多谢！\n------------------------";
	}
}



public abstract class StaffMember{
	public String name;
	public String address;
	public String phone;
	
	public StaffMember(String name, String address, String phone) {
		this.name = name;
		this.address = address;
		this.phone = phone;
	}
	public abstract double pay();
	@Override
	public String toString() {
		return "StaffMember [name=" + name + ", address=" + address + ", phone=" + phone + "]";
	}
}
