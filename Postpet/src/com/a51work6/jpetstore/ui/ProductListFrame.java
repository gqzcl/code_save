package com.a51work6.jpetstore.ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Panel;
import java.util.HashMap;
import java.util.List;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JSplitPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;
import javax.swing.SwingConstants;

import com.a51work6.jpetstore.dao.Productdao;
import com.a51work6.jpetstore.dao.mysql.ProductDaoImp;
import com.a51work6.jpetstore.domain.Product;
import com.sun.javafx.collections.MappingChange.Map;

public class ProductListFrame extends MyFrame {

	//��Ʒ�б���
	private List<Product> products=null;
	//��ƷDAO
	private Productdao dao=new ProductDaoImp();
	
	//ѡ����Ʒ�к�
	int selectRow=-1;
	//���ﳵ
	private java.util.Map<String, Integer> cart=new HashMap<String,Integer>();
	
	JTable table;
	JLabel lblImage;
	JLabel lblDescn;
	JLabel lblListprice;
	JLabel lblUnitcost;
	
	
	public ProductListFrame() {
		super("��Ʒ�б�",1000,700);
		//���ֲ���BorderLayou
		getContentPane().setLayout(new BorderLayout());
		
		//��ѯ������Ʒ
		products=dao.findAll();
		
		//��ʼ����
		//��Ӷ����������
		getContentPane().add(getSearchPanel(), BorderLayout.NORTH);
		//��ʼ��������
		JSplitPane splitPane=new JSplitPane();
		//���÷ָ��ߵ�λ��
		splitPane.setDividerLocation(400);
		//����������
		splitPane.setLeftComponent(getLeftPanel());
		//�����Ҳ����
		splitPane.setRightComponent(getRightPanel());
		//��ӷָ����
		getContentPane().add(splitPane, BorderLayout.CENTER);
		
	}
	
	//�����������
	private  JPanel getSearchPanel() {
		JPanel panel=new JPanel();
		FlowLayout flowLayout=(FlowLayout) panel.getLayout();
		flowLayout.setHgap(30);
		
		JLabel lblNewLabel=new JLabel("\u9009\u62E9\u5546\u54C1\u7C7B\u522B\uFF1A");
		lblNewLabel.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		panel.add(lblNewLabel);
		
		String[] categories= {"����","����","������","è��","����"};
		JComboBox comboBox=new JComboBox(categories);
		comboBox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		panel.add(comboBox);
		
		JButton btnGo=new JButton("\u67E5\u8BE2");
		//��ѯ����
		btnGo.addActionListener(e->{
			//ѡ�����
			String category=(String)comboBox.getSelectedItem();
			products=dao.findByCategory(category);
			ProductTableModel model=new ProductTableModel(this.products);
			table.setModel(model);	
		});
		btnGo.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		panel.add(btnGo);
		
		JButton btnReset=new JButton("\u91CD\u7F6E");
		//���ô���
		btnReset.addActionListener(e->{
			products=dao.findAll();
			ProductTableModel model=new ProductTableModel(this.products);
			table.setModel(model);	
		});
		
		btnReset.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		panel.add(btnReset);
		
		return panel;
	}
	
	//������
	private JScrollPane getLeftPanel() {
		
		JScrollPane leftPane=new JScrollPane();
		leftPane.setViewportView(getTable());
		
		return leftPane;
	}
	
	//��ʼ�����
	private JTable getTable() {
		
		ProductTableModel model=new ProductTableModel(this.products);
		
		if(table==null) {
			table=new JTable(model);
			//���ñ������
			table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
			//���ñ���������
			table.getTableHeader().setFont(new Font("Microsoft YaHei UI", Font.BOLD, 16));
			//�����и�
			table.setRowHeight(51);
			//���ñ����ѡ��ģʽ
			table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		
			//ѡ���е��¼�����
			ListSelectionModel rowListSelectionModel=table.getSelectionModel();
			rowListSelectionModel.addListSelectionListener(e->{
				
				//ֻ������갴��
				if(e.getValueIsAdjusting()==false) {
					return;
				}
				
				ListSelectionModel lsm=(ListSelectionModel)e.getSource();
				selectRow=lsm.getMinSelectionIndex();
				if(selectRow<0) {
					return;
				}
				
				System.out.println(selectRow);
				
				//�����Ҳ����
				Product p=products.get(selectRow);
				String petImage=String.format("/images/%s", p.getImage());
				ImageIcon icon=new ImageIcon(ProductListFrame.class.getResource(petImage));
				lblImage.setIcon(icon);
				
				String descn=p.getDescn();
				lblDescn.setText("��Ʒ������"+descn);
				
				double listprice=p.getListprice();
				String sListprice=String.format("��Ʒ�г��ۣ�%.2f", listprice);
				lblListprice.setText(sListprice);
				
				double unitcost=p.getUnitcost();
				String sunitcost=String.format("��Ʒ���ۣ�%.2f", unitcost);
				lblUnitcost.setText(sunitcost);
				
			});
			
		
		}else {
			table.setModel(model);
		}
		
		return table;
	}
	
	//�Ҳ����
	private JPanel getRightPanel() {
		JPanel rightPanel=new JPanel();
		rightPanel.setLayout(new GridLayout(2,1,0,0));
		rightPanel.setBackground(Color.WHITE);
		
		//ͼ��
		lblImage=new JLabel();
		lblImage.setHorizontalAlignment(SwingConstants.CENTER);
		rightPanel.add(lblImage);
		
		//��ϸ���
		JPanel detailPanel=new JPanel();
		rightPanel.add(detailPanel);
		detailPanel.setLayout(new GridLayout(7,1,0,5));
		detailPanel.setBackground(Color.WHITE);
		
		JSeparator separator1=new JSeparator();
		detailPanel.add(separator1);
		
		lblDescn=new JLabel();
		lblDescn.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		detailPanel.add(lblDescn);
		
		lblListprice=new JLabel("");
		lblListprice.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		detailPanel.add(lblListprice);
		
		lblUnitcost=new JLabel("");
		lblUnitcost.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		detailPanel.add(lblUnitcost);
		
		JSeparator separator2=new JSeparator();
		detailPanel.add(separator2);
		
		JButton btnAdd=new JButton("\u6DFB\u52A0\u5230\u8D2D\u7269\u8F66");
		//�����Ʒ�����ﳵ
		btnAdd.addActionListener(e->{
			
			if(selectRow<0) {
				return;
			}
			
			//�����Ʒ�����ﳵ
			Product p=products.get(selectRow);
			String productid=p.getProductid();
			
			if(cart.containsKey(productid)) {
				//�����Ʒ����
				Integer count=cart.get(productid);
				cart.put(productid, ++count);
			}else {
				cart.put(productid, 1);
			}
			
			System.out.println(cart);
			
		});
		btnAdd.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		detailPanel.add(btnAdd);
		
		JButton btnCheck=new JButton("\u67E5\u770B\u8D2D\u7269\u7269\u8F66");
		//�鿴���ﳵ
		btnCheck.addActionListener(e->{
			//TODO
			
		});
		btnCheck.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		detailPanel.add(btnCheck);
		
		
		return rightPanel;
	}
	
	
}
