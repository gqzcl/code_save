package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.OrderDetail;

public interface OrderDetailDao {

	//��ѯ���ж�������
	List<OrderDetail> findAll();
	//����������ѯ
	OrderDetail findByPk(int orderid, String productid);
	//����������ϸ��Ϣ
	int creat(OrderDetail orderDetail);
	//�޸Ķ�����ϸ��Ϣ
	int modify(OrderDetail orderDetail);
	//ɾ��������ϸ��Ϣ
	int remove(OrderDetail orderDetail);
}
