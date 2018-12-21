package com.a51work6.jpetstore.ui;

import com.a51work6.jpetstore.domain.Account;

public class MainApp {

	//用户登录成功后，需要保存的用户信息
	public static Account account;
	//Session(会话)
	
	public static void main(String[] args) {
		//TODO 调用LoginFrame
		LoginFrame frame=new LoginFrame();
		frame.setVisible(true);
	}

}
