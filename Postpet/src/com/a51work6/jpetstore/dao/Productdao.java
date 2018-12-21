package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.Product;

public interface Productdao {

	//��ѯ������Ʒ����
	List<Product> findAll();
	//����������ѯ
	Product findById(String id);
	//���������в�ѯ
	List<Product> findByCategory(String category);
	
	//������Ʒ��Ϣ
	int creat(Product product);
	//�޸���Ʒ��Ϣ
	int modify(Product product);
	//ɾ����Ʒ��Ϣ
	int remove(Product product);
	
}
