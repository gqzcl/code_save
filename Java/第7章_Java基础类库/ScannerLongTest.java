import java.util.Scanner;

public class ScannerLongTest{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        while(sc.hasNextLong()){
            System.out.println("input:"+sc.nextLong());
        }
    }
}