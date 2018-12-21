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

	//商品列表集合
	private List<Product> products=null;
	//商品DAO
	private Productdao dao=new ProductDaoImp();
	
	//选择商品行号
	int selectRow=-1;
	//购物车
	private java.util.Map<String, Integer> cart=new HashMap<String,Integer>();
	
	JTable table;
	JLabel lblImage;
	JLabel lblDescn;
	JLabel lblListprice;
	JLabel lblUnitcost;
	
	
	public ProductListFrame() {
		super("商品列表",1000,700);
		//布局采用BorderLayou
		getContentPane().setLayout(new BorderLayout());
		
		//查询所有商品
		products=dao.findAll();
		
		//初始界面
		//添加顶部搜索面板
		getContentPane().add(getSearchPanel(), BorderLayout.NORTH);
		//初始化风格面板
		JSplitPane splitPane=new JSplitPane();
		//设置分隔线的位置
		splitPane.setDividerLocation(400);
		//设置左侧面板
		splitPane.setLeftComponent(getLeftPanel());
		//设置右侧面板
		splitPane.setRightComponent(getRightPanel());
		//添加分隔面板
		getContentPane().add(splitPane, BorderLayout.CENTER);
		
	}
	
	//顶部搜索面板
	private  JPanel getSearchPanel() {
		JPanel panel=new JPanel();
		FlowLayout flowLayout=(FlowLayout) panel.getLayout();
		flowLayout.setHgap(30);
		
		JLabel lblNewLabel=new JLabel("\u9009\u62E9\u5546\u54C1\u7C7B\u522B\uFF1A");
		lblNewLabel.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		panel.add(lblNewLabel);
		
		String[] categories= {"鱼类","狗类","爬行类","猫类","鸟类"};
		JComboBox comboBox=new JComboBox(categories);
		comboBox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		panel.add(comboBox);
		
		JButton btnGo=new JButton("\u67E5\u8BE2");
		//查询处理
		btnGo.addActionListener(e->{
			//选择类别
			String category=(String)comboBox.getSelectedItem();
			products=dao.findByCategory(category);
			ProductTableModel model=new ProductTableModel(this.products);
			table.setModel(model);	
		});
		btnGo.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		panel.add(btnGo);
		
		JButton btnReset=new JButton("\u91CD\u7F6E");
		//重置处理
		btnReset.addActionListener(e->{
			products=dao.findAll();
			ProductTableModel model=new ProductTableModel(this.products);
			table.setModel(model);	
		});
		
		btnReset.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		panel.add(btnReset);
		
		return panel;
	}
	
	//左侧面板
	private JScrollPane getLeftPanel() {
		
		JScrollPane leftPane=new JScrollPane();
		leftPane.setViewportView(getTable());
		
		return leftPane;
	}
	
	//初始化表格
	private JTable getTable() {
		
		ProductTableModel model=new ProductTableModel(this.products);
		
		if(table==null) {
			table=new JTable(model);
			//设置表格字体
			table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
			//设置表格标题字体
			table.getTableHeader().setFont(new Font("Microsoft YaHei UI", Font.BOLD, 16));
			//设置行高
			table.setRowHeight(51);
			//设置表格行选择模式
			table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		
			//选择行的事件处理
			ListSelectionModel rowListSelectionModel=table.getSelectionModel();
			rowListSelectionModel.addListSelectionListener(e->{
				
				//只考虑鼠标按下
				if(e.getValueIsAdjusting()==false) {
					return;
				}
				
				ListSelectionModel lsm=(ListSelectionModel)e.getSource();
				selectRow=lsm.getMinSelectionIndex();
				if(selectRow<0) {
					return;
				}
				
				System.out.println(selectRow);
				
				//更新右侧面板
				Product p=products.get(selectRow);
				String petImage=String.format("/images/%s", p.getImage());
				ImageIcon icon=new ImageIcon(ProductListFrame.class.getResource(petImage));
				lblImage.setIcon(icon);
				
				String descn=p.getDescn();
				lblDescn.setText("商品描述："+descn);
				
				double listprice=p.getListprice();
				String sListprice=String.format("商品市场价：%.2f", listprice);
				lblListprice.setText(sListprice);
				
				double unitcost=p.getUnitcost();
				String sunitcost=String.format("商品单价：%.2f", unitcost);
				lblUnitcost.setText(sunitcost);
				
			});
			
		
		}else {
			table.setModel(model);
		}
		
		return table;
	}
	
	//右侧面板
	private JPanel getRightPanel() {
		JPanel rightPanel=new JPanel();
		rightPanel.setLayout(new GridLayout(2,1,0,0));
		rightPanel.setBackground(Color.WHITE);
		
		//图标
		lblImage=new JLabel();
		lblImage.setHorizontalAlignment(SwingConstants.CENTER);
		rightPanel.add(lblImage);
		
		//详细面板
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
		//添加商品到购物车
		btnAdd.addActionListener(e->{
			
			if(selectRow<0) {
				return;
			}
			
			//添加商品至购物车
			Product p=products.get(selectRow);
			String productid=p.getProductid();
			
			if(cart.containsKey(productid)) {
				//获得商品数量
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
		//查看购物车
		btnCheck.addActionListener(e->{
			//TODO
			
		});
		btnCheck.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		detailPanel.add(btnCheck);
		
		
		return rightPanel;
	}
	
	
}
