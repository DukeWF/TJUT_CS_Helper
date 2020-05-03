package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Touwenjian {
public Touwenjian(String s) throws IOException{
	File file = new File(CfenxiGUI.getStr()+"output.txt");
	FileOutputStream fop = new FileOutputStream(file,true);
	OutputStreamWriter writer = new OutputStreamWriter(fop,"UTF-8");
	writer.append("Í·ÎÄ¼þ£º"+s+ "\r\n");
	writer.close();
	fop.close();
}
}
