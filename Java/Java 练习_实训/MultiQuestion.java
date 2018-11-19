import java.util.Arrays;
public class MultiQuestion extends Question{
    char[] answer;
    public MultiQuestion(){};
    public MultiQuestion(String text,String[] options,char[] answer){
        this.text=text;
        this.options=options;
        this.answer=answer;
    }
    public boolean check(char[] answers){
        if(Arrays.equals(answers,this.answer)){
            System.out.println("恭喜，答对了！");
            return true;
        }
        System.out.println("还得努力呀！");
        return false;
    }
}