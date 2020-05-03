package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class ZifuxingCL {
	private static List<String> ezfxcl = new ArrayList<String>();

	public ZifuxingCL(String s) throws IOException {
		File f = new File(CfenxiGUI.getStr()+"output.txt");
		FileOutputStream fop = new FileOutputStream(f, true);
		OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
		writer.append(6+" 字符型常量："+s+ "\r\n");
		writer.close();
		fop.close();
		if (!ezfxcl.contains(s)) {
			ezfxcl.add(s);
			File file = new File(CfenxiGUI.getStr()+"Changliang.txt");
			FileOutputStream fos = new FileOutputStream(file,true);
			OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
			w.append("字符型常量："+s+"\t"+6+"\r\n");
			w.close();
			fos.close();
		} else
			return;
	}
}
