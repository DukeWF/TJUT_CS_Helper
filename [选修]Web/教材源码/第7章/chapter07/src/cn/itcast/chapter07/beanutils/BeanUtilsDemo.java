package cn.itcast.chapter07.beanutils;
import java.util.HashMap;
import java.util.Map;
import org.apache.commons.beanutils.BeanUtils;
public class BeanUtilsDemo {
	public static void main(String[] args) throws Exception {
		Person p = new Person();
		// 使用BeanUtils为属性赋值
		BeanUtils.setProperty(p, "name", "Jack");
		BeanUtils.setProperty(p, "age", 10);
		// 使用BeanUtils获取属性值
		String name = BeanUtils.getProperty(p, "name");
		String age = BeanUtils.getProperty(p, "age");
		System.out.println("我的名字是" + name + ",我今年" + age + "岁了！");
		// 创建map集合，用于存放属性及其属性值
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("name", "张三");
		map.put("age", 10);
		// 使用populate()方法为对象的属性赋值
		BeanUtils.populate(p, map);
		// 打印赋值后对象的信息
		System.out.println("姓名：" + p.getName() + ", 年龄：" + p.getAge());
	}
}
