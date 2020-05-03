package cn.itcast.jdbc.example;
import cn.itcast.jdbc.example.dao.UsersDao;
import cn.itcast.jdbc.example.domain.User;
public class FindUserByIdTest {
	public static void main(String[] args) {
		UsersDao usersDao = new UsersDao();
		User user = usersDao.find(1);
		System.out.println("id为1的User对象的name值为：" + user.getUsername());
	}
}
