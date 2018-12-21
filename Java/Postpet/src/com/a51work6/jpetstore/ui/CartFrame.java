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
    //���ﳵ����
    private Map<String,Integer> cart;

    //��ƷDAO
    private Productdao dao=new ProductDaoImp();

    //����DAO
    private OrderDao orderDao=new OrderDaoImp();
    //������ϸDAO
    private OrderDetailDao orderDetailDao=new OrderDetailDaoImp();

    //�������
    private Object[][] data;

    //���
    JTable table;
    //ProductListFrame����
    ProductListFrame productListFrame;

    public CartFrame(Map<String, Integer> cart,ProductListFrame productListFrame) {
        super("��Ʒ���ﳵ", 1000, 700);
        this.cart = cart;
        this.productListFrame=productListFrame;

        //���������
        JPanel topPanel=new JPanel();
        FlowLayout flowLayout=(FlowLayout) topPanel.getLayout();
        flowLayout.setVgap(20);
        flowLayout.setHgap(30);
        getContentPane().add(topPanel, BorderLayout.NORTH);

        JButton btnReturn=new JButton("\u8FD4\u56DE\u5546\u54C1\u5217\u8868");
        btnReturn.addActionListener(e->{

            //���¹��ﳵ
            for(int i=0;i<data.length;i++){
                //��Ʒ���
                String productid=(String)data[i][0];
                //����
                Integer quantity=(Integer)data[i][3];
                cart.put(productid,quantity);
            }
            this.productListFrame.setVisible(true);
            this.setVisible(false);
        });
        topPanel.add(btnReturn);

        JButton btnSubmit=new JButton("\u63D0\u4EA4\u8BA2\u5355");
        btnSubmit.addActionListener(e->{
            //���ɶ���
            generateOrders();
            double moneyToPay=getOrderTotalAmount();
            JLabel label=new JLabel("�����Ѿ����ɣ�Ӧ���� "+moneyToPay+" Ԫ���븶�");
            if(JOptionPane.showConfirmDialog(this,label,"��Ϣ",JOptionPane.YES_NO_OPTION)==JOptionPane.NO_OPTION){
                //
                System.out.println("δ����");
//                CartFrame frame=new CartFrame(this.cart,this.productListFrame);
//                frame.setVisible(true);
//                this.setVisible(false);
            }else{
                System.out.println("����ɹ�");
                JLabel label1=new JLabel("����ɹ�����֧�� "+moneyToPay+" Ԫ����л���Ļݹˡ�");
                JOptionPane.showConfirmDialog(this,label1,"��ʾ",JOptionPane.YES_OPTION);
                ProductListFrame listFrame=new ProductListFrame();
                listFrame.setVisible(true);
                this.setVisible(false);
            }
        });
        topPanel.add(btnSubmit);

        //�в����
        JScrollPane scrollPane=new JScrollPane();
        getContentPane().add(scrollPane, BorderLayout.CENTER);
        scrollPane.setViewportView(getTable());
    }

    private JTable getTable(){

        //׼������
        data =new Object[cart.size()][5];
        int idx=0;
        //�������ﳵ
        for(String productid : cart.keySet()){
            Product p=dao.findById(productid);
            data[idx][0]=p.getProductid(); //��Ʒ���
            data[idx][1]=p.getCname(); //��Ʒ��
            data[idx][2]=p.getUnitcost(); //��Ʒ����
            data[idx][3]=cart.get(productid); //��Ʒ����
            //����Ӧ�����
            double amount=(double)data[idx][2]*(int)data[idx][3];
            data[idx][4]=amount; //Ӧ�����

            idx++;
        }
        CartTableModel model=new CartTableModel(data);
        if(table==null){

            table = new JTable(model); //TODO TableModel

            //���ñ������
            table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 16));
            //���ñ���������
            table.getTableHeader().setFont(new Font("Microsoft YaHei UI", Font.BOLD, 17));
            //�����и�
            table.setRowHeight(51);

        }else{
            table.setModel(model);
        }
        return table;
    }



    //���ɶ�������
    private void generateOrders(){

        Order order=new Order();
        order.setUserid(MainApp.account.getUserid());
        //���ø���״̬ ������0
        order.setStatus(0);
        //����Id ���õ�ǰʱ����Ϊ����Id��
        Date now=new Date();
        order.setOrderid(now.getTime());
        order.setOrderdate(now);
        order.setAmount(getOrderTotalAmount());

        //������������
        orderDao.creat(order);

        //����������ϸ����
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
    //���㶩������
    private double getOrderTotalAmount(){
        double totalAmount=0;

        for(int i=0;i<data.length;i++){
            totalAmount+=(Double)data[i][4];
        }
        return totalAmount;
    }
}
