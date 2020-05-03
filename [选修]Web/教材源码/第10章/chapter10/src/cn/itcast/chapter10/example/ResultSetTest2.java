package cn.itcast.chapter10.example;
import java.sql.SQLException;
import java.util.ArrayList;
import org.apache.commons.dbutils.handlers.BeanListHandler;
public class ResultSetTest2 {
	public static void testBeanListHandler() throws SQLException {
		BaseDao basedao = new BaseDao();
		String sql = "select * from user ";
		ArrayList<User> list = (ArrayList<User>) basedao.query(sql,
				new BeanListHandler(User.class));
		for (int i = 0; i < list.size(); i++) {
			System.out.println("第" + (i + 1) + "条数据的username值为:"
					+ list.get(i).getName());
		}
	}
	public static void main(String[] args) throws SQLException {
		testBeanListHandler();
	}
}
