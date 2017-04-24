#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int  n, k, p, maxFacSum=-1;//��������
vector<int>fac,ans,temp;
//fac��¼
//ans������ŵ������У�temp��ŵݹ��е���ʱ�����б� 
int power(int x){
	int ans=1;
	for(int i=0;i<p;i++){
		ans*=x;
	}
	return ans;
}
//init�����봦��fac���飬ע���0Ҳ���ȥ 
void init(){
	int i=0,temp=0;
	while(temp<=n){
		fac.push_back(temp);
		temp=power(++i);
	}
} 
//DFS��������ǰ����fac[index],nowKΪ��ǰѡ�и���
//sumΪ��ǰѡ�е���֮�ͣ�facSunΪ��ǰѡ�еĵ���֮��
void DFS(int index,int nowK,int sum,int facSum){
	if(sum==n&&nowK==k){//�ҵ�һ����������� 
		if(facSum>maxFacSum){//����֮�͸��� 
			ans=temp;//�������ŵ�������
			maxFacSum=facSum;//������������ 
		} 
		return; 
	}
	if(sum>n||nowK>k)return;
	if(index-1>=0){
		DFS(index,nowK+1,sum+fac[index],facSum+index);//"ѡ"�ķ�֧
		temp.pop_back();
		DFS(index-1,nowK,sum,facSum); //"��ѡ"�ķ�֧
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
