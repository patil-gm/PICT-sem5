import java.net.*;
import java.util.Scanner;
import java.io.*;

//open terminal run code (javac client.java)
//after running command=>(java server) in server terminal Run command =>(java client) on client terminal
//this shows a message "client connected .....! " on server terminal
//enter the string to send


public class client {
    public static void main(String[] args) throws IOException {

        Socket s=new Socket ("localhost",4999);
        
        Scanner sc = new Scanner(System.in);
        
        String msg;

			PrintWriter pr = new PrintWriter(s.getOutputStream());
			msg = sc.next();
			pr.println(msg);
			pr.flush();
			
			
			InputStreamReader ip = new InputStreamReader(s.getInputStream());
			BufferedReader bf = new BufferedReader(ip);
			String str = bf.readLine();
			
			System.out.println("server : "+str);
        

        sc.close();
        s.close();
        
        
        
        
	}
}

