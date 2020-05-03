package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class ZhengxingCL {
	private static List<String> ezxcl = new ArrayList<String>();

	public ZhengxingCL(String s) throws IOException {
		File f = new File(CfenxiGUI.getStr()+"output.txt");
		FileOutputStream fop = new FileOutputStream(f, true);
		OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
		writer.append(4+" 整型常量："+s+ "\r\n");
		writer.close();
		fop.close();
		if (!ezxcl.contains(s)) {
			ezxcl.add(s);
			File file = new File(CfenxiGUI.getStr()+"Changliang.txt");
			FileOutputStream fos = new FileOutputStream(file,true);
			OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
			w.append("整型常量："+s+"\t"+4+"\r\n");
			w.close();
			fos.close();
		} else
			return;
	}
}
