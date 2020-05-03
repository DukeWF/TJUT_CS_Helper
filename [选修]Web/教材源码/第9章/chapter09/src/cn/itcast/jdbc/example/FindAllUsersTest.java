package cn.itcast.jdbc.example;
import java.util.ArrayList;
import cn.itcast.jdbc.example.dao.UsersDao;
import cn.itcast.jdbc.example.domain.User;
public class FindAllUsersTest{
	public static void main(String[] args) {
		//创建一个名称为usersDao的对象
		UsersDao usersDao = new UsersDao();
		//将UsersDao对象的findAll()方法执行后的结果放入list集合
		ArrayList<User> list = usersDao.findAll();
		//循环输出集合中的数据
		for (int i = 0; i < list.size(); i++) {
				System.out.println("第" + (i + 1) + "条数据的username值为:"
						+ list.get(i).getUsername());
			}
		}
}
