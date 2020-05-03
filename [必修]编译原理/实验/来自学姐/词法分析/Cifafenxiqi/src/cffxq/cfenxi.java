package cffxq;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class cfenxi {
	private String[] jf = { "{", "}", ";", ",", ":" };
	private List<String> jfl = Arrays.asList(jf);
	private String[] ysf = { "+", "=", "!", "~", "^", "|", "%" };
	private List<String> ysfl = Arrays.asList(ysf);
	private String[] qita = { "auto", "short", "int", "long", "float", "double", "char", "struct", "union", "enum",
			"typedef", "const", "unsigned", "signed", "extern", "register", "static", "volatile", "void", "if",
			"switch", "for", "do", "while", "goto", "continue", "break", "default", "sizeof", "return", "printf",
			"main", "include", "scanf", "sizeof", "assignment", "true", "false", "getch", "putch" };
	private List<String> qital = Arrays.asList(qita);
	private static String s;
	private boolean jflag = false;

	public boolean isJiefu(char c) {
		if (jfl.contains(Character.toString(c))) {
			return true;
		} else
			return false;
	}

	public boolean isLetterorDigitorXiahuaxian(char c) {
		if (Character.isLetterOrDigit(c) || c == '_') {
			return true;
		} else
			return false;
	}

	public boolean isYunsuanfu(char c) {
		if (ysfl.contains(Character.toString(c))) {
			return true;
		}
		return false;
	}

	public cfenxi(String c) throws IOException {
		FileInputStream fis = new FileInputStream(c);
		InputStreamReader ifr = new InputStreamReader(fis);
		@SuppressWarnings("resource")
		BufferedReader br = new BufferedReader(ifr);
		String line = br.readLine();
		while (line != null) {
			int tflag = 0;
			@SuppressWarnings("unused")
			boolean yflag = false;
			char[] fx = line.toCharArray();
			int count = 0;
			while (count < fx.length) {
				if (Character.isLetter(fx[count])) {
					s = Character.toString(fx[count]);
					count++;
					while (count < fx.length) {
						if (isLetterorDigitorXiahuaxian(fx[count])) {
							s = s.concat(Character.toString(fx[count]));
							count++;
						} else
							break;
					}
					Pattern pattern = Pattern.compile("[;#\\(\\)]");
					Matcher matcher = pattern.matcher(line.trim());
					Pattern p = Pattern.compile(
							"auto|struct|union|enum|typedef|extern|register|static|volatile|void|do|goto|assignment");
					Matcher m = p.matcher(line.trim());
					if (!matcher.find()) {
						if (!m.find()) {
							new MeijuCL(s);
						} else if (!qital.contains(s)) {
							new BiaoshiFu(s);
						} else {
							new JibenZi(s);
							new YunsuanFu(s);
							new BuerCL(s);
						}
					} else if (!qital.contains(s)) {
						new BiaoshiFu(s);
					} else {
						new JibenZi(s);
						new YunsuanFu(s);
						new BuerCL(s);
					}
				} else if (fx[count] == '#') {
					s = Character.toString(fx[count]);
					count++;
					new JieFu(s);
				} else if (Character.isWhitespace(fx[count])) {
					count++;
				} else if (jfl.contains(fx[count])) {
					count++;
					s = Character.toString(fx[count]);
				} else if (fx[count] == '<') {
					s = Character.toString(fx[count]);
					count++;
					Pattern pattern = Pattern.compile("<.*>");
					Matcher matcher = pattern.matcher(line.trim());
					if (matcher.find()) {
						tflag = 1;
						new JieFu(s);
						Pattern p = Pattern.compile("#include\\s*<\\s*[A-Za-z]+.h\\s*>");
						Matcher m = p.matcher(line.trim());
						if (m.find()) {
							Pattern pat = Pattern.compile("[A-Za-z]+.h");
							Matcher mat = pat.matcher(line.trim());
							if (mat.find()) {
								s = mat.group();
								new Touwenjian(s);
								count = count + mat.end() - mat.start();
							} else {
								return;
							}
						}
					} else {
						try {
							if (fx[count] == '=') {
								tflag = 0;
								s = s.concat(Character.toString(fx[count]));
								count++;
								new YunsuanFu(s);
							} else if (fx[count] == '<') {
								tflag = 0;
								s = s.concat(Character.toString(fx[count]));
								count++;
								if (fx[count] == '=') {
									s = s.concat(Character.toString(fx[count]));
									count++;
									new YunsuanFu(s);
								} else {
									new YunsuanFu(s);
								}
							} else {
								new YunsuanFu(s);
							}
						} catch (Exception e) {
							new YunsuanFu(s);
						}
					}
				} else if (fx[count] == '>') {
					s = Character.toString(fx[count]);
					count++;
					if (tflag == 1) {
						new JieFu(s);
					} else {
						try {
							if (fx[count] == '=') {
								s = s.concat(Character.toString(fx[count]));
								count++;
								new YunsuanFu(s);
							} else if (fx[count] == '>') {
								s = s.concat(Character.toString(fx[count]));
								count++;
								if (fx[count] == '=') {
									s = s.concat(Character.toString(fx[count]));
									count++;
									new YunsuanFu(s);
								} else {
									new YunsuanFu(s);
								}
							} else {
								new YunsuanFu(s);
							}
						} catch (Exception e) {
							new YunsuanFu(s);
						}
					}
				}

				else if (fx[count] == '(') {
					s = Character.toString(fx[count]);
					count++;
					Pattern p = Pattern.compile("\\((\\**\\&*[_A-Za-z0-9+-/%>*<!|&~^?:.\\s*]+)\\)");
					Matcher m = p.matcher(line.trim());
					if (m.find()) {
						jflag = true;
						new YunsuanFu(s);
					} else {
						jflag = false;
						new JieFu(s);
					}
				} else if (fx[count] == ')') {
					s = Character.toString(fx[count]);
					count++;
					if (jflag == false) {
						new JieFu(s);
					} else {
						new YunsuanFu(s);
					}
				} else if (isJiefu(fx[count])) {
					s = Character.toString(fx[count]);
					count++;
					new JieFu(s);
				} else if (isYunsuanfu(fx[count])) {
					s = Character.toString(fx[count]);
					count++;
					if (isYunsuanfu(fx[count])) {
						s = s.concat(Character.toString(fx[count]));
						count++;
						new YunsuanFu(s);
					} else {
						new YunsuanFu(s);
					}
				} else if (Character.isDigit(fx[count])) {
					s = Character.toString(fx[count]);
					count++;
					while (count < fx.length) {
						if (Character.isDigit(fx[count]) || fx[count] == '.') {
							s = s.concat(Character.toString(fx[count]));
							count++;
						} else
							break;
					}
					Pattern pattern = Pattern.compile("[\\d]+\\.[\\d]+");
					Matcher m = pattern.matcher(s);
					if (m.find()) {
						new FudianxingCL(s);
					} else {
						new ZhengxingCL(s);
					}
				} else if (fx[count] == '"') {
					s = Character.toString(fx[count]);
					new JieFu(s);
					count++;
					Pattern p = Pattern.compile("\".*\"");
					Matcher m = p.matcher(line.trim());
					Pattern pattern = Pattern.compile("#include\\s*\"\\s*[A-Za-z]+.h\\s*\"\\s*");
					Matcher matcher = pattern.matcher(line.trim());
					if (m.find()) {
						if (matcher.find()) {
							s = Character.toString(fx[count]);
							count = count - 1 + m.end() - m.start() - 1;
							for (int i = m.start() + 2; i < m.end() - 1; i++) {
								s = s.concat(Character.toString(fx[i]));
							}
							new Touwenjian(s);
							s = Character.toString(fx[count]);
							new JieFu(s);
							count++;
						} else {
							s = Character.toString(fx[count]);
							count = count - 1 + m.end() - m.start() - 1;
								s = m.group().substring(1, m.group().length()-1);
							new ZifuchuanxingCL(s);
							s = Character.toString(fx[count]);
							new JieFu(s);
							count++;
						}
					} else
						return;
				} else if (fx[count] == '\'') {
					s = Character.toString(fx[count]);
					new JieFu(s);
					count++;
					Pattern pattern = Pattern.compile("\'.*\'");
					Matcher matcher = pattern.matcher(line.trim());
					if (matcher.find()) {
						s = Character.toString(fx[count]);
						count = count - 1 + matcher.end() - matcher.start() - 1;
						s = matcher.group().substring(1, matcher.group().length() - 1);
						new ZifuxingCL(s);
						s = Character.toString(fx[count]);
						new JieFu(s);
						count++;
					} else
						return;
				} else if (fx[count] == '&') {
					s = Character.toString(fx[count]);
					count++;
					Pattern pattern = Pattern.compile(
							"[_A-Za-z0-9[\\d]+\\.[\\d]+]+\\)*\\s*\\)*&[&=]*\\(*\\s*\\(*[_A-Za-z0-9[\\d]+\\.[\\d]+]+");
					Matcher matcher = pattern.matcher(line.trim());
					if (matcher.find()) {
						if (fx[count] == '&') {
							s = s.concat(Character.toString(fx[count]));
							new YunsuanFu(s);
							count++;
						} else if (fx[count] == '=') {
							s = s.concat(Character.toString(fx[count]));
							new YunsuanFu(s);
							count++;
						} else
							new YunsuanFu(s);
					} else {
						for (int i = count; i < line.length(); i++) {
							if (isLetterorDigitorXiahuaxian(fx[count])) {
								s = s.concat(Character.toString(fx[count]));
								count++;
							}
						}
						new BiaoshiFu(s);
					}
				} else if (fx[count] == '*') {
					s = Character.toString(fx[count]);
					count++;
					Pattern pattern = Pattern.compile(
							"[_A-Za-z0-9[\\d]+\\.[\\d]+]+\\)*\\s*\\)*\\*=*\\(*\\s*\\(*[_A-Za-z0-9[\\d]+\\.[\\d]+]+");
					Matcher matcher = pattern.matcher(line.trim());
					Pattern p = Pattern.compile(".*\\*\\/");
					Matcher m = p.matcher(line.trim());
					if (matcher.find()) {
						if (fx[count] == '=') {
							s = s.concat(Character.toString(fx[count]));
							count++;
						}
						new YunsuanFu(s);
					} else if (m.find()) {
						s = s.concat(Character.toString(fx[count]));
						count++;
						new JieFu(s);
					} else {
						for (int i = count; i < line.length(); i++) {
							if (isLetterorDigitorXiahuaxian(fx[count])) {
								s = s.concat(Character.toString(fx[count]));
								count++;
							}
						}
						new BiaoshiFu(s);
					}
				} else if (fx[count] == '_') {
					s = Character.toString(fx[count]);
					count++;
					for (int i = count; i < line.length(); i++) {
						if (isLetterorDigitorXiahuaxian(fx[count])) {
							s = s.concat(Character.toString(fx[count]));
							count++;
						}
					}
					Pattern pattern = Pattern.compile("[;#\\(\\)]");
					Matcher matcher = pattern.matcher(line.trim());
					Pattern p = Pattern.compile(
							"auto|struct|union|enum|typedef|extern|register|static|volatile|void|do|goto|assignment");
					Matcher m = p.matcher(line.trim());
					if (!matcher.find()) {
						if (!m.find()) {
							new MeijuCL(s);
						} else if (!qital.contains(s)) {
							new BiaoshiFu(s);
						} else {
							new BuerCL(s);
							new JibenZi(s);
							new YunsuanFu(s);
						}
					} else if (!qital.contains(s)) {
						new BiaoshiFu(s);
					} else {
						new BuerCL(s);
						new JibenZi(s);
						new YunsuanFu(s);
					}
				} else if (fx[count] == '/') {
					s = Character.toString(fx[count]);
					count++;
					Pattern pattern = Pattern.compile(
							"\\**\\&*[_A-Za-z0-9[\\d]+\\.[\\d]+]+\\)*\\s*\\)*\\/=*\\(*\\s*\\(*\\**\\&*[_A-Za-z0-9[\\d]+\\.[\\d]+]+");
					Matcher matcher = pattern.matcher(line.trim());
					if (matcher.find()) {
						if (fx[count] == '=') {
							s = s.concat(Character.toString(fx[count]));
							count++;
						}
						new YunsuanFu(s);
					} else if (fx[count] == '*') {
						s = s.concat(Character.toString(fx[count]));
						count++;
						new JieFu(s);
					} else if (fx[count] == '/') {
						for (int i = count; i < line.length(); i++) {
							s = s.concat(Character.toString(fx[count]));
							count++;
						}
						new Zhushi(s);
					} else {
						new YunsuanFu(s);
					}
				} else if (fx[count] == '-') {
					s = Character.toString(fx[count]);
					count++;
					if (fx[count] == '-') {
						s = s.concat(Character.toString(fx[count]));
						count++;
						new YunsuanFu(s);
					} else if (fx[count] == '=') {
						s = s.concat(Character.toString(fx[count]));
						count++;
						new YunsuanFu(s);
					} else if (fx[count] == '>') {
						s = s.concat(Character.toString(fx[count]));
						count++;
						new YunsuanFu(s);
					}
					  else if(Character.isDigit(fx[count])){
						  s=s.concat(Character.toString(fx[count]));
						  count++;
						  while(Character.isDigit(fx[count])|fx[count]=='.'){
							  s=s.concat(Character.toString(fx[count]));
							  count++;
						  }
						  Pattern pattern = Pattern.compile("[\\d]+\\.[\\d]+");
						  Matcher matcher = pattern.matcher(line);
						  if(matcher.find()){
							  new FudianxingCL(s);
						  }
						  else 
							  new ZhengxingCL(s);
					} else
						new YunsuanFu(s);

				} else if (fx[count] == '?') {
					s = Character.toString(fx[count]);
					count++;
					Pattern pattern = Pattern.compile("[^\\s]+\\?[^\\s]+\\:[^\\s]+");
					Matcher matcher = pattern.matcher(line.trim());
					if (matcher.find()) {
						new YunsuanFu(s);
					} else
						new YunsuanFu(s);
				} else if (fx[count] == ':') {
					s = Character.toString(fx[count]);
					count++;
					Pattern pattern = Pattern.compile("[^\\s]+\\?[^\\s]+\\:[^\\s]+");
					Matcher matcher = pattern.matcher(line.trim());
					if (matcher.find()) {
						new YunsuanFu(s);
					} else
						new Wufashibie(s);
				} else {
					s = Character.toString(fx[count]);
					count++;
					new Wufashibie(s);
				}
			}
			line = br.readLine();
		}

		br.close();
	}
}
