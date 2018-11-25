public class TestExam{
    public static void main(String[] args){
        Student student=new Student("Lucy");
        Exam exam=new Exam(student);
        exam.exam();
    }
}