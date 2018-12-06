import java.awt.Panel;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class RegisterDialog extends JDialog{
	private JLabel labelEmail=new JLabel("email");
	private JTextField userEmail=new JTextField(20);
	private JLabel labelName=new JLabel("�û���");
	private JTextField userName=new JTextField(20);
	private JLabel labelSex=new JLabel("�Ա�:  ");
	private JLabel labelMale=new JLabel("��");
	private JLabel labelFemale=new JLabel("Ů");
	private JRadioButton male=new JRadioButton();
	private JRadioButton female=new JRadioButton();
	private JLabel labelHobby=new JLabel("����:  ");
	private String[] strHobbies= {"�����˶�","����","����","����Ϸ"};
	private JCheckBox hobbies[]=new JCheckBox[4];
	private JLabel labelHobbies[]=new JLabel[4];
	private JButton buttonSave=new JButton("����");
	private JButton buttonModify =new JButton("�޸�");
	private JButton buttonExit=new JButton("�˳�");
	private int windowHeight=280;
	private int windowWidth=400;
	public RegisterDialog(JFrame parent,String msg,UserDao userDao) {
		super(parent,msg,true);
	}
	private void init() {
		JPanel pEmail=new JPanel();
		pEmail.add(labelEmail);pEmail.add(userEmail);
		JPanel pName=new JPanel();
		pName.add(labelName);pName.add(userName);
		JPanel pSex=new JPanel();
		ButtonGroup sexRadioGroup=new ButtonGroup();
		sexRadioGroup.add(male);sexRadioGroup.add(female);
		pSex.add(labelSex);pSex.add(labelMale);pSex.add(male);pSex.add(labelFemale);pSex.add(female);
		male.setSelected(true);
		
		JPanel pHobby=new JPanel();
		pHobby.add(labelHobby);
		for(int i=0;i<hobbies.length;i++) {
			hobbies[i]=new JCheckBox();
			labelHobbies[i]=new JLabel();
			labelHobbies[i].setText(strHobbies[i]);
			pHobby.add(hobbies[i]);
			pHobby.add(labelHobbies[i]);
		}
		JPanel pButton=new JPanel();
		pButton.add(buttonSave);pButton.add(buttonExit);
		JPanel panel=new JPanel();
		panel.add(pEmail);
		panel.add(pName);
		panel.add(pSex);
		panel.add(pHobby);
		panel.add(pButton);
		this.add(panel);
	}
	public void showMe(JFrame parent) {
		this.init();
		setPosition(parent);
		this.validate();
		setVisible(true);
	}
	private void setPosition(JFrame parent) {
		int parentX=parent.getX();
		int parentY=parent.getY();
		int parentWidth=parent.getWidth();
		int parentHeight=parent.getHeight();
		int dialogX=parentX+(parentWidth-windowWidth)/2;
		int dialogY=parentY+(parentHeight-windowHeight)/2;
		this.setBounds(dialogX,dialogY,windowWidth,windowHeight);
	}
	
	
	
	/*
	//p234
	private UserDao userDao;
	//...
	public RegisterDialog(JFrame parent,String msg,UserDao userDao) {
		super(parent,msg,true);
		this.userDao=userDao;
		//...
	}
	//...
	*/
	
	
	
	
}
