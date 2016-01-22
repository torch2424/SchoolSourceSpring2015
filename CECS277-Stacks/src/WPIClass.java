public class WPIClass implements MiniWPI
{

	/**
	 * Aaron Turner
	 * 
	 * April 7th, 2015
	 * 
	 * Date Due: April 15th, 2015
	 * 
	 * Purpose: This is supposed to implement the MiniWPI class, and use it's
	 * functions to show that we have implemented and successfully used a stack
	 * to create a word processor.
	 * 
	 * Input: Commands from a Queue in our main program
	 * 
	 * Output: The results of the command if used by the printtest function
	 * 
	 * 
	 */

	// Our constructor
	public WPIClass(String s)
	{
		// Set our string into our right stack
		for (int i = s.length() - 1; i >= 0; --i)
		{
			// push the character onto the stack
			right.push(s.charAt(i));
		}
	}

	@Override
	public boolean isAtStart()
	{
		// If there is nothing in the left stack then
		// we are at the start
		if (left.isEmpty())
			return true;
		else
			return false;
	}

	@Override
	public boolean isAtEnd()
	{
		// If there is nothing in the right stack then
		// we are at the start
		if (right.isEmpty())
			return true;
		else
			return false;
	}

	@Override
	public void insertChar(char c)
	{
		// Simply add to the left stack
		left.push(c);
	}

	@Override
	public void moveLeft()
	{
		// Pop from the left stack and place into the right, if not at start
		if (!isAtStart()) right.push(left.pop());

	}

	@Override
	public void moveRight()
	{
		// Pop from the right stack and place into the left, if not at the end
		if (!isAtEnd()) left.push(right.pop());
	}

	@Override
	public void backspace()
	{
		// Simply remove from the left stack if not at the start
		if (!isAtStart()) left.pop();
	}

	@Override
	public void delete()
	{
		// Simply remove from the right stack if not at the end
		if (!isAtEnd()) right.pop();
	}

	@Override
	public void moveToStart()
	{
		// We simply need to pop everything from our left stack to our right
		// stack
		while (!left.isEmpty())
		{
			right.push(left.pop());
		}
	}

	@Override
	public void moveToEnd()
	{
		// We simply need to pop everything from our right stack to our left
		// stack
		while (!right.isEmpty())
		{
			left.push(right.pop());
		}

	}

	// Print our string
	@Override
	public String toString()
	{
		// String we will be printing
		String returnString = "";
		// print everything in our left stack with loop
		for (int i = 0; i < left.size(); ++i)
		{
			returnString = returnString + left.elementAt(i);
		}

		// print everything in our right stack with loop
		for (int i = right.size() - 1; i >= 0; --i)
		{
			returnString = returnString + right.elementAt(i);
		}

		// Return our string to print
		return returnString;
	}

	// Print our string with the cursor
	@Override
	public String toStringCursor()
	{
		// String we will be printing
		String returnString = "";
		// print everything in our left stack with loop
		for (int i = 0; i < left.size(); ++i)
		{
			returnString = returnString + left.elementAt(i);
		}

		// Print our cursor
		returnString = returnString + "|";

		// print everything in our right stack with loop
		for (int i = right.size() - 1; i >= 0; --i)
		{
			returnString = returnString + right.elementAt(i);
		}

		// Return our string to print
		return returnString;
	}

	@Override
	public boolean search(char c)
	{
		//First push everything into our right stack
		moveToStart();
		
		//Now search through our right stack
		while(!right.isEmpty())
		{
			//peek the right, if it is the answer, return true
			if(right.peek().equals(c)) 
			{
				moveRight();
				return true;
			}
			//just simple go to the next character
			else moveRight();
		}
		
		//If we have gotten here than we never found the item, 
		//simply move to the end and return false
		moveToEnd();
		return false;
	}

	@Override
	public void processCommand(String s)
	{
		// Get a string and do a function, then pass to print test to show results
		if (s.contentEquals("atStart"))
		{
			printtest(s);
			System.out.println(isAtStart());
		}
		else if (s.contentEquals("atEnd"))
		{
			printtest(s);
			System.out.println(isAtEnd());
		}
		else if (s.contentEquals("moveToStart"))
		{
			moveToStart();
			printtest(s);
		}
		else if (s.contentEquals("moveToEnd"))
		{
			moveToEnd();
			printtest(s);
		}
		else if (s.contentEquals("toString"))
		{
			printtest(s);
		}
		else if (s.startsWith("toStringCursor"))
		{
			printtest(s);
		}
		else if (s.contentEquals("moveLeft"))
		{
			moveLeft();
			printtest(s);
		}
		else if (s.contentEquals("moveRight"))
		{
			moveRight();
			printtest(s);
		}
		
		//ERROR CHECKING
		else if(left.isEmpty() && right.isEmpty())
		{
			//we have no inputted characters
			System.out.println();
			System.out.println("Now executing the command " + s + "...");
			System.out.println("The Results of this command are:");
			System.out.println("Sorry but you need to input something before using that command...");
		}
		else if (s.startsWith("insertChar"))
		{
			insertChar(s.charAt(s.length() - 1));
			printtest(s);
		}
		else if (s.contentEquals("backspace"))
		{
			backspace();
			printtest(s);
		}
		else if (s.contentEquals("delete"))
		{
			delete();
			printtest(s);
		}
		else if (s.startsWith("search"))
		{
			search(s.charAt(s.length() - 1));
			printtest(s);
		}
		
		//ERORR CHECKING
		else
		{
			//it is an unaccepted command, doing it this way since we cant pass two strings to printtest
			System.out.println();
			System.out.println("Now executing the command " + s + "...");
			System.out.println("The Results of this command are:");
			System.out.println("Sorry but this is not  valid command...");
		}

	}

	@Override
	public void printtest(String s)
	{
		//Simply print the command we are doing, and our process command will
		//print the results
		System.out.println();
		System.out.println("Now executing the command " + s + "...");
		System.out.println("The Results of this command are:");
		if(!s.contentEquals("toString")) System.out.println(toStringCursor());
		else  System.out.println(toString());
	}

}
