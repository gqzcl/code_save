#include<iostream>
using namespace std;
typedef struct{
	int data;
	int *cur;
	int length;
	int listsize;
}sqlist;
Status InitList(sqlist &L){
	L.cur=(int*)malloc(1000*sizeof(int));
	if(!L.cur)
		return 1;
	L.length=0;
	L.listsize=1000;
	return 0;
}
void mergelist(SqList La,sqlist sqlist Lb,sqlist &Lc){
	int *pa=La.cur;
	int *pb=Lb.cur;
	Lc.listsize=Lc.length=La.length+Lb.length;
	pc=Lc.cur=(int*)malloc(Lc.listsize*sizeof(int));
	if(!Lc.cur)
		return 1;
	int *pa_last=La.cur+La.length-1;
	int *pb_last=Lb.cur+La.length-1;
	while(pa<=pa_last&&pb<=pb_last){
		if(*pa<=*pb)
			*pc++=*pa++;
		else 
			*pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;
	while(pb<=pb_last) *pc++=*pb++;
}
int main(){
	SqList S1,S2;
	int a;
}
