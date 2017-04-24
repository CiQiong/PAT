#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int  n, k, p, maxFacSum=-1;//最大底数和
vector<int>fac,ans,temp;
//fac记录
//ans存放最优底数序列，temp存放递归中的临时底数列表 
int power(int x){
	int ans=1;
	for(int i=0;i<p;i++){
		ans*=x;
	}
	return ans;
}
//init函数与处理fac数组，注意把0也存进去 
void init(){
	int i=0,temp=0;
	while(temp<=n){
		fac.push_back(temp);
		temp=power(++i);
	}
} 
//DFS函数，当前访问fac[index],nowK为当前选中个数
//sum为当前选中的数之和，facSun为当前选中的底数之和
void DFS(int index,int nowK,int sum,int facSum){
	if(sum==n&&nowK==k){//找到一个满足的序列 
		if(facSum>maxFacSum){//底数之和更优 
			ans=temp;//更新最优底数序列
			maxFacSum=facSum;//更新最大底数和 
		} 
		return; 
	}
	if(sum>n||nowK>k)return;
	if(index-1>=0){
		DFS(index,nowK+1,sum+fac[index],facSum+index);//"选"的分支
		temp.pop_back();
		DFS(index-1,nowK,sum,facSum); //"不选"的分支
	}
} 
int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(maxFacSum==-1)printf("Impossible\n");
	else{
		printf("%d=%d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
	return 0;
}
