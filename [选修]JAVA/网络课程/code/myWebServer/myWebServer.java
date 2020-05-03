import java.io.*;
import java.net.*;

public class myWebServer
{
    public static void main(String []args) throws Exception{
            //提示连接情况
            System.out.println("waiting at port 9999");
        ServerSocket ss=new ServerSocket(9999);
            Socket s=ss.accept();

            OutputStream os=s.getOutputStream();
            BufferedReader br=new BufferedReader(new FileReader("D:\\test.html"));
            String buf="";
            while((buf=br.readLine())!=null){
                os.write(buf.getBytes());
            }
        //close IO stream
        br.close();
        os.close();
        s.close();
    }
}