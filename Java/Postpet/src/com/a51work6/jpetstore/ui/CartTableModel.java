package com.a51work6.jpetstore.ui;

import javax.swing.table.AbstractTableModel;

public class CartTableModel extends AbstractTableModel {

    //�������
    private Object[][] data;
    //�����������
    private String[] columnNames={"��Ʒ���","��Ʒ��","��Ʒ����","����","��ƷӦ�����"};

    public CartTableModel(Object[][] data){
        this.data=data;
    }
    @Override
    public int getColumnCount(){
        return columnNames.length;
    }
    @Override
    public int getRowCount(){
        return data.length;
    }
    @Override
    public Object getValueAt(int rowIdx,int colIdx){
        return data[rowIdx][colIdx];
    }
    @Override
    public String getColumnName(int column){
        return columnNames[column];
    }
    @Override
    public boolean isCellEditable(int rowIndex,int columnIndex){
        //
        if(columnIndex==3){
            return true;
        }
        return false;
    }
    @Override
    public void setValueAt(Object aValue,int rowIndex,int columnIndex){
        //ֻ�����޸�������
        if(columnIndex!=3){
            return;
        }
        try{
            int quantity=new Integer((String) aValue);//
            //check�û�����<0
            if(quantity<0){
                return;
            }
            //����data������
            data[rowIndex][3]=quantity;
            //����Ӧ�����
            //��Ʒ����
            double unitcost=(double)data[rowIndex][2];
            double totalPrice=unitcost*quantity;

            //����data��ƷӦ�������
            data[rowIndex][4]=totalPrice;
        }catch(NumberFormatException e){

        }
    }


}
