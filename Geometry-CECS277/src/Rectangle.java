/**
 * 
 */

/**
 * @author Aaron Turner
 *
 */
public class Rectangle  extends GeometricObject
{
	//width and height of rectangle
	private int width;
	private int height;
	
	//Constructor
	public Rectangle()
	{
		this(1,1);
	}
	
	public Rectangle(int rWidth, int rHeight)
	{
		//Call superclass constructor and set object width and height
		super();
		width = rWidth;
		height = rHeight;
	}
	
	public double getArea()
	{
		//Return the height
		return width* height;
	}
	
	public int getPerimeter()
	{
		//Return the perimeter
		return width * 2 + height * 2;
	}
	
	//Get and set methods
	public int getWidth()
	{
		return width;
	}
	
	public int getHeight()
	{
		return height;
	}
	
	public void setWidth(int w)
	{
		width = w;
	}
	
	public void setHeight(int h)
	{
		height = h;
	}
}
