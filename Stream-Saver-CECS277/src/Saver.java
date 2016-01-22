import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Saver
{

	/**
	 * Aaron Turner
	 * 
	 * April 20th, 2015
	 * 
	 * Date Due: April 27th, 2015
	 * 
	 * Purpose: This is supposed to save vanilla, chocolate, and strawberry ice
	 * cream cone objects to a file
	 * 
	 * Input: N/A
	 * 
	 * Output: The file the objects are saved to
	 * 
	 * 
	 */
	
	public static void main(String[] args)
	{
		// Welcome user to the program
		System.out.println("Welcome to the Ice Cream Object Saver!");
		System.out.println("We will now create three Ice Cream Cones!");

		// Create the cones
		// Default flavor is vanilla
		AdvancedIceCreamCone vanilla = new AdvancedIceCreamCone();
		AdvancedIceCreamCone chocolate = new AdvancedIceCreamCone(2, "chocolate", "cake");
		AdvancedIceCreamCone strawberry = new AdvancedIceCreamCone(3, "strawberry", "waffle");

		// Now save them
		System.out.println("We will now save the three Ice Cream Cones!");

		// First create the File, using the directory the user launched the app
		File cones = new File(System.getProperty("user.dir") + "/ice.cream");

		// Now serialize our objects to the file
		// Output the object into the DecisionsSave file
		FileOutputStream fileOut = null;
		ObjectOutputStream out = null;
		try
		{
			fileOut = new FileOutputStream(cones);
			out = new ObjectOutputStream(fileOut);
			out.writeObject(vanilla);
			out.writeObject(chocolate);
			out.writeObject(strawberry);
		}
		catch (IOException e)
		{
			// Print our error
			System.out.println("Unfortunately, there was an IO error "
					+ "when saving the file, please try again...");
			e.printStackTrace();
		}
		finally
		{
			try
			{
				out.close();
				fileOut.close();
			}
			catch (IOException e)
			{
				// Print our error
				System.out.println("Unfortunately, there was an IO error "
						+ "when saving the file, please try again...");
				e.printStackTrace();
			}
		}

		// Inform the user end of program!
		System.out.println("Ice Cream Cones saved at: " + cones.getAbsolutePath());
		System.out.println("Use the Ice Cream Cone fetcher program to view your Ice Cream Cones!");

	}

}
