import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;
import java.util.List;
import java.util.Set;
import java.util.Iterator;
import java.util.ArrayList;
public class Paper{
    private Map<Integer,Question> questions;
    private int count;
    public Paper(int count){
        this.count=count;
        questions=new HashMap<Integer,Question>();
        for(int i=0;i<count;i++){
            this.addQuestion(i);
        }
    }
    public void addQuestion(int index){
        Scanner scn=new Scanner(System.in);
        System.out.print("输入题目描述：");
        String title=scn.nextLine();
        List<String> list=new ArrayList<String>();
        while(true){
            System.out.print("输入选项（quit表示结束）：");
            String option=scn.nextLine();
            if(option.equalsIgnoreCase("quit")){
                break;
            }
            list.add(option);
        }
        System.out.print("输入题目的答案：");
        String answer=scn.nextLine();
        Question question=new Question(title,list,answer);
        questions.put(++index,question);
    }
    public void showPaper(){
        System.out.println();
        Set<Integer> s=questions.keySet();
        Iterator<Integer> it=s.iterator();
        while(it.hasNext()){
            int k=it.next();
            System.out.println("第"+k+"题");
            Question q=questions.get(k);
            q.showQuestion();
        }
    }
    public Map<Integer,Question> getQuestions(){
        return questions;
    }
    public int getCount(){
        return count;
    }
}