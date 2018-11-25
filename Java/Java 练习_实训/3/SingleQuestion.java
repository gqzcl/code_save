import java.util.Arrays;
public class SingleQuestion extends Question{
    char[] answer;
    public SingleQuestion(){};
    public SingleQuestion(String text,String[] options,char[] answer){
        this.text=text;
        this.options=options;
        this.answer=answer;
    };
    public boolean check(char[] answer){
        if(Arrays.equals(answer,this.answer)){
            System.out.println("恭喜，答对了！");
            return true;
        }
        System.out.println("还得努力呀！");
        return false;
    }
}