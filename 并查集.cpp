#include<cstdio> 
#include<algorithm> 
#include<cmath>
using namespace std;

int father[N];
//��ʼ�� 
for(int i=1;<N;i++){
	father[i]=i;//��father[i]Ϊ-1Ҳ�ɣ��˴���father[i]=iΪ�� 
}
//����
//findFather��������Ԫ��x���ڼ��ϵĸ���� 
//����ʵ�֣� 
int findFather(int x){
	while(x!=father[x]){//������Ǹ���㣬����ѭ�� 
		x=father[x];//����Լ��ĸ��׽�� 
	}
	return x; 
} 
//�ݹ�ʵ�� 
int findFather(int x){
	if(x==father[x])return x;//����ҵ�����㣬�򷵻ظ������x
	else return findFather(father[x]);//���򣬵ݹ��ж�x�ĸ��׽���Ƿ��Ǹ���� 
}
//�ϲ�
void Union(int a,int b){
	int faA=findFather(a);//����a�ĸ���㣬��ΪfaA 
	int faB=findFather(b);//����b�ĸ���㣬��ΪfaB 
	if(faA!=faB){//���������ͬһ������ 
		father[faA]=faB;//�ϲ����� 
	}
} 
//·��ѹ��
int findMother(int x){
	//����x�������while�л��ɸ���㣬��˰�ԭ�ȵ�x����һ��
	int a=x;
	while(x!=father[x]){//Ѱ�Ҹ���� 
		x=father[x];
	} 
	//�����x��ŵ��Ǹ���㡣�����·�������е�father����Ϊ�����
	while(a!=father[a]){
		int z=a;//��ΪaҪ��father[a]���ǣ�����ȱ���a��ֵ�����޸�father[a]
		a=fater[a];//a���ݸ��׽��
		father[z]=x;//��ԭ�ȵĽ��a�ĸ��׸�Ϊ�����x 
	} 
	return x;//���ظ���� 
} 
//�ݹ�д����
int findfather(int x){
	
} 

