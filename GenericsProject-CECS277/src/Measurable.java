import java.util.ArrayList;

/**
 * Aaron Turner
 * 
 * March 2nd, 2015
 * 
 * Date Due: March 11th, 2015
 * 
 * Purpose: This is supposed to show generics in a generic class, that contains
 * a static method that will return the largest element of an arrayList. This is
 * our parent class for our subclasses. This also implements Comparable for
 * Extra Credit
 * 
 * Input: N/A
 * 
 * Output: The largest elements of Arraylists passed into the static function
 * largestVal
 * 
 * OutPut Extra Credit: The sorted contents of the arrays
 */
public abstract class Measurable<T extends Comparable<T>> implements Comparable<Measurable<T>>
{
	// Our private variable
	private T t;

	Measurable()
	{
		this(null);
	}

	Measurable(T input)
	{
		t = input;
	}

	// Helper function to compare two measureable objects
	private static <T extends Comparable<T>> boolean isLarger(T originalObj, T otherObj)
	{
		// IF the other object is greate than the other return true, else return
		// false
		if (originalObj.compareTo(otherObj) < 0)
			return true;
		else
			return false;
	}

	// Get and set methods
	public T getT()
	{
		return t;
	}

	public void setT(T input)
	{
		t = input;
	}

	// static method that returns the largest element of an ArrayList
	public static <T extends Measurable> T largestVal(ArrayList<T> array)
	{
		// Get the first object, and then we compare to all the others
		T largest = array.get(0);
		// Loop through and find the lagest value
		for (int i = 1; i < array.size() - 1; ++i)
		{
			if (isLarger(array.get(i).getT(), array.get(i + 1).getT()))
			{
				// Swap the two values
				largest = array.get(i + 1);
			}
		}

		return largest;
	}

	// Return a string of the object
	public String toString()
	{
		return t.toString();
	}

	// CompareTo method since we implement Comparable
	@Override
	public int compareTo(Measurable<T> o)
	{
		// use our helper function to determine if the object is larger so we
		// can sort
		if (isLarger(t, o.getT()))
			return -1;
		else if (t.compareTo(o.getT()) == 0)
			return 0;
		else
			return 1;

	}

}
