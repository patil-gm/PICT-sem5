package mock1;

/*
//This code is for establishing connection with MySQL
//database and retrieving data
//from db Java Database connectivity

*1. import --->java.sql
*2. load and register the driver ---> com.jdbc.
*3. create connection
*4. create a statement
*5. execute the query
*6. process the results
*7. close


Schema:
Football(PlayerName,ClubName, Price)

*/

import java.util.*;
import java.io.IOException;
import java.sql.*;

public class  JDBC {
	public static void main(String[] args) throws SQLException, IOException{
		Scanner sc = new Scanner(System.in);
		Connection con =null;
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
            String url="jdbc:mysql://localhost:3306/student";
            String uname="root";
            String pass="gmp123";

            con = DriverManager.getConnection(url,uname,pass);
		}
		catch(Exception e) {
			
		}
		
		PreparedStatement ps = con.prepareStatement("create table Football("
				+ "PlayerName varchar(50),"
				+ "ClubName varchar(50),"
				+ "Price bigint"
				+ ");");
		
		int res = ps.executeUpdate();
		
		System.out.println("Table Football created successfully...");
		
		char ch = 'Y';
		while(ch=='Y' || ch=='y') {
			System.out.println("1. Display All Records");
			System.out.println("2. Insert Records");
			System.out.println("3. Update Records");
			System.out.println("4. Delete Records");
			int c = sc.nextInt();
			switch(c) {
			case 1:
				display(con);
				break;
			case 2:
				insert(con,sc);
				display(con);
				break;
			case 3:
				update(con,sc); 
				display(con);
				break;
			case 4:
				delete(con,sc);
				display(con);
				break;
			default:
				System.out.println("Enter correct choice!!");
				break;
			}
			System.out.println("Do you want to continue?[Y/N]");
			ch = sc.next().charAt(0);
		}
		
		

		ps = con.prepareStatement("drop table Football;");
		
		res = ps.executeUpdate();
		System.out.println("Table Football dropped successfully...");
		
		sc.close();
		con.close();
		
	}
	public static void insert(Connection con,Scanner sc) throws SQLException {
		System.out.println("Enter Number of Records to Insert: ");
		int n = sc.nextInt();
		PreparedStatement ps = null;
		while(n-->0) {
			System.out.println("Enter PlayerName: ");
			String pname = sc.next();
			System.out.println("Enter ClubName: ");
			String cname = sc.next();
			System.out.println("Enter Price:");
			long price = sc.nextLong();
			ps = con.prepareStatement("insert into Football values ('"
					+ pname +"','"+cname+"',"+price+");");
			int result = ps.executeUpdate();
			System.out.println(result +" records inserted..");
		}
		
	}
	public static void update(Connection con,Scanner sc) throws SQLException{
		System.out.println("Enter Number of Records to Update: ");
		int n = sc.nextInt();
		PreparedStatement ps = null;
		while(n-->0) {
			System.out.println("Enter PlayerName: ");
			String pname = sc.next();
			System.out.println("Enter New ClubName: ");
			String cname = sc.next();
			System.out.println("Enter New Price:");
			long price = sc.nextLong();
			ps = con.prepareStatement("update Football set ClubName = '" + cname+"', Price = "
					+ price+" where PlayerName = '"+pname+"';");
			int result = ps.executeUpdate();
			System.out.println(result +" records updated..");
		}
	}

	public static void delete(Connection con,Scanner sc) throws SQLException{
		System.out.println("Enter Number of Records to Delete: ");
		int n = sc.nextInt();
		PreparedStatement ps = null;
		while(n-->0) {
			System.out.println("Enter PlayerName to delete: ");
			String pname = sc.next();
			ps = con.prepareStatement("delete from Football where PlayerName = '"
					+ pname+ "';");
			int result = ps.executeUpdate();
			System.out.println(result +" records deleted..");
		}
	}

	public static void display(Connection con) throws SQLException{
		PreparedStatement ps = con.prepareStatement("select * from Football;");
		ResultSet rs = ps.executeQuery();
		System.out.println("PlayerName\tClubName\tPrice\t");
		while(rs.next()) {
			System.out.println(rs.getString(1)+"\t\t"+rs.getString(2)+"\t\t"+rs.getLong(3)+"\t\t");
		}
	}

}
