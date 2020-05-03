package cffxq;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Zhushi {
public Zhushi(String s) throws IOException{
	File f = new File(CfenxiGUI.getStr()+"output.txt");
	FileOutputStream fos = new FileOutputStream(f,true);
	OutputStreamWriter writer = new OutputStreamWriter(fos,"UTF-8");
	writer.append("×¢ÊÍ£º"+s+"\r\n");
	writer.close();
	fos.close();
}
}
