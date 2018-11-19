#include<iostream>
using namespace std;
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void maopaosort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
		}
	}
	}
	printArray(arr,n);
 
}
void choicesort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int k=i;
		for(int j=k+1;j<n;j++)
		{
			if(arr[j]<arr[k])//k��λ����Сֵ 
				k=j;	
		}
		int temp=arr[i];
		arr[i]=arr[k];
		arr[k]=temp;	
	}
	printArray(arr,n);
}

void insertsort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			int wait=arr[i];
			int j=i;
			while(j>0&&arr[j-1]>wait)//�Ӻ���ǰ�������������飬��������Ԫ��С�ڱ�����Ԫ�أ������Ԫ�����Ųλ��
			{
				arr[j]=arr[j-1];
				j--;
			}
			arr[j]=wait;
		}
	}
	printArray(arr,n);
}

void quicksort(int arr[],int left,int right)
{
	if (left > right){
		return;
	}
	int i, j, temp;
	i = left;
	j = right;
	temp = arr[left];
	while (i != j){
		while (arr[j] >= temp && i < j) {
			j--;
		}
		while (arr[i] <= temp && i < j){
			i++;
		}
		if (i < j){
			int change = arr[i];
			arr[i] = arr[j];
			arr[j] = change;
		}
	}
	arr[left] = arr[j];
	arr[j] = temp;
	quicksort(arr, left, i-1);
	quicksort(arr, i + 1, right);
}

void merge(int array[], int low, int mid, int high){//ʵ������������鲢 
	int i = low;
	int j = mid + 1;
	int *temp = new int[high - low + 1];
	int count = 0;
	while (i <= mid && j <= high)
	{
		//���αȽ����������С������Ȼ��װ��temp����
		if (array[i] <= array[j])
		{
			temp[count++] = array[i++];
		}
		else
		{
			temp[count++] = array[j++];
		}
	}
	while (i <= mid)
	{
		temp[count++] = array[i++];
	}
	while (j <= high)
	{
		temp[count++] = array[j++];
	}
	for (int i = low,k=0; i <= high; i++,k++)
	{
		array[i] = temp[k];
	}
	delete []temp;
}

void cutsort(int array[],int low,int high){
	//�ָ����飬һ��Ϊ2������Ϊ�ģ�����
	int mid = (low + high) / 2;
	if (low < high){
		cutsort(array, low, mid);
		cutsort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

 void shellsort(int arr[],int n) //ϣ�������ǲ�������ĸ�Ч�Ľ��� 
 {
 	int t=n;
	while (true)
	{
		n= n/2;
        for (int x=0;x<n;x++) 
		{
			for (int i=x+n; i<t;i=i+n) 
			{    
                int temp=arr[i];
                int j;
				for(j=i-n;j>=0&&arr[j]>temp;j=j-n)
				{
                    arr[j+n]=arr[j];
                }
                arr[j+n]=temp;
            }
        }
        if (n==1) 
            break;
    }
    printArray(arr,t);
}

int main() 
{
	int n;
	while(cin>>n)
	{
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		maopaosort(arr,n);
		choicesort(arr,n);
		insertsort(arr,n);
		quicksort(arr,0,n);
		printArray(arr,n);
		cutsort(arr,0,n);
		printArray(arr,n);
		shellsort(arr,n);
	}
	return 0;
}

