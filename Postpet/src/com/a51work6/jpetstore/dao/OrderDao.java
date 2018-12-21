package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.Order;

public interface OrderDao {

	//查询所有订单数据
	List<Order> findAll();
	//根据主键查询
	Order findById(String id);
	//创建订单信息
	int creat(Order order);
	//修改订单信息
	int modify(Order order);
	//删除订单信息
	int remove(Order order);
}
