import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.Button;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.GraphicsEnvironment;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

//import javafx.scene.control.Button;

public class AWTCalculation{
    private Frame frame;
    private TextField field;
    private Button[] allButtons;


    public AWTCalculation(){
        frame=new Frame("AWTCalculation");
        field=new TextField(20);
        allButtons=new Button[20];
        String str="←C√±789/456*123-0.=+";
        for(int i=0;i<str.length();i++){
            allButtons[i]=new Button(str.substring(i,i+1));
        }
    }


    private void init(){
        Panel northPanel=new Panel();
        northPanel.add(field);
        Panel centerPanel=new Panel();
        //centerPanel.add(field);
        GridLayout grid=new GridLayout(5,4,2,2);
        centerPanel.setLayout(grid);
        for(int i=0;i<allButtons.length;i++){
            centerPanel.add(allButtons[i]);
        }
        frame.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e) {
                    System.exit(0);
            }
        });
        frame.add(northPanel,BorderLayout.NORTH);
        frame.add(centerPanel,BorderLayout.CENTER);
    }


    public void showMe(){
        init();
        frame.pack();
        frame.setLocation(300,200);
        frame.setResizable(false);
        frame.setVisible(true);
        addEventHandler();
    }
    


    public void addEventHandler(){
        for(int i=0;i<allButtons.length;i++){
            allButtons[i].addActionListener(new CalculateActionHandler());
        }
    }


    double op1=0,op2=0;
    String operator="";
    boolean flag=true;
    private class CalculateActionHandler implements ActionListener{
    public void actionPerformed(ActionEvent e){
        String command=e.getActionCommand();
        if (command.equals("C")) {
            field.setText("");
        }
        if (command.equals("←")) {
                field.setText(field.getText().substring(0, field.getText().length() - 1));
        }
        if (command.equals("√")) {
                field.setText(String.valueOf(Math.sqrt(Double.valueOf(field.getText()))));
        }
        if (command.equals("±")) {
                field.setText(String.valueOf(Double.valueOf(field.getText()) * (-1)));
        }
        if("0123456789.".indexOf(command)!=1){
            if(flag){
                field.setText(command);
            }else{
                field.setText(field.getText()+command);
            }
            flag=false;
        }else if("+-*/".indexOf(command)!=-1){
            op1=Double.valueOf(field.getText());
            operator=command;
            field.setText("");
        }else if(command.equalsIgnoreCase("=")){
            double res=0;
            String text=field.getText();
            if(text.length()>0){
                op2=Double.valueOf(text);
                if(operator.equals("+")){
                    res=op1+op2;
                }else if(operator.equals("-")){
                    res=op1-op2;
                }else if(operator.equals("*")){
                    res=op1*op2;
                }else{
                    res=op1/op2;
                }
                field.setText(String.valueOf(res));
            }
            flag=true;
        }
    }
}



    public static void main(String[] args){
        new AWTCalculation().showMe();
    }
}