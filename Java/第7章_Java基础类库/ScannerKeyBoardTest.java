import java.util.Scanner;

public class ScannerKeyBoardTest{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        sc.useDelimiter("\n");//设置分隔符
        while(sc.hasNext()){
            System.out.println("input:"+sc.next());
        }
        sc.close();
    }
}