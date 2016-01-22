import java.util.LinkedList;
import java.util.Queue;

public class Tester
{

	/**
	 * Aaron Turner
	 * 
	 * April 11th, 2015
	 * 
	 * Date Due: April 15th, 2015
	 * 
	 * Purpose: This is supposed to send commands to the WPICLASS, and use it's
	 * functions to show that we have implemented and successfully used a stack
	 * to create a word processor.
	 * 
	 * Input: N/A
	 * 
	 * Output: The results of the commands we inputed to the WPICLASS
	 * 
	 * 
	 */
	public static void main(String[] args)
	{
		// Welcome the user to the program
		System.out.println("Welcome to the Mini WPI Application!");
		System.out.println("We will now fill a queue with commands and exectue them!");

		// Create our class, using the word javajava
		WPIClass wpi = new WPIClass("javajava");

		// Create a queue
		Queue<String> q = new LinkedList<String>();

		// Add commands to our queue (At least one for every function)
		q.add("toStringCursor");
		q.add("moveRight");
		q.add("moveLeft");
		q.add("atStart");
		q.add("atEnd");
		q.add("insertChar s");
		q.add("moveRight");
		q.add("backspace");
		q.add("moveRight");
		q.add("delete");
		q.add("moveToEnd");
		q.add("moveToStart");
		q.add("toString");
		q.add("toStringCursor");
		q.add("search v");
		q.add("search j");
		q.add("iqwohrfnlskanflk");
		q.add("moveToEnd");
		q.add("backspace");
		q.add("backspace");
		q.add("backspace");
		q.add("backspace");
		q.add("backspace");
		q.add("backspace");
		q.add("backspace");
		q.add("backspace");

		// Run our commands through our class with a loop
		while (!q.isEmpty())
		{
			wpi.processCommand(q.poll());
		}

		// Inform user of end of program
		System.out.println();
		System.out.println("Thank you for using the Mini WPI Application!");
	}

}
