package com.a51work6.jpetstore.dao.mysql;

import com.a51work6.jpetstore.domain.OrderDetail;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

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
		
		String sql="select orderid,productid,quantity,unitcost from ordersdetial where orderid=? and productid=?";
		
		try {
			//2.�������ݿ�����
			conn=DBHelper.getConnection();
			//3.����������
			pstmt=conn.prepareStatement(sql);
			//4.�󶨲���
			pstmt.setInt(1,orderid);
			pstmt.setString(2, productid);
			
			//5.ִ�в�ѯ
			rs=pstmt.executeQuery();
			//6.���������
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

		String sql="insert into ordersdetial(orderid,productid,quantity,unitcost) values (?,?,?,?)";
		
		try(//2.�������ݿ�����
				Connection conn=DBHelper.getConnection();
				//3.����������
				PreparedStatement pstmt=conn.prepareStatement(sql);
				){
			
				//4.�󶨲���
				pstmt.setLong(1, orderDetail.getOrderid());
				pstmt.setString(2, orderDetail.getProductid());
				pstmt.setInt(3, orderDetail.getQuantity());
				pstmt.setDouble(4, orderDetail.getUnitcost());	
				
				//5.ִ��
				int a=pstmt.executeUpdate();
				System.out.printf("�ɹ�����%d���ݡ� \n",a);
			
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
