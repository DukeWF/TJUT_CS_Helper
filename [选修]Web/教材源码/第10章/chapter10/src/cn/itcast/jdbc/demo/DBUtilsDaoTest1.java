package cn.itcast.jdbc.demo;
import java.sql.SQLException;
import cn.itcast.chapter10.example.User;
public class DBUtilsDaoTest1 {
	private static DBUtilsDao dao = new DBUtilsDao();
	public static void testInsert() throws SQLException {
		User user = new User();
		user.setName("zhaoliu");
		user.setPassword("666666");
		boolean b = dao.insert(user);
		System.out.println(b);
	}
	public static void main(String[] args) throws SQLException {
		testInsert();
	}
}
