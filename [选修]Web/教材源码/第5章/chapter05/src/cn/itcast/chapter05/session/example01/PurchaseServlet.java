 package cn.itcast.chapter05.session.example01;
 import java.io.IOException;
 import java.util.*;
 import javax.servlet.ServletException;
 import javax.servlet.http.*;
 public class PurchaseServlet extends HttpServlet {
 	private static final long serialVersionUID = 1L;
 	public void doGet(HttpServletRequest req, HttpServletResponse resp)
 			throws ServletException, IOException {
 			// 获得用户购买的商品
 			String id = req.getParameter("id");
 			if (id == null) {
 				// 如果id为null，重定向到ListBookServlet页面
 				String url = "/chapter05/ListBookServlet";
 				resp.sendRedirect(url);
 				return;
 			}
 			Book book = BookDB.getBook(id);
 			// 创建或者获得用户的Session对象
 			HttpSession session = req.getSession();
 			// 从Session对象中获得用户的购物车
 			List<Book> cart = (List) session.getAttribute("cart");
 			if (cart == null) {
 				// 首次购买，为用户创建一个购物车(List集合模拟购物车)
 				cart = new ArrayList<Book>();
 				// 将购物城存入Session对象
 				session.setAttribute("cart", cart);
 			}
 			// 将商品放入购物车
 			cart.add(book);
 			// 创建Cookie存放Session的标识号
 			Cookie cookie = new Cookie("JSESSIONID", session.getId());
 			cookie.setMaxAge(60 * 30);
 			cookie.setPath("/chapter05");
 			resp.addCookie(cookie);
 			// 重定向到购物车页面
 			String url = "/chapter05/CartServlet";
// 			resp.sendRedirect(url);
 			String newurl=resp.encodeRedirectURL(url);
 			resp.sendRedirect(newurl);

 		}
 	}
