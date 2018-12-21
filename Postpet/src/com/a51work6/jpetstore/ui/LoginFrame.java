package com.a51work6.jpetstore.ui;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import java.awt.Font;
import javax.swing.SwingConstants;

import com.a51work6.jpetstore.dao.AccountDao;
import com.a51work6.jpetstore.dao.mysql.AccountDaoImp;
import com.a51work6.jpetstore.domain.Account;

import java.awt.FlowLayout;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;

import java.awt.GridLayout;
import javax.swing.BoxLayout;
import java.awt.CardLayout;
import net.miginfocom.swing.MigLayout;

public class LoginFrame extends MyFrame {
	
	private AccountDao dao;
	private JTextField txtAccountId;
	private JPasswordField txtPassword;
	
	public LoginFrame() {
		super("用户登录",400,230);
		//设置布局管理器null
		getContentPane().setLayout(null);
		
		JLabel lblNewLabel1=new JLabel("\u8D26\u53F7\uFF1A");
		lblNewLabel1.setFont(new Font("Microsoft YaHei UI",Font.PLAIN,15));
		lblNewLabel1.setHorizontalAlignment(SwingConstants.RIGHT);
		lblNewLabel1.setBounds(68,45,72,18);
		getContentPane().add(lblNewLabel1);
		
		JLabel lblNewLabel2=new JLabel("\u5BC6\u7801\uFF1A");
		lblNewLabel2.setFont(new Font("Microsoft YaHei UI",Font.PLAIN,15));
		lblNewLabel2.setHorizontalAlignment(SwingConstants.RIGHT);
		lblNewLabel2.setBounds(60,85,80,21);
		getContentPane().add(lblNewLabel2);
		
		txtAccountId=new JTextField();
		txtAccountId.setFont(new Font("Microsoft YaHei UI",Font.PLAIN,15));
		txtAccountId.setBounds(179,39,125,24);
		getContentPane().add(txtAccountId);
		txtAccountId.setColumns(10);
		
		txtPassword=new JPasswordField(10);
		txtPassword.setBounds(179,82,125,24);
		getContentPane().add(txtPassword);
		
		JButton btnOK=new JButton("\u786E\u5B9A");
		//登录处理
		btnOK.addActionListener(e->{
			//TODO DAO
			dao=new AccountDaoImp();
			Account account=dao.findById(txtAccountId.getText());
			String passText =new String(txtPassword.getPassword());
			if(account!=null&&passText.equals(account.getPassword())) {
				//成功成功
				System.out.println("登录成功.");
				//界面跳转到商品列表窗口
				ProductListFrame listFrame=new ProductListFrame();
				listFrame.setVisible(true);
				this.setVisible(false);
				
				MainApp.account=account;
			}else {//登录失败
				System.out.println("登录失败。");
				JLabel label =new JLabel("您输入的账号或密码有误，请重新输入。");
				JOptionPane.showMessageDialog(null, label, "登录失败", JOptionPane.ERROR_MESSAGE);
			}
		});
		btnOK.setFont(new Font("Microsoft YaHei UI",Font.PLAIN,15));
		btnOK.setBounds(71,132,97,38);
		getContentPane().add(btnOK);
		
		
		JButton btnCancel=new JButton("\u53D6\u6D88");
		btnCancel.addActionListener(e->{
			//退出系统
			System.exit(0);
		});
		btnCancel.setFont(new Font("Microsoft YaHei UI",Font.PLAIN,15));
		btnCancel.setBounds(71,132,97,38);
		getContentPane().add(btnCancel);
		
	
	}
}
