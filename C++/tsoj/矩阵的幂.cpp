#include<iostream>
#include<vector>
using namespace std;
struct Matrix:vector<vector<int> >//使用标准容器vector做基类，需#include语句
{
  Matrix(int x=0,int y=0,int z=0)//初始化，默认为0行0列空矩阵
  {
    assign(x,vector<int>(y,z));
  }
  int h_size()const//常量说明不可省，否则编译无法通过
  {
    return size();
  }
  int l_size()const
  {
    return empty()?0:front().size();//列数要考虑空矩阵的情况
  }
  Matrix pow(int k);//矩阵的k次幂，用快速幂实现，k为0时返回此矩阵的单位矩阵
};
Matrix operator*(const Matrix &m,const Matrix &n)//常量引用避免拷贝
{
  if(m.l_size()!=n.h_size())return Matrix();//非法运算返回空矩阵
  Matrix ans(m.h_size(),n.l_size());
  for(int i=0; i!=ans.h_size(); ++i)
    for(int j=0; j!=ans.l_size(); ++j)
      for(int k=0; k!=m.l_size(); ++k)
        ans[i][j]+=m[i][k]*n[k][j];
  return ans;
}
Matrix Matrix::pow(int k)
{
  if(k==0)
  {
    Matrix ans(h_size(),h_size());
    for(int i=0; i!=ans.h_size(); ++i)
      ans[i][i]=1;
    return ans;
  }
  if(k==2)return (*this)*(*this);
  if(k%2)return pow(k-1)*(*this);
  return pow(k/2).pow(2);
}
int main()
{
	return 0;
}
