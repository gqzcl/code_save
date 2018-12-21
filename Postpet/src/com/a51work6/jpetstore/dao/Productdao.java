package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.Product;

public interface Productdao {

	//查询所有商品数据
	List<Product> findAll();
	//根据主键查询
	Product findById(String id);
	//按照类别进行查询
	List<Product> findByCategory(String category);
	
	//创建商品信息
	int creat(Product product);
	//修改商品信息
	int modify(Product product);
	//删除商品信息
	int remove(Product product);
	
}
