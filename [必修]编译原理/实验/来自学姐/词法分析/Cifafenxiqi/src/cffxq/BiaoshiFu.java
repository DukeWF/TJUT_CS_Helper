package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class BiaoshiFu {
	private static List<String> ebsf = new ArrayList<String>();

	public BiaoshiFu(String s) throws IOException {
			File f = new File(CfenxiGUI.getStr()+"output.txt");
			FileOutputStream fos = new FileOutputStream(f, true);
			OutputStreamWriter writer = new OutputStreamWriter(fos, "UTF-8");
			writer.append(0+" 标识符："+s+ "\r\n");
			writer.close();
			fos.close();
			if (!ebsf.contains(s)) {
				ebsf.add(s);
				File file = new File(CfenxiGUI.getStr()+"Fuhao.txt");
				FileOutputStream fop = new FileOutputStream(file,true);
				OutputStreamWriter w = new OutputStreamWriter(fop,"UTF-8");
				w.append("标识符："+s+"\t"+0+ "\r\n");
				w.close();
				fop.close();
			} else
				return;
	}
}