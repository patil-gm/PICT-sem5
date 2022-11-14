//This code is for establishing connection with MySQL
//database and retrieving data
//from db Java Database connectivity

/*
*1. import --->java.sql
*2. load and register the driver ---> com.jdbc.
*3. create connection
*4. create a statement
*5. execute the query
*6. process the results
*7. close
*/

package mock1;
import java.sql.*;
import java.util.Scanner;

public class JDBC {

	public static void main(String[] args) throws Exception{
		
		Connection connection = null;
		
			// below two lines are used for connectivity.
			Class.forName("com.mysql.cj.jdbc.Driver");
            String url="jdbc:mysql://localhost:3306/student";
            String uname="root";
            String pass="gmp123";

            connection = DriverManager.getConnection(url,uname,pass);


			Statement statement;
			statement = connection.createStatement();

			ResultSet resultSet;
			
			Scanner sc = new Scanner(System.in);

			while(true) {
				System.out.println("\nMain Menu\n1. Create table\n2. Read table\n3. Update\n4. Delete\n5. Exit\n");
				System.out.print("Enter the choice: ");
				int choice = sc.nextInt();
				
				if(choice==1) { // create table
					System.out.print("Enter the name of table to create: ");
					String tableName = sc.next();
					System.out.print("Enter number of fields in table");
					int nFields = sc.nextInt();
					String createTableQuery = "CREATE TABLE "+ tableName +" (";
					String cols[] = new String[nFields];
					
					for(int i=0; i<nFields; i++) {
						System.out.print("Enter the name of column " + i + ": ");
						cols[i] = sc.next();
						System.out.print("Enter the datatype for column " + cols[i] + ": ");
						String dataType = sc.next();
						if(i!=nFields-1) createTableQuery+= cols[i]+" "+dataType+", ";
						else createTableQuery+= cols[i]+" "+dataType;
					}
					
					createTableQuery+=");";
					System.out.println(createTableQuery);
					statement.executeUpdate(createTableQuery);
				} else if(choice==2) { // read
					System.out.println("Enter the name of table to read: ");
					String tableName = sc.next();
					String readTableQuery = "SELECT * FROM " + tableName + ";";
					
					resultSet = statement.executeQuery(readTableQuery);
					
					ResultSetMetaData resultSetMetaData = resultSet.getMetaData();
					
					int colCount = resultSetMetaData.getColumnCount();
					for(int i=1; i<=colCount; i++) {
						System.out.print(resultSetMetaData.getColumnName(i)+"\t"); 
					}
					System.out.println(" ");
					while(resultSet.next()) {
						System.out.print("\n");
						for(int i=1; i<=colCount; i++) {
							System.out.print(resultSet.getString(i)+"\t");
						}
					}
					System.out.println(" ");
					System.out.println(" ");
					
				} else if(choice==3) { // update
					System.out.print("Enter the table you want to update: ");
					String tableName = sc.next();
					String readTableQuery = "SELECT * FROM " + tableName + ";";
					
					resultSet = statement.executeQuery(readTableQuery);
					
					ResultSetMetaData resultSetMetaData = resultSet.getMetaData();
					
					int colCount = resultSetMetaData.getColumnCount();
					for(int i=1; i<=colCount; i++) {
						System.out.print(i + " " + resultSetMetaData.getColumnName(i)+"\t"); 
					}
					
					System.out.println("Select the column you want to update: ");
					int colToUpdate = sc.nextInt();
					
					System.out.println("Enter the updated value: ");
					String afterUpdate = sc.next();
					
					System.out.println("Enter the updation rule: ");
					String updateRule = sc.next();
					
					String updateTableQuery = "UPDATE " + tableName + " SET " + 
					resultSetMetaData.getColumnName(colToUpdate) + "=" +  afterUpdate + " WHERE " +
					updateRule;
					
					System.out.println(updateTableQuery);
					statement.executeUpdate(updateTableQuery);
				} else if(choice==4) { // delete
					System.out.println("this features is in progress we will get you soon .....! :)");
					
				} else if(choice==5) {
					System.out.println("Exiting...");
					break;
				}
			}
			
			

			statement.close();
			connection.close();
		
		
		
	}

}
