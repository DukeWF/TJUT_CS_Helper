package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BuerCL {
	private static String[] becl = { "true", "false" };
	private static List<String> becll = Arrays.asList(becl);
	private static List<String> ebecl = new ArrayList<String>();
	
	public BuerCL(String s) throws IOException {
		if (becll.contains(s)) {
			File f = new File(CfenxiGUI.getStr()+"output.txt");
			FileOutputStream fop = new FileOutputStream(f, true);
			OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
			writer.append(1+" 布尔型常量：" + s + "\r\n");
			writer.close();
			fop.close();
			if (!ebecl.contains(s)) {
				ebecl.add(s);
				File file = new File(CfenxiGUI.getStr()+"Changliang.txt");
				FileOutputStream fos = new FileOutputStream(file,true);
				OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
				w.append("布尔型常量："+s+"\t"+1+"\r\n");
				w.close();
				fos.close();
			} else
				return;
		} else
			return;
	}
}
