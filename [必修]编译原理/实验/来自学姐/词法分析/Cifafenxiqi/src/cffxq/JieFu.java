package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class JieFu {
	private String[] jf = { "{", "}", "<", ">", "(", ")", "[", "]", "/*", "*/", "\"", "'", ";",",",":","#"};
	private List<String> jfl = Arrays.asList(jf);
	private static List<String> ejf = new ArrayList<String>();
	
	public JieFu(String s) throws IOException {
		if (jfl.contains(s)) {
			File f = new File(CfenxiGUI.getStr()+"output.txt");
			FileOutputStream fop = new FileOutputStream(f, true);
			OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
			writer.append(100+jfl.indexOf(s)+" ½ç·û£º" + s + "\r\n");
			writer.close();
			fop.close();
			if (!ejf.contains(s)) {
				ejf.add(s);
				File file = new File(CfenxiGUI.getStr()+"Fuhao.txt");
				FileOutputStream fos = new FileOutputStream(file,true);
				OutputStreamWriter w = new OutputStreamWriter(fos,"UTF-8");
				w.append("½ç·û£º"+s+"\t"+(100+jfl.indexOf(s))+"\r\n");
				w.close();
				fos.close();
			}
			else return;
		}
		else return;
	}

}
