package com.a51work6.jpetstore.dao.mysql;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.a51work6.jpetstore.dao.Productdao;
import com.a51work6.jpetstore.domain.Product;

public class ProductDaoImp implements Productdao {

	@Override
	public List<Product> findAll() {
		
		String sql="select productid,category,cname,ename,image,listprice,unitcost,descn from product";
		
		List<Product> list=new ArrayList<Product>();
		
		try(//2.创建数据库连接
				Connection conn=DBHelper.getConnection();
				//3.创建语句对象
				PreparedStatement pstmt=conn.prepareStatement(sql);
				//4.绑定参数
				//5.执行查询
				ResultSet rs=pstmt.executeQuery()){
			
			//6.遍历结果集
			while(rs.next()) {
				
				Product p=new Product();
				
				p.setProductid(rs.getString("productid"));
				p.setCategory(rs.getString("category"));
				p.setCname(rs.getString("cname"));
				p.setEname(rs.getString("ename"));
				p.setImage(rs.getString("image"));
				p.setListprice(rs.getDouble("listprice"));
				p.setUnitcost(rs.getDouble("unitcost"));
				p.setDescn(rs.getString("descn"));
				
				list.add(p);
			}
			
		}catch(SQLException e) {
			e.printStackTrace();
		}
			
		return list;
	}

	@Override
	public Product findById(String id) {

		Connection conn=null;
		PreparedStatement pstmt=null;
		ResultSet rs=null;
		
		String sql="select productid,category,cname,ename,image,listprice,unitcost,descn from product where category=?";
		
		try {
			//2.创建数据库连接
			conn=DBHelper.getConnection();
			//3.创建语句对象
			pstmt=conn.prepareStatement(sql);
			//4.绑定参数
			pstmt.setString(1,id);
			//5.执行查询
			rs=pstmt.executeQuery();
			//6.遍历结果类
			if(rs.next()) {
				
				Product p=new Product();
				
				p.setProductid(rs.getString("productid"));
				p.setCategory(rs.getString("category"));
				p.setCname(rs.getString("cname"));
				p.setEname(rs.getString("ename"));
				p.setImage(rs.getString("image"));
				p.setListprice(rs.getDouble("listprice"));
				p.setUnitcost(rs.getDouble("unitcost"));
				p.setDescn(rs.getString("descn"));
				
				return p;
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
			if(pstmt!=null) {
				try{
					pstmt.close();
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
		
		return null;
	}
	
	@Override
	public List<Product> findByCategory(String category){
		
		Connection conn=null;
		PreparedStatement pstmt=null;
		ResultSet rs=null;
		
		List<Product> list =new ArrayList<Product>();
		String sql="select productid,category,cname,ename,image,listprice,unitcost,descn from product where category=?";
		
		try {
			//2.创建数据库连接
			conn=DBHelper.getConnection();
			//3.创建语句对象
			pstmt=conn.prepareStatement(sql);
			//4.绑定参数
			pstmt.setString(1,category);
			//5.执行查询
			rs=pstmt.executeQuery();
			//6.遍历结果类
			while(rs.next()) {
				
				Product p=new Product();
				
				p.setProductid(rs.getString("productid"));
				p.setCategory(rs.getString("category"));
				p.setCname(rs.getString("cname"));
				p.setEname(rs.getString("ename"));
				p.setImage(rs.getString("image"));
				p.setListprice(rs.getDouble("listprice"));
				p.setUnitcost(rs.getDouble("unitcost"));
				p.setDescn(rs.getString("descn"));
				
				list.add(p);
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
			if(pstmt!=null) {
				try{
					pstmt.close();
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
		return list;
	}

	@Override
	public int creat(Product product) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int modify(Product product) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int remove(Product product) {
		// TODO Auto-generated method stub
		return 0;
	}

}
