#include<iostream>
using namespace std;
template<typename A>
A sum(A* begin,A* end)
{
	A*p=begin;
	A ans=0;
	for(A*p=begin;p!=end;p++)
		ans=ans+*p;
	return ans; 
} 
struct Point
{
	int x,y;
	Point(int x=0,int y=0):x(x),y(y){
	}
};
Point operator +(const Point& A,Point& B)
{
	return Point(A.x+B.x,A.y+B.y);
}
ostream& operator << (ostream &out,const Point& p)
{
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}
int main()
{
	double a[]={1.1,2.2,3.3,4.4};
	cout<<sum(a,a+4)<<endl;
	Point b[]={Point(1,2),Point(3,4),Point(5,6),Point(7,8)};
	cout<<sum(b,b+4)<<endl;
	return 0;
}

