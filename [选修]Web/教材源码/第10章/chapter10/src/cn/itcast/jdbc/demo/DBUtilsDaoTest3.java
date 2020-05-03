package cn.itcast.jdbc.demo;
import java.sql.SQLException;
public class DBUtilsDaoTest3 {
	private static DBUtilsDao dao = new DBUtilsDao();
	public static void testdelete() throws SQLException {
		boolean b = dao.delete(4);
		System.out.println(b);
	}
	public static void main(String[] args) throws SQLException {
		testdelete();
	}
}
