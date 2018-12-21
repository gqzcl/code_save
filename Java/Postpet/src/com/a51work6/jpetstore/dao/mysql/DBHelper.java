package com.a51work6.jpetstore.dao.mysql;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DBHelper {

	//1.�������ݿ�����
	//���ݿ�url
	static String url;
	//����Properties����
	static Properties info=new Properties();
	//��̬�����7
	static {
		//��ȡ�����ļ���������
		InputStream in =DBHelper.class.getClassLoader().getResourceAsStream("com/a51work6/jpetstore/dao/mysql/config.properties");

	 	try {
	 		//���������ļ���Ϣ
	 		info.load(in);
	 		//�������ļ��ж�ȡurl
	 		url=info.getProperty("url");
	 		//�������ļ��ж�ȡdriver
	 		String driverClassName=info.getProperty("driver");
	 		//������������
	 		Class.forName(driverClassName);
	 	}catch(ClassNotFoundException e) {
	 		System.out.println("�����������ʧ��1:");
	 	}catch(IOException e) {
	 		System.out.println("�����������ʧ��2:");
	 	}
	}

	//2.�������ݿ�����
	public static Connection getConnection() throws SQLException {
		//�������ݿ�����
		Connection conn= DriverManager.getConnection(url, info);
		return conn;
	}
}
