import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
public class Question {
	private String title;
	private List<String> options;
	private String answer;
	public Question(){
		options=new ArrayList<String>();
	}
	public Question(String title,List<String> options,String answer){
		this.title=title;
		this.options=options;
		this.answer=answer;
	}
	public void showQuestion(){
		System.out.println(":"+title);
		Iterator<String> it=options.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
	}
	public String getAnswer(){
		return answer;
	}
}
