package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class FudianxingCL {
	private static List<String> efsxcl = new ArrayList<String>();

	public FudianxingCL(String s) throws IOException {
		File f = new File(CfenxiGUI.getStr()+"output.txt");
		FileOutputStream fop = new FileOutputStream(f, true);
		OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
		writer.append(2+" 浮点型常量："+s+"\r\n");
		writer.close();
		fop.close();
		if (!efsxcl.contains(s)) {
			efsxcl.add(s);
			File file = new File(CfenxiGUI.getStr()+"Changliang.txt");
			FileOutputStream fos = new FileOutputStream(file,true);
			OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
			w.append("浮点型常量："+s+"\t"+2+"\r\n");
			w.close();
			fos.close();
		} else
			return;
	}
}
