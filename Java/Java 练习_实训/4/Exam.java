import java.util.Scanner;
import java.util.Set;
import java.util.Iterator;
import java.util.InputMismatchException;
public class Exam{
    private Student student;
    private Paper paper;
    private AnswerSheet answerSheet;
    public Exam(){
    }
    public Exam(Student student){
        this.student=student;
    }
    private void createPaper(){
        System.out.print("输入题目的个数：");
        Scanner scn=new Scanner(System.in);
        try{
            int count=scn.nextInt();
            paper=new Paper(count);
            paper.showPaper();
        }catch(InputMismatchException e){
            System.out.println("题目必须是数字，程序结束");
        }
    }
    private void answerQuestions(){
        System.out.println();
        Scanner scn=new Scanner(System.in);
        answerSheet=new AnswerSheet();
        for(int i=0;i<paper.getCount();){
            System.out.print("请输入要答题的序号:");
            int key=scn.nextInt();
            if(key>=1&&key<=paper.getCount()){
                System.out.print("请输入答案：");
                String answer=scn.next();
                answerSheet.addAnswer(key,answer);
                i++;
            }else{
                System.out.println("没有这道题！");
            }
        }
    }
    private void showScoreOfPaper(){
        System.out.println("\n考生"+student.getName());
        int right=0;
        Set<Integer> s=paper.getQuestions().keySet();
        Iterator<Integer> it=s.iterator();
        while(it.hasNext()){
            int k=it.next();
            System.out.print("第"+k+"题：");
            String answer1=paper.getQuestions().get(k).getAnswer();
            System.out.print("标准答案"+answer1+"\t");
            String answer2=answerSheet.getAnswers().get(k);
            System.out.println("用户答案"+answer2);
            if(answer1.equalsIgnoreCase(answer2)){
                right++;
            }
        }
        System.out.println("共答对"+right+"道题目！");
    }
    public void exam(){
        createPaper();
        answerQuestions();
        showScoreOfPaper();
    }
}