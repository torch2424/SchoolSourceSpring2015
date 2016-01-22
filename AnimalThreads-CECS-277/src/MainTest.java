import java.util.ArrayList;
import java.util.Scanner;

/**
 * Aaron Turner
 * 
 * April 28th, 2015
 * 
 * Date Due: May 6th, 2015
 * 
 * Purpose: This is supposed to promt the user to create their animal racers,
 * and then race them, and display results to the user
 * 
 * Input: Strings and Integers according to the prompts to create and race
 * animals
 * 
 * Output: The results of the animals Racing
 * 
 * 
 */
public class MainTest
{

	public static void main(String[] args)
	{
		// Welcome user to the program
		System.out.println("Welcome to the ANIMAL RACER program!");

		// create our scanner to get our input
		Scanner input = new Scanner(System.in);

		// Create an arraylist of animal racers
		ArrayList<AnimalRacer> animals = new ArrayList<AnimalRacer>();

		// --- HAVE USER CREATE THE ANIMALS ---

		// prompt the user for the number of animals to get
		System.out.println("How many animals would you like to race? Please input an Integer");

		// get the input and make sure it is a number
		int racers = 0;
		String user;
		while (racers <= 0)
		{
			user = input.nextLine();
			racers = numCheck(user);
		}

		// Now loop until we have created the number of animals
		for (int i = 0; i < racers; ++i)
		{
			animals.add(new AnimalRacer());
		}

		// Prompt the user to set up every animal
		for (int i = 0; i < racers; ++i)
		{
			// prompt
			System.out.println("Please name Animal #" + (i + 1));

			// get input and assign to racer
			user = input.nextLine();
			animals.get(i).setAnimalName(user);

			// prompt
			System.out.println("Give a speed integer (in milliseconds e.g. 100) less than 1000 to Animal #" + (i + 1));

			// get the input and make sure it is a number
			int speed = 0;
			while (speed <= 0)
			{
				user = input.nextLine();
				speed = numCheck(user);
				
				//Since we are subtracting, we need to prompt user for this
				 if(speed >= 1000)
				 {
					 System.out.println("Please input a number less than 1000..."); 
					 speed = 0;
				 }
			}
			
			//Make speed speed - 100 for a better UX
			speed = 1000 - speed;

			// Add to animal
			animals.get(i).setSpeed(speed);

			// prompt
			System.out.println("Give a rest integer (in milliseconds e.g. 100) to Animal #" + (i + 1));

			// get the input and make sure it is a number
			int rest = 0;
			while (rest <= 0)
			{
				user = input.nextLine();
				rest = numCheck(user);
			}

			// Add to animal
			animals.get(i).setRest(rest);
		}

		// Tell user done racing animals
		System.out.println();
		System.out.println("Finished animal racer creation...");
		System.out.println();

		// Finally race the animals, use a boolean for continous races

		// Start all the animals
		for (int i = 0; i < animals.size(); ++i)
		{
			animals.get(i).start();
		}

		//NOT REQUIRED FOR THE ASSIGNMENT
		// boolean racing = true;
		// while (racing)
		// {
		// // Tell the user you are now racing
		// // System.out.println("NOW RACING ANIMALS!!!");
		//
		// // Start all the animals
		// for (int i = 0; i < animals.size(); ++i)
		// {
		// animals.get(i).start();
		// }
		//
		// // Stall output until animals finish
		// int finished = 0;
		// while (finished < animals.size())
		// {
		// finished = AnimalRacer.finishedAnimals;
		// }
		//
		// System.out.println();
		// System.out.println("Race has finished!");
		//
		// // Menu to race again
		// boolean menu = true;
		// while (menu)
		// {
		//
		// System.out.println("Would you like to race again? (Y/N)");
		//
		// user = input.nextLine();
		//
		// if (user.equalsIgnoreCase("Y"))
		// {
		// //They want to race again
		// menu = false;
		// }
		// else if (user.equalsIgnoreCase("N"))
		// {
		// //They do not want to race again
		// racing = false;
		// menu = false;
		// }
		// else
		// {
		// // it was improper input
		// System.out.println("That is not valid input, please enter Y or N");
		// }
		// }
		// }

		// leave user from the program done in animal racer

	}

	// Function to determine if input is a number
	public static int numCheck(String number)
	{
		// try and parse the int, if it is not an int catch and return
		// false
		int returner = 0;
		try
		{
			returner = Integer.parseInt(number);

			if (returner < 0)
				System.out.println("That is not positive, Please input a positive Integer");
		}
		catch (NumberFormatException nfe)
		{
			System.out.println("That is not an integer, Please input an Integer");
			returner = 0;
		}
		finally
		{
			return returner;
		}
	}
}
