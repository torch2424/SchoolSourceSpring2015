import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JFileChooser;

public class RegexClass
{

	/**
	 * Aaron Turner
	 * 
	 * March 11th, 2015
	 * 
	 * Date Due: March 18th, 2015
	 * 
	 * Purpose: This is supposed to read a file named scrabble.txt, and use
	 * regex to return 1. All of the words with two z's in a row. (385 words) 2.
	 * All of the words with two vowels in a row. (63864 word) 3. All of the
	 * words with more than two vowels in them. (132420 words) 4. All of the
	 * words with two x's in them. (16 words) 5. All of the words starting with
	 * 'Q' not followed by a 'U'. For this one item, write these words to a
	 * file. (25 words)
	 * 
	 * Input: scabble.txt
	 * 
	 * Output: 1. All of the words with two z's in a row. (385 words) 2. All of
	 * the words with two vowels in a row. (63864 word) 3. All of the words with
	 * more than two vowels in them. (132420 words) 4. All of the words with two
	 * x's in them. (16 words) 5. All of the words starting with 'Q' not
	 * followed by a 'U'. For this one item, write these words to a file. (25
	 * words)
	 * 
	 * 
	 */

	// Arraylist that we store lines of file inside of
	static ArrayList<String> allWords;

	public static void main(String[] args)
	{
		// Introduce the program to user
		System.out.println("Welcome to the Regex project!");
		System.out.println("Please enter the scrabble.txt file");

		// Our arraylist to hold our words
		allWords = new ArrayList<String>();
		ArrayList<String> twoZ = new ArrayList<String>();
		ArrayList<String> twoVowelsRow = new ArrayList<String>();
		ArrayList<String> threeVowels = new ArrayList<String>();
		ArrayList<String> twoX = new ArrayList<String>();
		ArrayList<String> qU = new ArrayList<String>();

		// Open our file chooser
		JFileChooser chooser = new JFileChooser();
		if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
		{
			// Get the file
			File selectedFile = chooser.getSelectedFile();
			if (selectedFile.getName().contentEquals("scrabble.txt"))
			{
				Scanner scan = null;
				try
				{
					scan = new Scanner(selectedFile);

					// Scan all of the words into all words
					while (scan.hasNextLine())
					{
						allWords.add(scan.nextLine());
					}

					// Regex for all words with two z's
					String regexString = "(zz)";
					Pattern regex = Pattern.compile(regexString);

					// Prepare our user for Matching
					System.out.println();
					System.out.println("Matching for words with two z's, Regex: (zz)");

					// Match the words (now since we can return number of
					// matches here)
					twoZ = findWords(regex);
					System.out.println("Found " + twoZ.size() + " Words");
					System.out.println();

					// DO NOT NEED TO PRINT THE MATCHES WE FIND, PROFESSOR SAYS
					// SO

					// Regex for all words with two vowels in a row
					regexString = "[aeiou]{2}";
					regex = Pattern.compile(regexString);

					// Prepare our user for Matching
					System.out.println();
					System.out
							.println("Matching for words with two vowels in a row, Regex: [aeiou]{2}");

					// Match the words (now since we can return number of
					// matches here)
					twoVowelsRow = findWords(regex);
					System.out.println("Found " + twoVowelsRow.size() + " Words");
					System.out.println();

					// Regex for all words with more than two vowels
					regexString = "[aeiou].*[aeiou].*[aeiou]";
					regex = Pattern.compile(regexString);

					// Prepare our user for Matching
					System.out.println();
					System.out
							.println("Matching for words with more than two vowels, Regex: [aeiou].*[aeiou].*[aeiou]");

					// Match the words (now since we can return number of
					// matches here)
					threeVowels = findWords(regex);
					System.out.println("Found " + threeVowels.size() + " Words");
					System.out.println();

					// Regex for all words with two x's
					regexString = "[x].*[x]";
					regex = Pattern.compile(regexString);

					// Prepare our user for Matching
					System.out.println();
					System.out.println("Matching for words with two x's, Regex: [x].*[x]");

					// Match the words (now since we can return number of
					// matches here)
					twoX = findWords(regex);
					System.out.println("Found " + twoX.size() + " Words");
					System.out.println();

					// Regex for all words starting with q, but not follewed by
					// U
					regexString = "^[Qq][^uU]";
					regex = Pattern.compile(regexString);

					// Prepare our user for Matching
					System.out.println();
					System.out
							.println("Matching for words the start with q, but are not follwed by U, Regex: ^[Qq][^uU]");

					// Match the words (now since we can return number of
					// matches here)
					qU = findWords(regex);
					System.out.println("Found " + qU.size() + " Words");
					System.out.println();

					// Now save the words to a file
					// First create the File, using the directory the user
					// launched the app
					File regexFile = new File(System.getProperty("user.dir") + "/RegexProject.txt");

					// Create our FileWriter and print to file
					FileWriter writer = null;
					try
					{
						// Using file writer
						writer = new FileWriter(regexFile, true);
						// Print the words we found
						for (int i = 0; i < qU.size(); ++i)
						{
							writer.write(qU.get(i));
							writer.write(System.getProperty("line.separator"));
						}
					}
					catch (IOException baseball)
					{
						// In case we can not create or find the file
						System.out
								.println("File could not be found or created, please ask for assistance!");
					}
					finally
					{
						// finish and close our filewriter
						try
						{
							writer.close();
							//Inform the user their file has been saved
							//Inform user of success
							System.out.println("File successfuly saved at: " + regexFile.getAbsolutePath());
							System.out.println("The found matches of words that start with Q but are not" +
									"followed by a U are in the file. Thank you for using this application!");
						}
						catch (IOException baseball)
						{
							// In case we could not close the writer
							System.out
									.println("File could not be found or created, please ask for assistance!");
						}
					}

				}
				catch (FileNotFoundException e)
				{
					e.printStackTrace();
					System.out
							.println("Sorry, but the file could not be found! Please try this application again!");
				}
				finally
				{
					scan.close();
				}
			}
			else
			{
				// They did not open scrabble.txt, warn them, and tell them to
				// re-open program
				System.out
						.println("Unfortunately, that is the incorrect file, this application accepts scrabble.txt");
				System.out
						.println("Please run this application again, and select the correct file!");
			}
		}
		else
		{
			// They did not open scrabble.txt, warn them, and tell them to
			// re-open program
			System.out.println("Unfortunately, the file was not approved by the file chooser...");
			System.out.println("Please run this application again, and select the correct file!");
		}

	}

	private static ArrayList<String> findWords(Pattern regex)
	{
		// Start the loop to loop through for loop
		ArrayList<String> tempArray = new ArrayList<String>();
		for (int i = 0; i < allWords.size(); ++i)
		{
			// Match for the word
			String tempString = allWords.get(i);
			Matcher m = regex.matcher(allWords.get(i));
			if (m.find())
			{
				// Add it to our arraylist
				tempArray.add(tempString);
			}
		}

		// Return our array
		return tempArray;
	}

}
