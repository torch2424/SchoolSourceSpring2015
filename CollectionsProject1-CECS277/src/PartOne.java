import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;

import javax.swing.JFileChooser;

/**
 * 
 */

/**
 * Aaron Turner
 * 
 * March 23rd, 2015
 * 
 * Due: April 6th, 2015
 * 
 * Purpose: This is supposed to retrieve the words that start with Q not
 * followed by U in a file, then create file with the values with those words,
 * read them into a map data structure, then find the point value of each of the
 * words and print it out
 * 
 * Input: The words that start with Q not followed by U
 * 
 * Output: The point value of the words
 */
public class PartOne
{

	public static void main(String[] args)
	{
		// Initiliaze our variables
		ArrayList<String> words = new ArrayList<String>();
		ArrayList<ArrayList<String>> letterValues = new ArrayList<ArrayList<String>>();
		// Fill out letter values array
		fillValues(letterValues);
		// Introduce the program to user
		System.out.println("Welcome to Part One of the Collections Application!");
		System.out.println("Please enter the words that start with Q not followed by U file:");

		// Open our file chooser
		JFileChooser chooser = new JFileChooser();
		if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
		{
			// Get the file
			File selectedFile = chooser.getSelectedFile();

			// Read in our words
			Scanner scan = null;

			// Our printwriter for printing our values to a file
			PrintWriter pw = null;

			try
			{
				// Initialize our scanner
				scan = new Scanner(selectedFile);

				// Read each word into our array
				while (scan.hasNextLine())
				{
					words.add(scan.nextLine());
				}

				// Now save the letter values into a file
				File values = new File(System.getProperty("user.dir") + "/lettervalues.txt");

				// create a new writer
				pw = new PrintWriter(values);

				// Print our values to the file
				for (int i = 0; i < letterValues.size(); ++i)
				{
					// Show which point value we are showing
					pw.print(i + " point(s): ");
					// now display the letters
					for (int j = 0; j < letterValues.get(i).size(); ++j)
					{
						// Print a comma and a space if it isnt the last value
						if (j != letterValues.get(i).size())
						{
							pw.print(letterValues.get(i).get(j) + ", ");
						}
						else
						{
							pw.print(letterValues.get(i).get(j));
						}
					}
					// Finally print some new lines for formatting after every
					// point value
					pw.println();
					pw.println();
				}

				// Inform user done with file I/O
				System.out
						.println("Finished our File I/O! Read in our words, and printed letter values to a"
								+ "file at: " + values.getAbsolutePath());

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
				// Close the printwriter
				pw.close();
			}
		}

		// Now start the map
		System.out.println();
		System.out.println("Now Creating our Map to be printed!");

		// Create a hash map
		TreeMap<String, Integer> tm = new TreeMap<String, Integer>();

		// Put our letter values to the map
		for (int i = 0; i < letterValues.size(); ++i)
		{
			for (int j = 0; j < letterValues.get(i).size(); ++j)
			{
				// Put the letter of the index, and match it with the
				// point value that is the first index
				tm.put(letterValues.get(i).get(j), i);
			}
		}

		// Finally get each word, and print it's value
		int value = 0;

		for (int i = 0; i < words.size(); ++i)
		{
			// First we get every word
			for (int j = 0; j < words.get(i).length(); ++j)
			{
				// Now we are getting every letter (uppercase)
				// Match each letter to a vlue, and add it to the total
				// need to return string here
				value = value + tm.get(String.valueOf(words.get(i).charAt(j)).toUpperCase());
			}

			// Display our word and value
			System.out.println(words.get(i) + " has the value of: " + value);

			// Reset the value
			value = 0;
		}

		// Finish and exit
		System.out.println();
		System.out.println("Thank you for using Part One of the Collections Application!");
	}

	private static void fillValues(ArrayList<ArrayList<String>> array)
	{
		// 0 points
		// Using temp array and then adding it to our dimensional array
		ArrayList<String> tempArray = new ArrayList<String>();
		// add our elements
		tempArray.add(" ");
		// Add to final array
		array.add(tempArray);

		// 1 point
		tempArray = new ArrayList<String>();
		tempArray.add("A");
		tempArray.add("E");
		tempArray.add("I");
		tempArray.add("L");
		tempArray.add("N");
		tempArray.add("O");
		tempArray.add("R");
		tempArray.add("S");
		tempArray.add("T");
		tempArray.add("U");
		array.add(tempArray);

		// 2 points
		tempArray = new ArrayList<String>();
		tempArray.add("D");
		tempArray.add("G");
		array.add(tempArray);

		// 3 points
		tempArray = new ArrayList<String>();
		tempArray.add("B");
		tempArray.add("C");
		tempArray.add("M");
		tempArray.add("P");
		array.add(tempArray);

		// 4 points
		tempArray = new ArrayList<String>();
		tempArray.add("F");
		tempArray.add("H");
		tempArray.add("V");
		tempArray.add("W");
		tempArray.add("Y");
		array.add(tempArray);

		// 5 points
		tempArray = new ArrayList<String>();
		tempArray.add("K");
		array.add(tempArray);

		// Add some spacers to increase index for when we add to our map
		array.add(new ArrayList<String>());
		array.add(new ArrayList<String>());

		// 8 points
		tempArray = new ArrayList<String>();
		tempArray.add("J");
		tempArray.add("X");
		array.add(tempArray);

		// Add some spacers to increase index for when we add to our map
		array.add(new ArrayList<String>());

		// 10 points
		tempArray = new ArrayList<String>();
		tempArray.add("Q");
		tempArray.add("Z");
		array.add(tempArray);
	}

}
