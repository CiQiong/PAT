#include<cstdio> 
#include<algorithm> 
#include<cmath>
using namespace std;

int father[N];
//初始化 
for(int i=1;<N;i++){
	father[i]=i;//令father[i]为-1也可，此处以father[i]=i为例 
}
//查找
//findFather函数返回元素x所在集合的根结点 
//递推实现： 
int findFather(int x){
	while(x!=father[x]){//如果不是根结点，继续循环 
		x=father[x];//获得自己的父亲结点 
	}
	return x; 
} 
//递归实现 
int findFather(int x){
	if(x==father[x])return x;//如果找到根结点，则返回根结点编号x
	else return findFather(father[x]);//否则，递归判断x的父亲结点是否是根结点 
}
//合并
void Union(int a,int b){
	int faA=findFather(a);//查找a的根结点，记为faA 
	int faB=findFather(b);//查找b的根结点，记为faB 
	if(faA!=faB){//如果不属于同一个集合 
		father[faA]=faB;//合并它们 
	}
} 
//路径压缩
int findMother(int x){
	//由于x在下面的while中会变成根结点，因此把原先的x保存一下
	int a=x;
	while(x!=father[x]){//寻找根结点 
		x=father[x];
	} 
	//到这里，x存放的是根结点。下面把路径上所有的father都改为根结点
	while(a!=father[a]){
		int z=a;//因为a要被father[a]覆盖，因此先保存a的值，以修改father[a]
		a=fater[a];//a回溯父亲结点
		father[z]=x;//将原先的结点a的父亲改为根结点x 
	} 
	return x;//返回根结点 
} 
//递归写法：
int findfather(int x){
	
} 

