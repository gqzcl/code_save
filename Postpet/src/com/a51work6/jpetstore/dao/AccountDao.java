package com.a51work6.jpetstore.dao;

import java.util.List;

import com.a51work6.jpetstore.domain.Account;

public interface AccountDao {

	//��ѯ�����û���Ϣ
	List<Account> findAll();
	//����������ѯ
	Account findById(String userid);
	//�����û���Ϣ
	int create(Account account);
	//�޸��û���Ϣ
	int modity(Account account);
	//ɾ���û���Ϣ
	int remove(Account account);
	
}
