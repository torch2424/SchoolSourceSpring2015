

/**
 * Aaron Turner
 * 
 * April 28th, 2015
 * 
 * Date Due: May 6th, 2015
 * 
 * Purpose: This is the class that extends thread and will act as an "animal" that races
 * other animal racers, and display their progress
 * 
 * Input: Parameters to correctly create animal Racers
 * 
 * Output: Their position along the race
 * 
 * 
 */
public class AnimalRacer extends Thread
{
	// name of the animal
	private String animalName;
	// amount of rest an animal will have (milliseconds)
	private int rest;
	// the speed of an animal (milliseconds)
	private int speed;
	
	//Animals that have been created
	private static int createdAnimals = 0;
	//Animals that have finished the racd
	private static int finishedAnimals = 0;
	
	public static String winner;

	// our default constructor, create a default animal
	public AnimalRacer()
	{
		animalName = "Animal Racer";
		rest = 100;
		speed = 100;
		createdAnimals++;
	}

	// our constructor
	public AnimalRacer(String name, int restInput, int speedInput)
	{
		animalName = "Animal Racer";
		rest = restInput;
		speed = speedInput;
	}
	
	//Set methods
	public void setAnimalName(String name)
	{
		animalName = name;
	}
	
	public void setSpeed(int newSpeed)
	{
		speed = newSpeed;
	}
	
	public void setRest(int newRest)
	{
		rest = newRest;
	}
	
	//Our to string to display our thread info
	public String toString()
	{
		//Return our animal
		return animalName + System.lineSeparator() + "Speed: " + 
		speed + System.lineSeparator() + "Rest: " + rest;
	}
	
	//Our runnable
	public void run()
	{
		//save the time we started
		Long time = System.currentTimeMillis();
		//Say that the animal has started
		System.out.println(animalName + " has Started!");
		
		//Loop to do 5 laps
		for(int i = 1; i < 6; ++i)
		{
			try
			{
				//race for the lap
				this.sleep(speed);
				//Say we completed the lap
				System.out.println(animalName + " has completed lap # " + i + "!");
				//Rest so we may start the next lap
				this.sleep(rest);
			}
			//If we get an intteruption
			catch (InterruptedException e)
			{
				e.printStackTrace();
				//inform the user that the animal crash
				System.out.println("Unfortunately, " + animalName + "Has crashed, and will not race correctly...");
			}
		}
		
		//increase finished animals
		++finishedAnimals;
		//Prompt finished race
		System.out.println("Place: " + finishedAnimals + ", " + animalName + " has completed the race!");
		
		//If race is finshed tell user program is over
		if(createdAnimals == finishedAnimals)
		{
			System.out.println();
			System.out.println("Race has finished!");
			System.out.println("Thank you for using the Animal Racer program!");
		}
		
		
	}
}
