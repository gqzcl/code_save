package com.a51work6.jpetstore.dao.mysql;

import com.a51work6.jpetstore.dao.AccountDao;
import com.a51work6.jpetstore.domain.Account;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

public class AccountDaoImp implements AccountDao {

	@Override
	public List<Account> findAll() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Account findById(String userid) {
		
		Connection conn=null;
		PreparedStatement pstmt=null;
		ResultSet rs=null;
		Account account=null;
		
		PreparedStatement pstm = null;
		try {
			//2.创建数据库连接
			conn=DBHelper.getConnection();
			String sql="select userid,password,email,name,addr,city,country,phone from account where userid=?";
			//3.创建语句对象
			pstmt=conn.prepareStatement(sql);
			//4.绑定参数
			pstmt.setString(1,userid);
			//5.执行查询
			rs=pstmt.executeQuery();
			//System.out.println("success");
			//System.out.println(rs.next());
			//6.遍历结果类
			if(rs.next()) {
				
				account=new Account();
				
				account.setUserid(rs.getString("userid"));
				account.setUsername(rs.getString("name"));
				account.setEmail(rs.getString("email"));
				account.setAddr(rs.getString("addr"));
				account.setCity(rs.getString("city"));
				account.setCountry(rs.getString("country"));
				account.setPhone(rs.getString("phone"));
				account.setPassword(rs.getString("password"));				
				
			}
		}catch(SQLException e) {
			e.printStackTrace();
		}finally {
			if(rs!=null) {
				try{
					rs.close();
				}catch(SQLException e) {
					e.printStackTrace();
				}
			}
			if(pstm!=null) {
				try{
					pstm.close();
				}catch(SQLException e) {
					e.printStackTrace();
				}
			}
			if(conn!=null) {
				try{
					conn.close();
				}catch(SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return account;
	}

	@Override
	public int create(Account account) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int modity(Account account) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int remove(Account account) {
		// TODO Auto-generated method stub
		return 0;
	}

}
