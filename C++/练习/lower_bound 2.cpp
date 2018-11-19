#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class person
{
private:
  int age;//����
  double height;//���
  string name;//����
public:
  person():age(0),height(0.0){}
  person(const int age_,const double height_,const string &name_):age(age_),height(height_),name(name_) {}
  int key1() const
  {
    return age;
  }
  double key2() const
  {
    return height;
  }
 string &key3() 
  {
    return name;
  }
};
struct compareByTwoKey
{
  template<class T1,class T2>
  int operator()(const T1 &t1,const T2 &t2)
  {
    if(t1.key1()<t2.key1())
      return true;
    else
      if(t1.key1()==t2.key1())
      {
        if(t1.key2()<t2.key2())
          return true;
        else
          return false;
      }
      else
        return false;
  }
};
void init_data(vector<person> &v)
{
  v.push_back(person(12,96.8,"���"));
  v.push_back(person(12,86.9,"���"));
  v.push_back(person(13,76.8,"���"));
  v.push_back(person(13,77.8,"���"));
  v.push_back(person(10,70.8,"���"));
  v.push_back(person(15,79.8,"���"));
  v.push_back(person(18,176.8,"���"));
  v.push_back(person(2,6.8,"���"));
  v.push_back(person(12,55.8,"���"));
  v.push_back(person(12,97.8,"hello"));
  sort(v.begin(),v.end(),compareByTwoKey());//һ��Ҫ�������򣬲�����������lower_boundһ��
}
int main()
{
  vector<person> v;
  init_data(v);
  person val(12,90.0,"hello");
  vector<person>::iterator iter=lower_bound(v.begin(),v.end(),val,compareByTwoKey());//��sort����һ��
  system("pause");
}

