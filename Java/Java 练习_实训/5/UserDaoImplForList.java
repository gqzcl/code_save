import java.util.ArrayList;
import java.util.List;

public class UserDaoImplForList implements UserDao{
	private List<User>users;
	public void UmsDaoImplForList() {
		users=new ArrayList<User>();
	}
	public void insert(User user) {
		users.add(user);
	}
	public List<User>selectAll(){
		return users;
	}
	public User selectByEmail(String email) {
		for(int i=0;i<users.size();i++) {
			User user=users.get(i);
			if(user.getEmail().equals(email)) {
				return user;
			}
		}
		return null;
	}
}
