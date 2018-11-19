#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>nums;
	nums.push_back(-242);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(11);
	cout<<"Beforenumsis:";
	for(unsigned int i=0;i<nums.size();i++){
		cout<<nums[i]<<"";
	}
	cout<<endl;
	vector<int>::iterator result;
	int new_val=7;
	result=lower_bound(nums.begin(),nums.end(),new_val);
	nums.insert(result,new_val);
	cout<<"After,numsis:";
	for(unsigned int i=0;i<nums.size();i++){
		cout<<nums[i]<<"";
	}
	cout<<endl;
}

