package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class ZifuchuanxingCL {
	private static List<String> ezfcxCL = new ArrayList<String>();

	public ZifuchuanxingCL(String s) throws IOException {
		File f = new File(CfenxiGUI.getStr()+"output.txt");
		FileOutputStream fop = new FileOutputStream(f, true);
		OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
		writer.append(5+" 字符串型常量："+s+ "\r\n");
		writer.close();
		fop.close();
		if (!ezfcxCL.contains(s)) {
			ezfcxCL.add(s);
			File file = new File(CfenxiGUI.getStr()+"Changliang.txt");
			FileOutputStream fos = new FileOutputStream(file,true);
			OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
			w.append("字符创型常量："+s+"\t"+5+"\r\n");
			w.close();
			fos.close();
		} else
			return;
	}
}
