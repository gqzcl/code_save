#include <iostream> 
#include <cstdio> 
#include <stack>  
using namespace std;   
bool judge(char c)  
{  
    return (c == '('  || c == '{');  
}  
  
bool match(char right, char left)  
{  
    if (right == ')')  
    {  
        return (left == '(');  
    }  
  
    if (right == '}')  
    {  
        return (left == '{');  
    }  
}  
   
bool matching(char* s)  
{  
    stack<char> arr;  
    char c;  
    while (*s)  
    {  
        c = *s;  
        if (judge(c))  
        {  
            arr.push(c);  
        }  
        else if(c==')'||c=='}') 
        {  
            if (arr.empty() || !match(c, arr.top()))  
            {  
                return false;  
            }  
  
            arr.pop();  
        }  
        ++s;  
    }  
  
    if (!arr.empty())  
    {  
        return false;  
    }  
    return true;  
}  
int main()  
{  
	int n;
	cin>>n;
	char c=getchar();
    char arr1[100];
    while(n--)
    {
    	gets(arr1);
    if (matching(arr1))  
    {  
        cout <<  "Yes" << endl;  
    }  
    else  
    {  
        cout << "No" << endl;  
    }  
	}
    return 0;  
}  
