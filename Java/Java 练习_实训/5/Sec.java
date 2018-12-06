import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.lang.ref.Cleaner;

import javax.swing.*;






public class Sec extends JFrame{//？？？
	
	
	
	
	JMenuItem jmiModify;
	JMenuItem jmiRemove;
	JMenuItem jmiRegiste;
	private void createMenuBar(){
		JMenuItem jmiRegiste=new JMenuItem("注册用户");
		
		JMenuBar menuBar=new JMenuBar();
		JMenu registeMenu=new JMenu("注册（N）");
		registeMenu.setMnemonic(KeyEvent.VK_N);
		registeMenu.add(jmiRegiste=new JMenuItem("注册用户"));
		jmiRegiste.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N,ActionEvent.CTRL_MASK));
		menuBar.add(registeMenu);
		JMenu editmenu=new JMenu("编辑用户信息（E）");
		editmenu.setMnemonic(KeyEvent.VK_E);
		menuBar.add(editmenu);
		editmenu.add(jmiModify=new JMenuItem("修改用户信息（M）",'M'));
		editmenu.add(jmiRemove=new JMenuItem("删除用户信息（R）",'R'));
		//...
		
		this.setJMenuBar(menuBar);
	}
	
	JButton btnEdit;
	JButton btnRegiste;
	JButton btnSearch;
	JButton btnRemove;
	
	private void createToolBar(){
		JToolBar toolBar=new JToolBar();
		btnRegiste=new JButton("",new ImageIcon(this.getClass().getResource("../ico/add.gif")));
		btnRegiste.setToolTipText("注册用户");
		btnEdit=new JButton("",new ImageIcon(this.getClass().getResource("../ico/modify.gif")));
		
		
		btnEdit.setToolTipText("修改用户信息");
		btnRemove=new JButton("",new ImageIcon(this.getClass().getResource("../ico/remove.gif")));
		btnRemove.setToolTipText("删除用户信息");
		btnSearch=new JButton("",new ImageIcon(this.getClass().getResource("../ico/search.gif")));
		btn.setToolTipText("浏览用户信息");
		toolBar.add(btnRegiste);
		toolBar.add(btnEdit);
		toolBar.add(btnRemove);
		toolBar.add(btnSearch);
		this.add("North",toolBar);
		
		
		
		jmiRegiste.addActionListener(new RegisteHandler());
		btnRegiste.addActionListener(new RegisteHandler());
	}
	
	

	private class RegisteHandler implements ActionListener{
		public void actionPerformed(ActionEvent events) {
			new RegisterDialog(Menu.this,"注册用户",userDao).showMe(Menu.this);
		}
	}
	
	
	private String getHobbiesInfo() {
		StringBuilder strHobbies=new StringBuilder();
		for(int i=0;i<strHobbies.length();i++) {
			if(hobbies[i].isSelected()) {
				String hobbyText=labelHobbies[i].getText();
				strHobbies.append("  "+hobbyText+"  ");
			}
		}
		return strHobbies.toString();
	}
	
	
	private class SaveHandler implements ActionListener{
		public void actionPerformed(ActiveEvent e) {
			String email=userEmail.getText();
			String name=userName.getText();
			String sex=male.isSelected()?"男":"女";
			String hobby=getHobbiesInfo();
			if(email.length()==0) {
				JOptionPane.showMessageDialog(null,"请输入email", "提示", JOptionPane.PLAIN_MESSAGE);
				userEmail.grabFocus();
			}else if(!email.matches("[a-zA-Z0-9_+\\.-]+@([a-zA-Z0-9-]+\\.)+[a-zA-Z0-9]{2,4}")) {
				JOptionPane.showMessageDialog(null, "email格式有误", "提示", JOptionPane.PLAIN_MESSAGE);
				userEmail.setText("");
				userEmail.grabFocus();
			}else if(name.length()==0) {
				JOptionPane.showMessageDialog(null, "请输入用户名", "提示", JOptionPane.PLAIN_MESSAGE);
				userName.grabFocus();
			}else {
				if(userDao.selectByEmail(email)!=null) {
					JOptionPane.showMessageDialog(null, "该邮箱已存在", "提示", JOptionPane.PLAIN_MESSAGE);
					userEmail.setText("");
					userEmail.grabFocus();
				}else {
					User user=new User(email,name,sex,hobby);
					UserDao.insert(user);
					clear();
				}
			}
		}
		private void clear() {
			userEmail.setText("");
			userName.setText("");
			male.setSelect(true);
			for(int i=0;i<hobbies.length;i++)
			{
				hobbies[i].setSelected(false);
			}
		}
	}
	
	
	public void init() {
		ButtonGroup sexRadioGroup=new ButtonGroup();
		JRadioButton male=new JRadioButton();
		JRadioButton female=new JRadioButton();
		sexRadioGroup.add(male);
		sexRadioGroup.add(female);
		male.setSelected(true);
		btnSearch.addActionListener(new SearchAllHandler());
	}
	public static void main(String[] args) {
		
		
		
	}
	
	private class SearchAllHandler implements ActionListener{
		public void actionPerFormed(ActionEvent e) {
			List<User>users=userDao.selectAll();
			if(users.size()!=0) {
				new ShowDataTableDialog(Menu.this,"查询结果", users).showMe(Menu.this);
			}else {
				JOptionPane.showMessageDialog(null, "没有用户的信息", "提示", JOptionPane.PLAIN_MESSAGE);
			}
		}
	}
}
