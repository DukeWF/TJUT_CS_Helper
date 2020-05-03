package yufafenxi;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Yffx {
	private static List<String> vn = new ArrayList<String>();
	private static Hashtable<String, List<String>> First = new Hashtable<String, List<String>>();
	private static Hashtable<String, List<String>> Last = new Hashtable<String, List<String>>();
	private static Hashtable<String, List<String>> Xiaoyu = new Hashtable<String, List<String>>();
	private static Hashtable<String, List<String>> Dayu = new Hashtable<String, List<String>>();
	private static Hashtable<String, String> Dengyu = new Hashtable<String, String>();
	private static Hashtable<String, String> Yufa = new Hashtable<String, String>();
	private static List<String> sf = new ArrayList<String>();

	public Yffx(String[] s) {
		System.out.println("语法为：");
		for (int i = 0; i < s.length; i++) {
			System.out.println(s[i]);
			vn.add(s[i].substring(0, 1));
		}
		System.out.println("非终结符：" + vn);
		for (int i = 0; i < s.length; i++) {
			List<String> cache = new ArrayList<String>();
			List<String> cache1 = new ArrayList<String>();
			s[i] = s[i].substring(3, s[i].length());
			String[] values = s[i].split("\\|");
			for (int j = 0; j < values.length; j++) {
				for (int a = 0; a < values[j].length(); a++) {
					if (!vn.contains(values[j].substring(a, a + 1))) {
						cache.add(values[j].substring(a, a + 1));
						break;
					}
				}
				for (int b = values[j].length(); b >= 1; b--) {
					if (!vn.contains(values[j].substring(b - 1, b))) {
						cache1.add(values[j].substring(b - 1, b));
						break;
					}
				}
			}
			First.put(vn.get(i), cache);
			Last.put(vn.get(i), cache1);
		}
		System.out.println("第一步FirstVt：" + First);
		System.out.println("第一步LastVt：" + Last);
		for (int i = 0; i < s.length; i++) {
			char[] c = s[i].toCharArray();
			for (int j = 0; j < c.length; j++) {
				if (!Character.isUpperCase(c[j]) && !(c[j] == '|')) {
					sf.add(Character.toString(c[j]));
				}
			}
		}
		sf.add("#");
		for (int i = s.length - 1; i >= 0; i--) {
			String[] values = s[i].split("\\|");
			for (int j = 0; j < values.length; j++) {
				if (vn.contains(values[j])) {
					for (int c = 0; c < First.get(values[j]).size(); c++) {
						First.get(vn.get(i)).add(First.get(values[j]).get(c));
						First.put(vn.get(i), First.get(vn.get(i)));
						Last.get(vn.get(i)).add(Last.get(values[j]).get(c));
						Last.put(vn.get(i), Last.get(vn.get(i)));
					}
				}
			}
		}
		System.out.println("FirstVt：" + First);
		System.out.println("LastVt：" + Last);
		for (int i = 0; i < s.length; i++) {
			String[] values = s[i].split("\\|");
			for (int j = 0; j < values.length; j++) {
				char[] ch = values[j].toCharArray();
				int count = 0;
				while (count < ch.length - 1) {
					String str;
					str = Character.toString(ch[count]);
					if (vn.contains(str)) {
						count++;
						if (!vn.contains(Character.toString(ch[count]))) {
							for (int i1 = 0; i1 < Last.get(str).size(); i1++) {
								List<String> cache2 = new ArrayList<String>();
								if (Dayu.containsKey(Last.get(str).get(i1))) {
									cache2.addAll(Dayu.get(Last.get(str).get(i1)));
									cache2.add(Character.toString(ch[count]));
								} else {
									cache2.add(Character.toString(ch[count]));
								}
								Dayu.put(Last.get(str).get(i1), cache2);
							}
						} else
							System.out.println("Wrong grammer");
						;
					} else {
						count++;
						if (vn.contains(Character.toString(ch[count]))) {
							List<String> cache3 = new ArrayList<String>();
							if (Xiaoyu.containsKey(str)) {
								cache3.addAll(Xiaoyu.get(str));
								cache3.addAll(First.get(Character.toString(ch[count])));
							} else {
								cache3.addAll(First.get(Character.toString(ch[count])));
							}
							Xiaoyu.put(str, cache3);
						}
					}
				}
			}
		}
		Xiaoyu.put("#", First.get(vn.get(0)));
		for (int i = 0; i < Last.get(vn.get(0)).size(); i++) {
			List<String> cache4 = new ArrayList<String>();
			if (Dayu.containsKey(Last.get(vn.get(0)).get(i))) {
				cache4.addAll(Dayu.get(Last.get(vn.get(0)).get(i)));
				cache4.add("#");
			} else {
				cache4.add("#");
			}
			Dayu.put(Last.get(vn.get(0)).get(i), cache4);
		}
		Dengyu.put("#", "#");
		for (int i = 0; i < s.length; i++) {
			String[] values = s[i].split("\\|");
			for (int j = 0; j < values.length; j++) {
				Pattern pattern = Pattern.compile("[^A-Z][A-Z]+[^A-Z]");
				Matcher matcher = pattern.matcher(values[j]);
				if (matcher.find()) {
					Dengyu.put(matcher.group().substring(0, 1),
							matcher.group().substring(matcher.end() - 1, matcher.end()));
				}
			}
		}
		System.out.println(">：" + Dayu);
		System.out.println("<：" + Xiaoyu);
		System.out.println("=：" + Dengyu);
		System.out.print(" ");
		for (int i = 0; i < sf.size(); i++) {
			System.out.print("   " + sf.get(i));
		}
		System.out.println();
		for (int i = 0; i < sf.size(); i++) {
			System.out.print(sf.get(i));
			for (int j = 0; j < sf.size(); j++) {
				if (Xiaoyu.containsKey(sf.get(i)) && Xiaoyu.get(sf.get(i)).contains(sf.get(j)))
					System.out.print("   <");
				else if (Dayu.containsKey(sf.get(i)) && Dayu.get(sf.get(i)).contains(sf.get(j)))
					System.out.print("   >");
				else if (Dengyu.containsKey(sf.get(i)) && Dengyu.get(sf.get(i)).contains(sf.get(j)))
					System.out.print("   =");
				else
					System.out.print("    ");
			}
			System.out.println();
		}
		for (int i = 0; i < s.length; i++) {
			String[] values = s[i].split("\\|");
			for (int j = 0; j < values.length; j++) {
				Yufa.put(values[j], vn.get(i));
			}
		}
	}

	public static void JianCe(String str) {
		System.out.println(str);
		char[] h = str.toCharArray();
		List<String> a = new ArrayList<String>();
		List<String> b = new ArrayList<String>();
		List<String> c = new ArrayList<String>();
		a.add("#");
		c.add("#");
		System.out.println(a);
		for (int i = 1; i < h.length; i++) {
			if (!vn.contains(Character.toString(h[i]))) {
				if (Xiaoyu.containsKey(a.get(a.size() - 1))
						&& Xiaoyu.get(a.get(a.size() - 1)).contains(Character.toString(h[i]))) {
					a.add(Character.toString(h[i]));
					c.add(Character.toString(h[i]));
					System.out.println(c);
				} else if (Dayu.containsKey(a.get(a.size() - 1))
						&& Dayu.get(a.get(a.size() - 1)).contains(Character.toString(h[i]))) {
					while (Dayu.containsKey(a.get(a.size() - 1))
							&& Dayu.get(a.get(a.size() - 1)).contains(Character.toString(h[i]))) {
						if (Yufa.containsKey(a.get(a.size() - 1))) {
							b.add(Yufa.get(a.get(a.size() - 1)));
							a.remove(a.get(a.size() - 1));
							c.remove(c.get(c.size() - 1));
							c.add(b.get(b.size() - 1));
							System.out.println(c);
							if (!"#".equals(Character.toString(h[i]))) {
								c.add(Character.toString(h[i]));
								System.out.println(c);
							}
						} else if (Yufa.containsKey(b.get(b.size() - 2) + a.get(a.size() - 1) + b.get(b.size() - 1))) {
							b.remove(b.size() - 1);
							b.remove(b.size() - 1);
							a.remove(a.size() - 1);
							c.remove(c.size() - 1);
							c.remove(c.size() - 1);
							c.remove(c.size() - 1);
							b.add(Yufa.get(b.get(b.size() - 2) + a.get(a.size() - 1) + b.get(b.size() - 1)));
							c.add(b.get(b.size() - 1));
							System.out.println(c);
						} else {
							String s = b.get(b.size() - 2);
							int count1 = 0;
							while (Yufa.containsKey(s)) {
								count1++;
								s = Yufa.get(s);
							}
							String t = b.get(b.size() - 1);
							int count2 = 0;
							while (Yufa.containsKey(t)) {
								count2++;
								t = Yufa.get(t);
							}
							s = b.get(b.size() - 2);
							for (int k = 0; k < count1 + 1; k++) {
								t = b.get(b.size() - 1);
								for (int j = 0; j < count2; j++) {
									if (Yufa.containsKey(s + a.get(a.size() - 1) + t)) {
										b.remove(b.size() - 1);
										b.remove(b.size() - 1);
										b.add(Yufa.get(s + a.get(a.size() - 1) + t));
										c.remove(c.size() - 1);
										c.remove(c.size() - 1);
										c.remove(c.size() - 1);
										c.add(Yufa.get(s + a.get(a.size() - 1) + t));
										System.out.println(c);
										a.remove(a.size() - 1);
										break;
									} else {
										t = Yufa.get(t);
									}
								}
								s = Yufa.get(s);
							}
						}
					}
					a.add(Character.toString(h[i]));
				} else {
					a.remove(a.get(a.size() - 1));
					c.add(Character.toString(h[i]));
					System.out.println(c);
				}
			}
		}
	}

	public static void Siyuanshi(String str) {
		System.out.println(str);
		char[] h = str.toCharArray();
		List<String> a = new ArrayList<String>();
		List<String> b = new ArrayList<String>();
		a.add("#");
		int y = 1;
		for (int i = 1; i < h.length; i++) {
			if (sf.contains(Character.toString(h[i]))) {
				if (Xiaoyu.containsKey(a.get(a.size() - 1))
						&& Xiaoyu.get(a.get(a.size() - 1)).contains(Character.toString(h[i]))) {
					a.add(Character.toString(h[i]));
				} else if (Dayu.containsKey(a.get(a.size() - 1))
						&& Dayu.get(a.get(a.size() - 1)).contains(Character.toString(h[i]))) {
					while (Dayu.containsKey(a.get(a.size() - 1))
							&& Dayu.get(a.get(a.size() - 1)).contains(Character.toString(h[i]))) {
						System.out.println(
								"(" + a.get(a.size()-1) + "," + b.get(b.size() - 2) + "," + b.get(b.size() - 1) + ",t" + y + ")");
						b.remove(b.size() - 1);
						b.remove(b.size() - 1);
						a.remove(a.size() - 1);
						b.add("t" + y);
						y++;
					}
					a.add(Character.toString(h[i]));
				} else {
					a.remove(a.get(a.size() - 1));
				}
			} else {
				b.add(Character.toString(h[i]));
			}
		}
	}

	public static void main(String[] args) {
		String[] string = {"E→E+T | E-T | T","T→T*F | T/F | F","F→P^F | P","P→(E) | i"};
		new Yffx(string);
//		System.out.println("测试");
//		JianCe("#i+i*i#");
//		System.out.println("四元式");
//		Siyuanshi("#A+B*C-D/E#");
	}

}
