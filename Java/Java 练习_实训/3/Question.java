import java.util.Arrays;
public class Question{
    String text;
    String[] options;
    public Question(){};
    public Question(String text,String[] options){
        text=this.text;
        options=this.options;
    };
    public boolean check(char[] answers){
        return false;
    };
    public void print(){
        System.out.println(text+'\n');
        System.out.println(Arrays.toString(options)+'\n');
    };
}