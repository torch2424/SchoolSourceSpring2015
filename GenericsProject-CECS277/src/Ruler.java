/**
 * Aaron Turner
 * 
 * March 2nd, 2015
 * 
 * Date Due: March 11th, 2015
 * 
 * Purpose: This is supposed to show generics in our generic parent class. By
 * creating a subclass of our generic class as an Integer.
 * 
 * Input: N/A
 * 
 * Output: The largest elements of Arraylists passed into the static function
 * largestVal
 * 
 * OutPut Extra Credit: The sorted contents of the arrays
 */

public class Ruler extends Measurable<Integer>
{
	// Our constructors
	Ruler()
	{
		this(1);
	}

	Ruler(int howLong)
	{
		super(howLong);
	}
}
