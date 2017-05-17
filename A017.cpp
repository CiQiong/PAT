#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int K=111;
const int INF=1000000000; 
struct Customer{
	int comeTime,serveTime;//�ͻ������ʱ�估����ʱ�� 
}newCustomer;//newCustomer��ʱ����¿ͻ�����Ϣ
vector<Customer> custom;//ģ�����
int convertTime(int h,int m,int s){
	return h*3600+m*60+s;//��ʱ��ת��Ϊ����Ϊ��λ������ȽϺͼ��� 
}
bool cmp(Customer a,Customer b){//���ͻ�����ʱ������ 
	return a.comeTime<b.comeTime;
} 
int endTime[K];//endTime[i]��¼i�Ŵ��ڵĵ�ǰ����ͻ��Ľ���ʱ��
int main(){
	int c,w,totTime=0;//totTime��¼�ܵȴ�ʱ��
	int stTime=convertTime(8,0,0);//����ʱ��
	int edTime=convertTime(17,0,0);//����ʱ��
	scanf("%d%d",&c,&w);//�ͻ�����������
	for(int i=0;i<w;i++){
		endTime[i]=stTime;//û�пͻ�����ʼ��ΪstTime 
	}
	for(int i=0;i<c;i++){
		int h,m,s,serveTime;//ʱ���֣��룬����ʱ��
		scanf("%d:%d:%d %d",&h,&m,&s,&serveTime);
		int comeTime=convertTime(h,m,s);//����ʱ��ת��Ϊ����Ϊ��λ
		if(comeTime>edTime) continue;//��������ʱ�䣬��������
		newCustomer.comeTime=comeTime;
		newCustomer.serveTime=serveTime<=60?serveTime*60:3600;
		custom.push_back(newCustomer);//�¿ͻ����� 
	}
	sort(custom.begin(),custom.end(),cmp);//������ʱ������
	for(int i=0;i<custom.size();i++){
		int idx=-1,minEndTime=INF;//ѡ��ǰ�����������Ĵ���
		for(int j=0;j<w;j++){
			if(endTime[j]<minEndTime){
				minEndTime=endTime[j];
				idx=j;
			}
		} 
		//idxΪ�����������ı�ţ����ͻ�custom[i]���䵽�ô���
		if(endTime[idx]<=custom[i].comeTime){
			//����ͻ�custom[i]�ڴ���idx����֮���������ֱ�ӽ��ܷ���
			endTime[idx]=custom[i].comeTime+custom[i].serveTime; 
		} else {//����ͻ�custom[i]����̫�磬����ȴ����ȴ�ʱ�����totTime 
			totTime+=(endTime[idx]-custom[i].comeTime);
			endTime[idx]+=custom[i].serveTime;
		}
	} 
	if(custom.size()==0)printf("0.0");//û���ڹ涨ʱ���ڵĿͻ�
	else printf("%.1f",totTime/60.0/custom.size());
	return 0;
} 

