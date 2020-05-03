 package cn.itcast.chapter10.example;
 import java.sql.SQLException;
 import javax.sql.DataSource;
 import com.mchange.v2.c3p0.ComboPooledDataSource;
 public class Example04 {
 	public static DataSource ds = null;
 	// 初始化C3P0数据源
 	static {
 		// 使用c3p0-config.xml配置文件中的named-config节点中name属性的值
 		ComboPooledDataSource cpds = new ComboPooledDataSource("itcast");
 		ds = cpds;
 	}
 	public static void main(String[] args) throws SQLException {
 		System.out.println(ds.getConnection());
 	}
 }
