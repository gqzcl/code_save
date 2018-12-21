package com.a51work6.jpetstore.ui;

import java.awt.Toolkit;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;

public class MyFrame extends JFrame {
	//获得屏幕宽度
	private double screenWidth=Toolkit.getDefaultToolkit().getScreenSize().getWidth();
	
	//获得屏幕高度
	private double screenHeight=Toolkit.getDefaultToolkit().getScreenSize().getWidth();
	
	public MyFrame(String title,int width,int height) {
		super(title);
		//设置窗口大小
		setSize(width,height);
		//计算窗口居中的坐标
		int x=(int)(screenWidth-width)/2;
		int y=(int)(screenHeight-height)/2;
		//设置窗口的位置
		setLocation(x,y);
		
		//注册窗口事件
		addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				//退出系统
				System.exit(0);
			}		
		});	
	}	
}
