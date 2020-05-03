package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class MeijuCL {
	private static List<String> emjcl = new ArrayList<String>();

	public MeijuCL(String s) throws IOException {
		File file = new File(CfenxiGUI.getStr()+"output.txt");
		FileOutputStream fop = new FileOutputStream(file, true);
		OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
		writer.append(3+" 枚举型常量：" + s + "\r\n");
		writer.close();
		fop.close();
		if (!emjcl.contains(s)) {
			emjcl.add(s);
			File f = new File(CfenxiGUI.getStr()+"Changliang.txt");
			FileOutputStream fos = new FileOutputStream(f, true);
			OutputStreamWriter w = new OutputStreamWriter(fos, "UTF-8");
			w.append("枚举型常量："+s +"\t"+3+ "\r\n");
			w.close();
			fos.close();
		} else
			return;
	}
}
