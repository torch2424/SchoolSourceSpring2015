import javax.swing.JFrame;


/**
 * Aaron Turner
 * 
 * April 30th, 2015
 * 
 * Date Due: May 13th, 2015
 * 
 * Purpose: This is the class that creates our frame, and places our Jpanel game 
 * within it, which is continuously run
 * 
 * Input: N/A
 * 
 * Output: Jframe with out game
 * 
 * 
 */
public class MainClass
{
	public static void main(String[] args) throws InterruptedException
	{
		//Create our frame
		JFrame frame = new JFrame("GUI Project");
		//Create our game Jpanel
		Ball game = new Ball(600);
		//Add our game to our frame
		frame.add(game);
		//Set our frame size, and other properties
		frame.setSize(game.getFrameSize(), game.getFrameSize());
		frame.setResizable(false);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//Continuously run the game
		while (true)
		{
			game.moveBall();
			game.repaint();
			Thread.sleep(game.getSpeed());
		}
	}
}