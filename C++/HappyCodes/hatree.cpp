#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char * *HuffmanCode;
int min(HuffmanTree HT,int k)
{
	int i = 0;
	int min;       
	int min_weight; 
	while(HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;
	for(;i<k;i++)
	{
		if(HT[i].weight<min_weight && HT[i].parent==-1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}
	HT[min].parent = 1; 
 
	return min;
}
void select_minium(HuffmanTree HT,int k,int &min1,int &min2)
{
	min1 = min(HT,k);
	min2 = min(HT,k);
}


HuffmanTree create_HuffmanTree(int *wet,int n)
{
	int total = 2*n-1;
	HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
	if(!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;
	for(i=0;i<n;i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = *wet;
		wet++;
	}
	for(;i<total;i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}
 
	int min1,min2;
	for(i=n;i<total;i++)
	{
		select_minium(HT,i,min1,min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight =HT[min1].weight + HT[min2].weight;
	}
	return HT;
}
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)
{
	HC = (HuffmanCode)malloc(n*sizeof(char *));
	if(!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}
	char *code = (char *)malloc(n*sizeof(char));
	if(!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}
 
	code[n-1] = '\0'; 
	int i;
	for(i=0;i<n;i++)
	{
		int current = i;         
		int father = HT[i].parent; 
		int start = n-1;           
		while(father != -1)
		{
			if(HT[father].lchild == current)  
				code[--start] = '0';    
			else                               
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		HC[i] = (char *)malloc((n-start)*sizeof(char));
		if(!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}

		strcpy(HC[i],code+start);
	}
 
	free(code);
}
int main(){
    string s="CAS;CAT;SAT;AT";//4 3 3 3 2 2
    int n;
    while(cin>>n){
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        HuffmanCode HC;
        HuffmanCoding(create_HuffmanTree(a,n),HC,n);
        for(int i=0;i<n;i++)
            cout<<HC[i]<<endl;
    }
}