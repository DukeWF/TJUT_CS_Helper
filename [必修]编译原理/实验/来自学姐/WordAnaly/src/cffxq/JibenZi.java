package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class JibenZi {
	private static String[] jbz = { "auto", "short", "int", "long", "float", "double", "char", "struct", "union",
			"enum", "typedef", "const", "unsigned", "signed", "extern", "register", "static", "volatile", "void", "if",
			"switch", "for", "do", "while", "goto", "continue", "break", "default", "sizeof", "return", "printf",
			"main", "include", "scanf","putch","getch" };
	private static List<String> jbzl = Arrays.asList(jbz);
	private static List<String> ejbz = new ArrayList<String>();

	public JibenZi(String s) throws IOException {
		if (jbzl.contains(s)) {
			File f = new File(CfenxiGUI.getStr()+"output.txt");
			FileOutputStream fop = new FileOutputStream(f, true);
			OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
			writer.append(7+jbzl.indexOf(s)+" 基本字：" + s + "\r\n");
			writer.close();
			fop.close();
			if (!ejbz.contains(s)) {
				ejbz.add(s);
				File file = new File(CfenxiGUI.getStr()+"Fuhao.txt");
				FileOutputStream fos = new FileOutputStream(file,true);
				OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
				w.append("基本字："+s+"\t"+(7+jbzl.indexOf(s))+"\r\n");
				w.close();
				fos.close();
			} else
				return;
		} else
			return;
	}
}
