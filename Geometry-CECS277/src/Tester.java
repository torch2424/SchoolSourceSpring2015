/**
 * 
 */

/**
	 * Aaron Turner
	 * 
	 * Febuary 4th, 2015
	 * 
	 * Purpose: This is supposed to test the Rectangle, Circle, and Triangle
	 * objects that extend the geometric object class, This will demonstrate
	 * Polymorphism and the comparable interface
	 * 
	 * Input: N/A
	 * 
	 * Output: The info of our objects
	 */
public class Tester 
{

	public static void main(String[] args)
	{
		//Create our classes
		Circle circ = new Circle(3);
		Rectangle rect = new Rectangle(2,3);
		Triangle tri = new Triangle(2,2,3);
		
		//Say that you are testing the values
		System.out.println("Welcome to the testing program, objects will be presented" +
				"in the order of circle, rectangle, and trianlge!");
		
		//Testing toString
		System.out.println("\nTesting toString()...");
		//Now test the values
		System.out.println("Circle: " + circ.toString());
		System.out.println("Rectangle: " + rect.toString());
		System.out.println("Triangle: " + tri.toString());
		
		//Testing the get methods
		System.out.println("\nTesting get methods of private variables...");
		//Now test the values
		System.out.println("Our circle's radius is: " + circ.getRadius());
		System.out.println("Our rectangles's height is: " + rect.getHeight());
		System.out.println("Our rectangles's width is: " + rect.getWidth());
		System.out.println("Our triangles's side 1 is: " + tri.getSide1());
		System.out.println("Our triangles's side 2 is: " + tri.getSide2());
		System.out.println("Our triangles's side 3 is: " + tri.getSide3());
		
		//Test circles get diameter
		System.out.println("\nTesting getDiameter...");
		System.out.println("Our circle's diamtere is: " + circ.getDiameter());
		
		//Test get perimeter
		System.out.println("\nTesting getPerimeter()...");
		//Now test the values
		System.out.println("Circle: " + circ.getPerimeter());
		System.out.println("Rectangle: " + rect.getPerimeter());
		System.out.println("Triangle: " + tri.getPerimeter());
		
		//Test get area
		System.out.println("\nTesting getArea()...");
		//Now test the values
		System.out.println("Circle: " + circ.getArea());
		System.out.println("Rectangle: " + rect.getArea());
		System.out.println("Triangle: " + tri.getArea());
		
		//Test Geometric Object's max
		System.out.println("\nTesting GeometricObject's static method, max()...");
		System.out.println("Comparing Circle (A) to default circle (B):");
		int test = GeometricObject.max(circ, new Circle());
		if(test == 1)
		{
			System.out.println("A is larger!");
		}
		else if(test == 0)
		{
			System.out.println("They are the same.");
		}
		else
		{
			System.out.println("B is larger!");
		}
		System.out.println("Comparing default rectangle (A) to Rectangle (B):");
		test = GeometricObject.max(new Rectangle(), rect);
		if(test == 1)
		{
			System.out.println("A is larger!");
		}
		else if(test == 0)
		{
			System.out.println("They are the same.");
		}
		else
		{
			System.out.println("B is larger!");
		}
		System.out.println("Comparing default triangle (A) to " +
				"another default triangle (B):");
		test = GeometricObject.max(new Triangle(), new Triangle());
		if(test == 1)
		{
			System.out.println("A is larger!");
		}
		else if(test == 0)
		{
			System.out.println("They are the same.");
		}
		else
		{
			System.out.println("B is larger!");
		}
		
		//End of the testing program
	}
}
