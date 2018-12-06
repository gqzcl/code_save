import java.util.List;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import javafx.scene.control.Dialog;

public class ShowDataTableDialog extends JDialog{
	private int windowHeight=300;
	private int windowWidth=450;
	private JTable table;
	public ShowDataTableDialog(JFrame parent,String msg,List<User>users) {
		super(parent,"�û��б�",true);
		table=new JTable();
		UserTableModel model=new UserTableModel(users);
		table.setModel(model);
	}
	public void showMe(JFrame parent) {
		table.getColumn("���").setPreferredWidth(30);
		table.getColumn("email").setPreferredWidth(100);
		table.getColumn("�û���").setPreferredWidth(60);
		table.getColumn("�Ա�").setPreferredWidth(60);
		table.getColumn("����").setPreferredWidth(200);
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		JScrollPane pane=new JScrollPane(table);
		this.add(pane);
		setPosition(parent);
		setVisible(true);
		validate();
		setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
	}

}
