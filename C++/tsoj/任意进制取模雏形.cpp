#include <iostream>    
#include <string.h>    
#include <math.h>    
using namespace std;  
//��һ���ַ�������ת������������  
int charToNum(char num)    
{    
    //num��'0'-'9'   
    if(num<='9'&&num>='0')    
    {    
        num-=48;    
    }    

    //num��'A/a'��'F/f'   
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
//�������������ת��Ϊʮ��������  
int convertToDecimal(string num,int binary)  //numΪ�������������binaryΪ�������Ľ���   
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
    cout<<"��������ƴ���"<<endl;  
    cin>>str;  
    int decimal_num=convertToDecimal(str,2);  
    int result=decimal_num%3;  
    cout<<"�����ƴ�����3������:" <<endl;  
    cout<<result;  
    return 0;  
}  

