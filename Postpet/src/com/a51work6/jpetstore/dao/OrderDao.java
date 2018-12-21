package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.Order;

public interface OrderDao {

	//��ѯ���ж�������
	List<Order> findAll();
	//����������ѯ
	Order findById(String id);
	//����������Ϣ
	int creat(Order order);
	//�޸Ķ�����Ϣ
	int modify(Order order);
	//ɾ��������Ϣ
	int remove(Order order);
}
