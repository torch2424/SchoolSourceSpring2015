import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JFileChooser;

public class Fetcher
{

	/**
	 * Aaron Turner
	 * 
	 * April 20th, 2015
	 * 
	 * Date Due: April 27th, 2015
	 * 
	 * Purpose: This is supposed to grab vanilla, chocolate, and strawberry ice
	 * cream cone objects from a file, and ask the user which they would like
	 * 
	 * Input: The ice cream cone they would like to see
	 * 
	 * Output: the ice cream cone they selected
	 * 
	 * 
	 */
	public static void main(String[] args)
	{
		// Welcome user to the program
		System.out.println("Welcome to the Ice Cream Object Saver!");
		System.out.println("We will now get the three Ice Cream Cones!");

		// Get the ice cream cones from the file
		// Open our file chooser
		JFileChooser chooser = new JFileChooser();
		if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
		{
			// Get the file
			File selectedFile = chooser.getSelectedFile();

			// Make sure it is the correct file
			if (selectedFile.getName().contentEquals("ice.cream"))
			{

				// Create our cones
				AdvancedIceCreamCone cone1;
				AdvancedIceCreamCone cone2;
				AdvancedIceCreamCone cone3;

				/*
				 * This reads our files and deserilizes our object, which then
				 * sets it to our cones
				 */
				FileInputStream fileIn = null;
				ObjectInputStream in = null;
				Scanner input = null;
				try
				{
					fileIn = new FileInputStream(selectedFile);
					in = new ObjectInputStream(fileIn);
					// Read in all of our objects
					cone1 = (AdvancedIceCreamCone) in.readObject();
					cone2 = (AdvancedIceCreamCone) in.readObject();
					cone3 = (AdvancedIceCreamCone) in.readObject();

					// Sort our objects into an array by their flavor
					ArrayList<AdvancedIceCreamCone> cones = new ArrayList<AdvancedIceCreamCone>();

					//Check each Cone for their flavor
					if (cone1.getFlavor().contentEquals("vanilla"))
					{
						cones.add(cone1);
						if (cone2.getFlavor().contentEquals("chocolate"))
						{
							cones.add(cone2);
							cones.add(cone3);
						}
						else
						{
							cones.add(cone3);
							cones.add(cone2);
						}
					}
					else if (cone2.getFlavor().contentEquals("vanilla"))
					{
						cones.add(cone2);
						if (cone1.getFlavor().contentEquals("chocolate"))
						{
							cones.add(cone1);
							cones.add(cone3);
						}
						else
						{
							cones.add(cone3);
							cones.add(cone1);
						}
					}
					else
					{
						cones.add(cone3);
						if (cone2.getFlavor().contentEquals("chocolate"))
						{
							cones.add(cone2);
							cones.add(cone1);
						}
						else
						{
							cones.add(cone1);
							cones.add(cone2);
						}
					}

					// Now Start the UI for user
					boolean menu = true;
					input = new Scanner(System.in);

					while (menu)
					{
						System.out
						.println();
						System.out
						.println("---Main Menu---");
						System.out
						.println();
						System.out
						.println("1. View Vanilla Ice Cream");
						System.out
						.println("2. View Chocolate Ice Cream");
						System.out
						.println("3. View Strawberry Ice Cream");
						System.out
						.println("4. Exit");
						System.out
						.println();
						System.out
						.println("Please select an option");
						System.out
						.println();
						
						//Get our input
						String user = input.nextLine();
						
						//Check our input with out options
						if(user.contentEquals("1"))
						{
							//Print the cone to the user
							System.out
							.println(cones.get(0).toString());
							System.out
							.println();
						}
						else if(user.contentEquals("2"))
						{
							//Print the cone to the user
							System.out
							.println(cones.get(1).toString());
							System.out
							.println();
						}
						else if(user.contentEquals("3"))
						{
							//Print the cone to the user
							System.out
							.println(cones.get(2).toString());
							System.out
							.println();
						}
						else if(user.contentEquals("4"))
						{
							//Thank the user and exit program
							System.out
							.println("Thank you for using the Ice Cream Fetcher Application!");
							
							menu = false;
						}
						else
						{
							//The input was incorrect
							System.out
							.println("That is not a valid option...");
							System.out
							.println();
						}
			
					}

				}
				catch (IOException | ClassNotFoundException baseball)
				{
					// In case we can not create or find the file
					System.out
							.println("File could not be found or created, or the class was not found,"
									+ "please ask for assistance!");
				}
				finally
				{
					try
					{
						in.close();
						fileIn.close();
						input.close();
					}
					catch (IOException e)
					{
						// TODO Auto-generated catch block
						e.printStackTrace();
						// In case we can not create or find the file
						System.out
								.println("Unfortunately, there was an IO error, please ask for assistance!");
					}
				}
			}
			else
			{
				// They did not open ice.cream, warn them, and tell them to
				// re-open program
				System.out
						.println("Unfortunately, that is the incorrect file, this application accepts ice.cream");
				System.out
						.println("Please run this application again, and select the correct file!");
			}
		}
		else
		{
			// Jfile chooser was not approved
			System.out.println("Unfortunately, the file was not approved by the file chooser...");
			System.out.println("Please run this application again, and select the correct file!");
		}

	}

}
