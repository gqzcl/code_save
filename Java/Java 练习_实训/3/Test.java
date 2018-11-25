import java.util.Scanner;
public class Test{
    public static void main(String[] args){
        MultiQuestion a1=new MultiQuestion("三国演义中的三绝是谁？",
        new String[]{"A.曹操","B.刘备","C.关羽","D.诸葛亮"},
        new char[]{'A','C','D'});
        a1.print();
        char[] ansewrs;
        System.out.println("请选择： ");
        Scanner sc=new Scanner(System.in);
        String answer=sc.nextLine();
        ansewrs=answer.toCharArray();
        a1.check(ansewrs);
        SingleQuestion a2=new SingleQuestion("最早向刘备推荐诸葛亮的是谁？",
        new String[]{"A.徐庶","B.司马徽","C.鲁肃","D.关羽"},
        new char[]{'B'});
        a2.print();
        System.out.println("请选择： ");
        answer=sc.nextLine();
        ansewrs=answer.toCharArray();
        a2.check(ansewrs);
    }
}