package com.a51work6.jpetstore.ui;

import com.a51work6.jpetstore.dao.OrderDao;
import com.a51work6.jpetstore.dao.OrderDetailDao;
import com.a51work6.jpetstore.dao.Productdao;
import com.a51work6.jpetstore.dao.mysql.OrderDaoImp;
import com.a51work6.jpetstore.dao.mysql.OrderDetailDaoImp;
import com.a51work6.jpetstore.dao.mysql.ProductDaoImp;
import com.a51work6.jpetstore.domain.Order;
import com.a51work6.jpetstore.domain.OrderDetail;
import com.a51work6.jpetstore.domain.Product;

import javax.swing.*;
import java.awt.*;
import java.util.Date;
import java.util.Map;

public class CartFrame extends MyFrame{
    //购物车数据
    private Map<String,Integer> cart;

    //商品DAO
    private Productdao dao=new ProductDaoImp();

    //订单DAO
    private OrderDao orderDao=new OrderDaoImp();
    //订单详细DAO
    private OrderDetailDao orderDetailDao=new OrderDetailDaoImp();

    //表格数据
    private Object[][] data;

    //表格
    JTable table;
    //ProductListFrame窗口
    ProductListFrame productListFrame;

    public CartFrame(Map<String, Integer> cart,ProductListFrame productListFrame) {
        super("商品购物车", 1000, 700);
        this.cart = cart;
        this.productListFrame=productListFrame;

        //顶部的面板
        JPanel topPanel=new JPanel();
        FlowLayout flowLayout=(FlowLayout) topPanel.getLayout();
        flowLayout.setVgap(20);
        flowLayout.setHgap(30);
        getContentPane().add(topPanel, BorderLayout.NORTH);

        JButton btnReturn=new JButton("\u8FD4\u56DE\u5546\u54C1\u5217\u8868");
        btnReturn.addActionListener(e->{

            //更新购物车
            for(int i=0;i<data.length;i++){
                //商品编号
                String productid=(String)data[i][0];
                //数量
                Integer quantity=(Integer)data[i][3];
                cart.put(productid,quantity);
            }
            this.productListFrame.setVisible(true);
            this.setVisible(false);
        });
        topPanel.add(btnReturn);

        JButton btnSubmit=new JButton("\u63D0\u4EA4\u8BA2\u5355");
        btnSubmit.addActionListener(e->{
            //生成订单
            generateOrders();
            double moneyToPay=getOrderTotalAmount();
            JLabel label=new JLabel("订单已经生成，应付款 "+moneyToPay+" 元，请付款。");
            if(JOptionPane.showConfirmDialog(this,label,"信息",JOptionPane.YES_NO_OPTION)==JOptionPane.NO_OPTION){
                //
                System.out.println("未付款");
//                CartFrame frame=new CartFrame(this.cart,this.productListFrame);
//                frame.setVisible(true);
//                this.setVisible(false);
            }else{
                System.out.println("付款成功");
                JLabel label1=new JLabel("付款成功，已支付 "+moneyToPay+" 元，感谢您的惠顾。");
                JOptionPane.showConfirmDialog(this,label1,"提示",JOptionPane.YES_OPTION);
                ProductListFrame listFrame=new ProductListFrame();
                listFrame.setVisible(true);
                this.setVisible(false);
            }
        });
        topPanel.add(btnSubmit);

        //中部表格
        JScrollPane scrollPane=new JScrollPane();
        getContentPane().add(scrollPane, BorderLayout.CENTER);
        scrollPane.setViewportView(getTable());
    }

    private JTable getTable(){

        //准备数据
        data =new Object[cart.size()][5];
        int idx=0;
        //遍历购物车
        for(String productid : cart.keySet()){
            Product p=dao.findById(productid);
            data[idx][0]=p.getProductid(); //商品编号
            data[idx][1]=p.getCname(); //商品名
            data[idx][2]=p.getUnitcost(); //商品单价
            data[idx][3]=cart.get(productid); //商品数量
            //计算应付金额
            double amount=(double)data[idx][2]*(int)data[idx][3];
            data[idx][4]=amount; //应付金额

            idx++;
        }
        CartTableModel model=new CartTableModel(data);
        if(table==null){

            table = new JTable(model); //TODO TableModel

            //设置表格字体
            table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 16));
            //设置表格标题字体
            table.getTableHeader().setFont(new Font("Microsoft YaHei UI", Font.BOLD, 17));
            //设置行高
            table.setRowHeight(51);

        }else{
            table.setModel(model);
        }
        return table;
    }



    //生成订单方法
    private void generateOrders(){

        Order order=new Order();
        order.setUserid(MainApp.account.getUserid());
        //设置付款状态 待付款0
        order.setStatus(0);
        //订单Id （用当前时间作为订单Id）
        Date now=new Date();
        order.setOrderid(now.getTime());
        order.setOrderdate(now);
        order.setAmount(getOrderTotalAmount());

        //创建订单数据
        orderDao.creat(order);

        //创建订单详细数据
        for(int i=0;i<data.length;i++){
            OrderDetail orderDetail=new OrderDetail();
            orderDetail.setOrderid(order.getOrderid());
            orderDetail.setProductid((String)data[i][0]);
            orderDetail.setQuantity((int)data[i][3]);
            orderDetail.setUnitcost((double)data[i][2]);
            //
            orderDetailDao.creat(orderDetail);
        }

    }
    //计算订单金额方法
    private double getOrderTotalAmount(){
        double totalAmount=0;

        for(int i=0;i<data.length;i++){
            totalAmount+=(Double)data[i][4];
        }
        return totalAmount;
    }
}
