#include<iostream>
#include<vector>
using namespace std;
struct Matrix:vector<vector<int> >//ʹ�ñ�׼����vector�����࣬��#include���
{
  Matrix(int x=0,int y=0,int z=0)//��ʼ����Ĭ��Ϊ0��0�пվ���
  {
    assign(x,vector<int>(y,z));
  }
  int h_size()const//����˵������ʡ����������޷�ͨ��
  {
    return size();
  }
  int l_size()const
  {
    return empty()?0:front().size();//����Ҫ���ǿվ�������
  }
  Matrix pow(int k);//�����k���ݣ��ÿ�����ʵ�֣�kΪ0ʱ���ش˾���ĵ�λ����
};
Matrix operator*(const Matrix &m,const Matrix &n)//�������ñ��⿽��
{
  if(m.l_size()!=n.h_size())return Matrix();//�Ƿ����㷵�ؿվ���
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
