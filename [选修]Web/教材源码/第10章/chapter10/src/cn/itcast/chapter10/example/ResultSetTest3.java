package cn.itcast.chapter10.example;
import java.sql.SQLException;
import org.apache.commons.dbutils.handlers.ScalarHandler;
public class ResultSetTest3 {
public static void testScalarHandler() throws SQLException {
	BaseDao basedao = new BaseDao();
	String sql = "select * from user where id=?";
	Object arr = (Object) basedao.query(sql, 
                           new ScalarHandler("name"), 1);
		System.out.println(arr);
	}
	public static void main(String[] args) throws SQLException {
		testScalarHandler();
	}
}
