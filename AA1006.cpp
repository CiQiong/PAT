//����������
//������ÿ�У�����������ʱ�䣬�ߵ�ʱ��
//���������������ߵ���������
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,mincome=24*60*60,maxleave=0,hh,mm,ss;
	string minname,maxname;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string tempname;
		cin>>tempname;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int temp=hh*3600+mm*60+ss;
		if(temp<mincome){
			mincome=temp;
			minname=tempname;
		}
		scanf("%d:%d:%d",&hh,&mm,&ss);
		temp=hh*3600+mm*60+ss;
		if(temp>maxleave){
			maxleave=temp;
			maxname=tempname;
		}
	}
	cout<<minname<<" "<<maxname;
	return 0;
} 
