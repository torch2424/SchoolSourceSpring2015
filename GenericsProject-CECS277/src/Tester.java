import java.util.ArrayList;
import java.util.Collections;

/**
 * Aaron Turner
 * 
 * March 2nd, 2015
 * 
 * Date Due: March 11th, 2015
 * 
 * Purpose: This is supposed to show generics in a generic class, that contains
 * a static method that will return the largest element of an arrayList. This
 * tester will put our subclass objects into an array list, greet the user, show
 * the contents of the array lists, and then identify the largest value of each
 * array list, and the sorted contents of the array lists
 * 
 * Input: N/A
 * 
 * Output: The largest elements of Arraylists passed into the static function
 * largestVal
 * 
 * OutPut Extra Credit: The sorted contents of the arrays
 */
public class Tester
{
	public static void main(String[] args)
	{
		// Create our Arraylists
		ArrayList<Ruler> rulerArray = new ArrayList<Ruler>();
		ArrayList<SecondsTime> secondsArray = new ArrayList<SecondsTime>();
		ArrayList<AString> aStringArray = new ArrayList<AString>();
		// Fill our arrays
		rulerArray.add(new Ruler());
		rulerArray.add(new Ruler(12));
		rulerArray.add(new Ruler(56));
		rulerArray.add(new Ruler(2));
		secondsArray.add(new SecondsTime());
		secondsArray.add(new SecondsTime(4.1));
		secondsArray.add(new SecondsTime(65.5));
		secondsArray.add(new SecondsTime(20.3));
		aStringArray.add(new AString("f"));
		aStringArray.add(new AString("g"));
		aStringArray.add(new AString("x"));
		aStringArray.add(new AString("k"));

		// Create an array for our 3 array lists, for easier printing
		ArrayList<?>[] arrays = { rulerArray, secondsArray, aStringArray };

		// Greet the user to the program
		System.out.println("Welcome to the Generics Project Testing Program! Here are the Tests!");
		System.out.println();

		// print the contents of every arraylist
		for (int i = 0; i < arrays.length; ++i)
		{
			// Say which array we are printing
			System.out.print("Showing contents of: ");
			//Using if statements for easier printing
			if (i == 0)
				System.out.println("Ruler Array");
			else if (i == 1)
				System.out.println("Seconds Time Array");
			else
				System.out.println("AString Array");
			// Inner loop to print contents of arrays
			for (int ii = 0; ii < arrays[i].size(); ++ii)
			{
				// print the value
				System.out.println(arrays[i].get(ii));
			}
		}

		//Now show larget val of our arrays
		System.out.println();
		System.out.println("Now printing largestVal of our arrays!");
		// Put through our function, and print to user
		System.out.println("Ruler array largestVal: " + Measurable.largestVal(rulerArray));
		System.out.println("SecondsTime array largestVal: " + Measurable.largestVal(secondsArray));
		System.out.println("AString array largestVal: " + Measurable.largestVal(aStringArray));
		
		System.out.println();
		
		//Now show our arrays sorted
		System.out.println("Lastly, printing our arrays sorted! (By implementation of Comparable)");
		
		//Sort our arrays
		Collections.sort(rulerArray);
		Collections.sort(secondsArray);
		Collections.sort(aStringArray);
		
		//Now print our arrays sorted
		for (int i = 0; i < arrays.length; ++i)
		{
			// Say which array we are printing
			System.out.print("Showing sorted contents of: ");
			//Using if statements for easier printing
			if (i == 0)
				System.out.println("Ruler Array");
			else if (i == 1)
				System.out.println("Seconds Time Array");
			else
				System.out.println("AString Array");
			// Inner loop to print contents of arrays
			for (int ii = 0; ii < arrays[i].size(); ++ii)
			{
				// print the value
				System.out.println(arrays[i].get(ii));
			}
		}
		
		//Finish up, and tell the user thank you!
		System.out.println();
		System.out.println("Thank you for using the Generics Project Testing Program!");
	}

}
