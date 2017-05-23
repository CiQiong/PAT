#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct pNode{
	char id[20];
	int hh,mm,ss;
}temp,ans1,ans2;
//temp表示临时变量，ans也就是answer答案。
//ans1存放最早时间，ans2存放最晚时间 
bool great(pNode node1,pNode node2){
	if(node1.hh!=node2.hh)return node1.hh>node2.hh;
	if(node1.mm!=node2.mm)return node1.mm>node2.mm;//不用写else，因为前面有return 
	return node1.ss>node2.ss;//不用写else，因为前面有return
}
int main(){
	int n;
	scanf("%d",&n);
	ans1.hh=24,ans1.mm=60,ans1.ss=60;
	ans2.hh=0,ans2.mm=0,ans2.ss=0;
	//while(n--){
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans1)==false)ans1=temp;
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans2)==true)ans2=temp;
	}
	printf("%s %s\n",ans1.id,ans2.id);
	return 0;
} 
