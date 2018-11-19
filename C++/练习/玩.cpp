#include<stdio.h>  
#include<string.h>  
char s[20003];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    getchar();  
    while(t--){  
        int top=0;  
        char ch;  
        while((ch=getchar())!='\n'){  
            if(ch==')' && top>0 && s[top-1]=='(')  
                top--;  
            else if(ch=='}' && top>0 && s[top-1]=='{')  
                top--;  
            else    s[top++]=ch;  
        }  
        if(top==0)  printf("Yes\n");  
        else    printf("No\n");  
    }  
    return 0;  
}  
