#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<set>
#include<map>
using namespace std;

struct BigInteger {
  static const int BASE = 10000;
  static const int WIDTH = 4;
  vector<int> s;

  BigInteger(long long num = 0) { *this = num; } // 构造函数
  BigInteger operator = (long long num) { // 赋值运算符
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0);
    return *this;
  }

  BigInteger operator = (const string& str) { // 赋值运算符
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for(int i = 0; i < len; i++) {
      int end = str.length() - i*WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end-start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return *this;
  }

  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i++) {
      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if(i < s.size()) x += s[i];
      if(i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }

    BigInteger operator * (const BigInteger& b) const
  {
  	BigInteger c;
  	c.s.clear();
  	c.s.resize(s.size()+c.s.size()+2);
    int i,g=0,j,k;
    for(i=0;i<s.size();i++)
    {
    	for(j=0;j<b.s.size();j++)
    	{
    		c.s[i+j]+=s[i]*b.s[j];
		}
	}
	for(i=0;i<s.size()+c.s.size()+1;i++)
	{
		if(c.s[i]>BASE)
		{
			c.s[i+1]+=c.s[i]/BASE;
			c.s[i]%=BASE;
		}
	}
	while(c.s.back()==0)
		c.s.pop_back();
    return c;
  }
};

ostream& operator << (ostream &out, const BigInteger& x) {
  out << x.s.back();
  for(int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%04d", x.s[i]);
    for(int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;
}

istream& operator >> (istream &in, BigInteger& x) {
  string s;
  if(!(in >> s)) return in;
  x = s;
  return in;
}

int main() {

  BigInteger a, b;
  while(cin>>a>>b)
  //cin >> a >> b;
  {
  cout << a * b << "\n";
}
  return 0;

}

