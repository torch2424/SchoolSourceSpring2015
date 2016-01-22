import java.io.File;
import java.io.FileNotFoundException;
import java.util.Date;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

import javax.swing.JFileChooser;

public class PartTwo
{

	/**
	 * Aaron Turner
	 * 
	 * March 23rd, 2015
	 * 
	 * Due: April 6th, 2015
	 * 
	 * Purpose: This is supposed to retrieve the words from a large text file
	 * and place them in both a tree set and a hash set. We are supposed to time
	 * both of them to see which is faster, and print it to the user
	 * 
	 * Input: The large text file
	 * 
	 * Output: The amount of time for the words to be placed in each set
	 */
	public static void main(String[] args)
	{
		// Initiliaze our variables, hash set and treeset
		HashSet<String> theHash = new HashSet<String>();
		TreeSet<String> theTree = new TreeSet<String>();

		// Introduce the program to user
		System.out.println("Welcome to Part Two of the Collections Application!");
		System.out.println("Please enter a large .txt file:");

		// Open our file chooser
		JFileChooser chooser = new JFileChooser();
		if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
		{
			// Get the file
			File selectedFile = chooser.getSelectedFile();

			// initialize our scanner
			Scanner scan = null;

			try
			{
				//Get our file
				scan = new Scanner(selectedFile);
				
				//Start our hash set first
				System.out.println("Now adding words to Hash Set!");
				
				//Get our date
				Date today = new Date();
				//Create our time variables
				long time1, time2;
				//Get our beginning time
				time1=System.nanoTime();
				
				System.out.println("Hash Set beginning time is: " + time1 + " nanoseconds.");
				
				//Start our loop and fill the set
				while(scan.hasNextLine())
				{
					theHash.add(scan.nextLine());
				}
				
				//Get our final time
				time2=System.nanoTime();
				System.out.println("Hash Set ending time is: " + time2 + " nanoseconds.");
				
				System.out.println("Hash Set total operation time is: " + (time2 - time1)
						+ " nanoseconds.");
				
				//Now our tree set
				System.out.println();
				System.out.println("Now adding words to Tree Set!");
				
				//Get our beginning time
				time1=System.nanoTime();
				
				System.out.println("Tree Set beginning time is: " + time1 + " nanoseconds.");
				
				//Start our loop and fill the set
				while(scan.hasNextLine())
				{
					theTree.add(scan.nextLine());
				}
				
				//Get our final time
				time2=System.nanoTime();
				System.out.println("Tree Set ending time is: " + time2 + " nanoseconds.");
				
				System.out.println("Tree Set total operation time is: " + (time2 - time1)
						+ " nanoseconds.");
				
			}
			catch (FileNotFoundException e)
			{
				System.out.println("Unfortunately, the file could not be found...");
				System.out.println("Please run this application again!");
			}
			finally
			{
				// Close the scanner
				scan.close();
			}
			
			//Finish and exit
			System.out.println();
			System.out.println("Thank you for using Part Two of the Collections Application!");
		}

	}

}
