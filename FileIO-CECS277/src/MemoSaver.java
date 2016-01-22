import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.util.Scanner;


public class MemoSaver 
{

	/**
	 * Aaron Turner
	 * 
	 * Febuary 18th, 2015
	 * 
	 * Purpose: This is supposed to save the title, text, and date stamp of a memo which can later
	 * be retrieved by a companion application
	 * 
	 * Input: The title, and text of the memo
	 * 
	 * Output: Confirmation of save, and contents of memo
	 */
	public static void main(String[] args) 
	{
		//Initialize variables
		String title;
		String text;
		Date timeStamp;
		Scanner input = new Scanner(System.in);
		//Introduce the program to user
		System.out.println("Welcome to the Memo Saver Application!");
		System.out.println("Please enter the title of your memo:");

		//Get the title
		title = input.nextLine();
		
		//Get our text
		System.out.println("Please enter the text of your memo:");
		text = input.nextLine();
		
		//Save the memo
		//First create the File, using the directory the user launched the app
		File memo = new File(System.getProperty("user.dir") + "/memo.txt");
		
		//Create our FileWriter and print to memo
		FileWriter writer = null;
		try
		{
			//Using file writer to append to text instead of replacing it
			writer = new FileWriter(memo, true);
			//Print title text and date stamp, using line seperator to create new lines
			writer.write(title);
			writer.write(System.getProperty( "line.separator" ));
			writer.write(text);
			writer.write(System.getProperty( "line.separator" ));
			timeStamp = new Date();
			writer.write(timeStamp.toString());
			writer.write(System.getProperty( "line.separator" ));
		}
		catch (IOException baseball)
		{
			//In case we can not create or find the file
			System.out.println("File could not be found or created, please ask for assistance!");
		}
		finally
		{
			//finish and close our filewriter
			try
			{
				writer.close();
			}
			catch (IOException baseball)
			{
				//In case we could not close the writer
				System.out.println("File could not be found or created, please ask for assistance!");
			}
		}
		
		//Inform user of success
		System.out.println("Memo successfuly saved at: " + memo.getAbsolutePath());
		System.out.println("Use the memo fetcher program to view your memos!");
		//Close our input scanner
		input.close();
		
	}

}
