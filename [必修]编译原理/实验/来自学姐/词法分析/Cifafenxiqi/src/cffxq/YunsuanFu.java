package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class YunsuanFu {
	private static String[] ysf = { "+", "-", "*", "/", "%", "++", "--", ">", "<", "==", ">=", "<=", "!=", "&&", "||",
			"!", "&", "|", "~", "^", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ">>=", "<<=",
			"?:", "sizeof", "(", ")", "->", "assignment" };
	private static List<String> ysfl = Arrays.asList(ysf);
	private static List<String> eysf = new ArrayList<String>();

	public YunsuanFu(String s) throws IOException {
		if (ysfl.contains(s)) {
			File f = new File(CfenxiGUI.getStr()+"output.txt");
			FileOutputStream fop = new FileOutputStream(f, true);
			OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
			writer.append(50+ysfl.indexOf(s)+" ÔËËã·û£º" + s + "\r\n");
			writer.close();
			fop.close();
			if (!eysf.contains(s)) {
				eysf.add(s);
				File file = new File(CfenxiGUI.getStr()+"Fuhao.txt");
				FileOutputStream fos = new FileOutputStream(file,true);
				OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
				w.append("ÔËËã·û£º"+s+"\t"+(50+ysfl.indexOf(s))+"\r\n");
				w.close();
				fos.close();
			} else
				return;
		} else
			return;
	}

}
