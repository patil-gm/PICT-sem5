import java.net.*;
import java.io.*;
import java.util.*;
//open new terminal after running client file
// run server file in terminal (javac server.java)
// run command java server
//after receiving a msg send rply from server side


public class server {
    public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		ServerSocket ss = new ServerSocket(4999); 
		Socket s = ss.accept();
		
		System.out.println("client connected .....! ");

		String msg ;
		

			InputStreamReader in = new InputStreamReader(s.getInputStream());
			BufferedReader bf = new BufferedReader(in);
			String str = bf.readLine();
			System.out.println("client : "+str);


			PrintWriter pr = new PrintWriter(s.getOutputStream());
	        Scanner sc = new Scanner(System.in);
	      	String p =sc.next();
	      	pr.println(p);
	      	pr.flush();

	}

}

