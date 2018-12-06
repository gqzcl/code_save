import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JDialog;
import javax.swing.JFrame;

public class Menu {
	private UserDao userDao;
	public Menu() {
		userDao=new UserDaoImplForList();
		//...
	}
	//...
	private class RegisteHandler implements ActionListener {
		public void actionPerformed(ActionEvent events) {
			new RegisterDialog(Menu.this, "×¢²áÓÃ»§", userDao);
		}
	}
}
//p234