package com.a51work6.jpetstore.ui;

import javax.swing.table.AbstractTableModel;

public class CartTableModel extends AbstractTableModel {

    //表格数据
    private Object[][] data;
    //表格列名数组
    private String[] columnNames={"商品编号","商品名","商品单价","数量","商品应付金额"};

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
        //只允许修改数量列
        if(columnIndex!=3){
            return;
        }
        try{
            int quantity=new Integer((String) aValue);//
            //check用户输入<0
            if(quantity<0){
                return;
            }
            //更新data数量列
            data[rowIndex][3]=quantity;
            //计算应付金额
            //商品单价
            double unitcost=(double)data[rowIndex][2];
            double totalPrice=unitcost*quantity;

            //更新data商品应付金额列
            data[rowIndex][4]=totalPrice;
        }catch(NumberFormatException e){

        }
    }


}
