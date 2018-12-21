package com.a51work6.jpetstore.dao.mysql;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DBHelper {

	//1.加载数据库驱动
	//数据库url
	static String url;
	//创建Properties对象
	static Properties info=new Properties();
	//静态代码块7
	static {
		//获取属性文件的输入流
		InputStream in =DBHelper.class.getClassLoader().getResourceAsStream("com/a51work6/jpetstore/dao/mysql/config.properties");

	 	try {
	 		//加载属性文件信息
	 		info.load(in);
	 		//从属性文件中读取url
	 		url=info.getProperty("url");
	 		//从属性文件中读取driver
	 		String driverClassName=info.getProperty("driver");
	 		//加载驱动程序
	 		Class.forName(driverClassName);
	 	}catch(ClassNotFoundException e) {
	 		System.out.println("驱动程序加载失败1:");
	 	}catch(IOException e) {
	 		System.out.println("驱动程序加载失败2:");
	 	}
	}

	//2.创建数据库连接
	public static Connection getConnection() throws SQLException {
		//创建数据库连接
		Connection conn= DriverManager.getConnection(url, info);
		return conn;
	}
}
