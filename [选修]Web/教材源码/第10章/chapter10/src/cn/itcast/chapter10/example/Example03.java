package cn.itcast.chapter10.example;
import java.sql.SQLException;
import javax.sql.DataSource;
import com.mchange.v2.c3p0.ComboPooledDataSource;
public class Example03 {
	public static DataSource ds = null;
	// 初始化C3P0数据源
	static {
		ComboPooledDataSource cpds = new ComboPooledDataSource();
		// 设置连接数据库需要的配置信息
		try {
			cpds.setDriverClass("com.mysql.jdbc.Driver");
			cpds.setJdbcUrl("jdbc:mysql://localhost:3306/jdbc");
			cpds.setUser("root");
			cpds.setPassword("itcast");
			// 设置连接池的参数
			cpds.setInitialPoolSize(5);
			cpds.setMaxPoolSize(15);
			ds = cpds;
		} catch (Exception e) {
			throw new ExceptionInInitializerError(e);
		}
	}
	public static void main(String[] args) throws SQLException {
		// 获取数据库连接对象
		System.out.println(ds.getConnection());
	}
}
