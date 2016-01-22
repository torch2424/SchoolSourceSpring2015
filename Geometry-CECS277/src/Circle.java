/**
 * 
 */

/**
 * @author Aaron Turner
 *
 */

public class Circle extends GeometricObject
{
	//Our radius
	int radius;
	
	public Circle()
	{
		this(1);
	}
	
	public Circle(int cRadius)
	{
		super();
		radius = cRadius;
	}
	
	//Get and set radius
	public int getRadius()
	{
		return radius;
	}
	
	public void setRadius(int r)
	{
		radius = r;
	}
	
	//return the area of the circle
	public double getArea()
	{
		//Pi R^2
		return (Math.PI * radius * radius);
	}
	
	//return the circumference of the circle
	public int getPerimeter()
	{
		return (int) (Math.PI * radius * 2);
	}
	
	//Return the diameter of the circle
	public int getDiameter()
	{
		return radius * 2;
	}
}
