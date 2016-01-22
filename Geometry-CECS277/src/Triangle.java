/**
 * 
 */

/**
 * @author Aaron Turner
 *
 */
public class Triangle extends GeometricObject
{
	//Sides
	int side1;
	int side2;
	int side3;
	
	//Our constructors
	public Triangle()
	{
		this(1, 1, 1);
	}
	
	public Triangle(int s1, int s2, int s3)
	{
		super();
		side1 = s1;
		side2 = s2;
		side3 = s3;
	}
	
	//Accessor method
	public int getSide1()
	{
		return side1;
	}
	
	public int getSide2()
	{
		return side2;
	}
	
	public int getSide3()
	{
		return side3;
	}
	
	public void setSide1(int s)
	{
		side1 = s;
	}
	
	public void setSide2(int s)
	{
		side2 = s;
	}
	
	public void setSide3(int s)
	{
		side3 = s;
	}
	
	//Returns perimeter of triangle
	public int getPerimeter()
	{
		return (side1 + side2 + side3);
	}
	
	//Prints the triangle, and all of its info
	@Override
	public String toString()
	{
		return "The sides of the Triangle are: " + side1 + " " + side2 + " " + side3 
				+ "\n The perimeter is " + getPerimeter()
				+ "\n the area is " + getArea();
	}
	
	//returns the area of the triangle
	public double getArea()
	{
		//set the variables to the formula
		int a = side1;
		int b = side2;
		int c = side3;
		//s is half of the perimeter
		double s = getPerimeter() / 2.0f;
		return Math.sqrt(s * (s-a) * (s-b) * (s-c));
	}
}
