package com.a51work6.jpetstore.dao;

import com.a51work6.jpetstore.domain.Account;

import java.util.List;

public interface AccountDao {

	//查询所有用户信息
	List<Account> findAll();
	//根据主键查询
	Account findById(String userid);
	//创建用户信息
	int create(Account account);
	//修改用户信息
	int modity(Account account);
	//删除用户信息
	int remove(Account account);
	
}
