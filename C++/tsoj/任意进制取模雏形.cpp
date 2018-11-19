#include <iostream>    
#include <string.h>    
#include <math.h>    
using namespace std;  
//将一个字符型数字转化成整型数字  
int charToNum(char num)    
{    
    //num在'0'-'9'   
    if(num<='9'&&num>='0')    
    {    
        num-=48;    
    }    

    //num在'A/a'到'F/f'   
    else    
    {    
          switch(num)    
        {    
        case 'A':    
        case 'a':    
            num=10;    
        case 'B':    
        case 'b':    
            num=11;    
        case 'C':    
        case 'c':    
            num=12;    
        case 'D':    
        case 'd':    
            num=13;    
        case 'E':    
        case 'e':    
            num=14;    
        case 'F':    
        case 'f':    
            num=15;    
        }    
    }    
    return num;    
}   
//将任意进制整数转化为十进制整数  
int convertToDecimal(string num,int binary)  //num为任意进制整数，binary为该整数的进制   
{    
    int len=num.size();    
    int decimal_num=0;    
    for(int i=0;i<len;i++)    
    {    
        decimal_num+=charToNum(num[i])*pow(binary,len-i-1);    
    }    
    return decimal_num;    
}    
int main(){  
    string str;  
    cout<<"输入二进制串："<<endl;  
    cin>>str;  
    int decimal_num=convertToDecimal(str,2);  
    int result=decimal_num%3;  
    cout<<"二进制串除以3的余数:" <<endl;  
    cout<<result;  
    return 0;  
}  

