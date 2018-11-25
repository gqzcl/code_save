import java.util.Map;
import java.util.HashMap;
public class AnswerSheet{
    private Map<Integer,String> answers;
    public AnswerSheet(){
        answers=new HashMap<Integer,String>();
    }
    public void addAnswer(int key,String answer){
        answers.put(key,answer);
    }
    public Map<Integer,String> getAnswers(){
        return answers;
    }
}