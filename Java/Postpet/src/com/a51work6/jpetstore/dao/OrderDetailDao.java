package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.OrderDetail;

public interface OrderDetailDao {

	//查询所有订单数据
	List<OrderDetail> findAll();
	//根据主键查询
	OrderDetail findByPk(int orderid, String productid);
	//创建订单详细信息
	int creat(OrderDetail orderDetail);
	//修改订单详细信息
	int modify(OrderDetail orderDetail);
	//删除订单详细信息
	int remove(OrderDetail orderDetail);
}
