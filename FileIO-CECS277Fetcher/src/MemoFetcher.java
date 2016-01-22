import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javax.swing.JFileChooser;

public class MemoFetcher
{

	/**
	 * Aaron Turner
	 * 
	 * Febuary 18th, 2015
	 * 
	 * Purpose: This is supposed to retrieved the title, text, and date stamp of
	 * a memo which is first saved by a companion application
	 * 
	 * Input: The memo.txt file
	 * 
	 * Output: The memos
	 */
	public static void main(String[] args)
	{
		// Introduce the program to user
		System.out.println("Welcome to the Memo Fetcher Application!");
		System.out.println("Please enter the memo file('memo.txt'):");

		// Open our file chooser
		JFileChooser chooser = new JFileChooser();
		if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
		{
			// Get the file
			File selectedFile = chooser.getSelectedFile();
			if (selectedFile.getName().contentEquals("memo.txt"))
			{
				// Boolean that user is reading memos, scanner to get our memo
				// and user input
				boolean reading = true;
				Scanner scan = null;
				Scanner input = null;
				// Number to display the current memo
				int memoNum = 0;
				try
				{
					// Create loop to keep reading until user runs out of memos
					// or
					// doesn't want to read anymore
					scan = new Scanner(selectedFile);
					input = new Scanner(System.in);
					while (reading)
					{
						// Increment the memoNumber
						++memoNum;
						// Println for formatting
						System.out.println();
						// Display the memo number, it's title, text, and date
						System.out.println("Memo #" + memoNum + ": ");
						System.out.println("Title: " + scan.nextLine());
						System.out.println("Text: " + scan.nextLine());
						System.out.println("Date: " + scan.nextLine());
						System.out.println();
						// If there are more memos, ask if they would like to
						// view the next one
						if (scan.hasNextLine())
						{
							System.out.println("Would you like to view the next memo? Y/N");
							// If they do not enter yes (uppercase Y) we will
							// assume no, and exit the application
							if (!input.nextLine().toUpperCase().contentEquals("Y"))
							{
								reading = false;
								System.out.println("Thank you for using the Memo Fetcher!");
								System.out
										.println("To open your memo, please run this application again!");
							}
						}
						else
						{
							// If there are no more memos, inform theme and exit
							// the application
							reading = false;
							System.out.println("No next memo...");
							System.out.println("Thank you for using the Memo Fetcher!");
							System.out
									.println("To open your memo, please run this application again!");
						}

					}
				}
				catch (FileNotFoundException e)
				{
					System.out.println("Unfortunately, the file could not be found...");
					System.out.println("To open your memo, please run this application again!");
				}
				finally
				{
					// Close the scanner
					scan.close();
					input.close();
				}
			}
			else
			{
				// They did not open memo.txt, warn them, and tell them to
				// re-open program
				System.out
						.println("Unfortunately, that is the incorrect file, this application accepts memo.txt");
				System.out.println("To open your memo, please run this application again!");
			}
		}
		else
		{
			// They cancelled the dialog, tell them to re-open the program if
			// they want to use it still
			System.out.println("Thank you for using the Memo Fetcher!");
			System.out.println("To open your memo, please run this application again!");
		}

	}

}
