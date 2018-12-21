package com.a51work6.jpetstore.dao.mysql;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.a51work6.jpetstore.domain.OrderDetail;
import com.a51work6.jpetstore.domain.Product;

public class OrderDetailDaoImp implements com.a51work6.jpetstore.dao.OrderDetailDao {

	@Override
	public List<OrderDetail> findAll() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public OrderDetail findByPk(int orderid, String productid) {
		Connection conn=null;
		PreparedStatement pstmt=null;
		ResultSet rs=null;
		
		String sql="select orderid,productid,quantity,unitcost from ordersdetail where orderid=? and productid=?";
		
		try {
			//2.创建数据库连接
			conn=DBHelper.getConnection();
			//3.创建语句对象
			pstmt=conn.prepareStatement(sql);
			//4.绑定参数
			pstmt.setInt(1,orderid);
			pstmt.setString(2, productid);
			
			//5.执行查询
			rs=pstmt.executeQuery();
			//6.遍历结果类
			if(rs.next()) {
				
				OrderDetail detail=new OrderDetail();
				
				detail.setOrderid(rs.getInt("orderid"));
				detail.setProductid(rs.getString("productid"));
				detail.setQuantity(rs.getInt("quantity"));
				detail.setUnitcost(rs.getDouble("unitcost"));
				
				
				return detail;
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
	public int creat(OrderDetail orderDetail) {

		String sql="insert into orderdetail(orderid,productid,quantity,unitcost) values (?,?,?,?)";
		
		try(//2.创建数据库连接
				Connection conn=DBHelper.getConnection();
				//3.创建语句对象
				PreparedStatement pstmt=conn.prepareStatement(sql);
				){
			
				//4.绑定参数
				pstmt.setLong(1, orderDetail.getOrderid());
				pstmt.setString(2, orderDetail.getProductid());
				pstmt.setInt(3, orderDetail.getQuantity());
				pstmt.setDouble(4, orderDetail.getUnitcost());	
				
				//5.执行
				int a=pstmt.executeUpdate();
				System.out.printf("成功插入%d数据。 \n",a);
			
		}catch(SQLException e) {
			e.printStackTrace();
		}
		
		return 0;
		
	}

	@Override
	public int modify(OrderDetail orderDetail) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int remove(OrderDetail orderDetail) {
		// TODO Auto-generated method stub
		return 0;
	}

}
