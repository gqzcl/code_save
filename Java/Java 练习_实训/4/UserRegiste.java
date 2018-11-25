import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;

public class UserRegiste {
	private List<String> users;
	public UserRegiste(){
		users =new LinkedList<String>();
	}
	public void registe(String email)throws EmailExistException{
		if(email.equalsIgnoreCase("zhangsan@126.com")){
			throw new EmailExistException("该邮箱已注册...");
		}else{
			users.add(email);
		}
	}
	public static void main(String[] args){
		Scanner scn=new Scanner(System.in);
		System.out.print("邮箱");
		String email=scn.next();
		try{
			new UserRegiste().registe(email);
		}catch(EmailExistException e){
			e.printStackTrace();
		}
	}
}
