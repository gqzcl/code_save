import java.util.Scanner;
import java.io.File;

public class ScannerFileTest{
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner(new File("ScannerFileTest.java"));
        System.out.println("ScannerFileTest.java:\n");
        while(sc.hasNextLine()){
            System.out.println(sc.nextLine());
        }
    }
}
