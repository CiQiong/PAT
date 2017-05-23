#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct Car{
	char id[8];//���ƺ�
	int time;//��¼��ʱ�̣���sΪ��λ
	char status[4];//in����out 
}all[maxn],valid[maxn];//allΪ���м�¼��validΪ��Ч��¼ 
int num=0;//��Ч��¼������ 
map<string,int> parkTime;//���ƺ�->��ͣ��ʱ��
//timeToInt��ʱ��ת��Ϊ��sΪ��λ 
int timeToInt(int hh,int mm,int ss){
	return hh*3600+mm*60+ss;
} 
//�Ȱ����ƺ��ֵ����С�������������ƺ���ͬ����ʱ���С��������
bool cmpByIDAndTime(Car a,Car b){
	if(strcmp(a.id,b.id)) return strcmp(a.id,b.id)<0;
	else return a.time<b.time;
} 

bool cmpByTime(Car a,Car b){
	return a.time<b.time;
}
int main(){
	int n,k,hh,mm,ss;
	scanf("%d%d",&n,&k);//��¼������ѯ��
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d %s",all[i].id,&hh,&mm,&ss,all[i].status);
		all[i].time=timeToInt(hh,mm,ss);//ת��Ϊ��sΪ��λ 
	} 
	sort(all,all+n,cmpByIDAndTime);
	int maxTime=-1;//���ͣ��ʱ��
	for(int i=0;i<n-1;i++){//�������м�¼ 
		if(!strcmp(all[i].id,all[i+1].id)&&!strcmp(all[i].status,"in")&&!strcmp(all[i+1].status,"out")){
			valid[num++]=all[i];//i��i+1����Եģ�����valid���� 
			valid[num++]=all[i+1];
			int inTime=all[i+1].time-all[i].time;//�˴�ͣ��ʱ��
			if(parkTime.count(all[i].id)==0){
				parkTime[all[i].id]=0;//map�л�û��������ƺţ����� 
			} 
			parkTime[all[i].id]+=inTime;//���Ӹó��ƺŵ���ͣ��ʱ�� 
		}
	} 
	sort(valid,valid+num,cmpByTime);//����Ч��¼��ʱ���С��������
	//nowָ�򲻳�����ǰ��ѯʱ��ļ�¼��numCarΪ��ǰѧУ�ڵĳ�����
	int now=0,numCar=0;
	for(int i=0;i<k;i++){//k����ѯ 
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int time=timeToInt(hh,mm,ss);
		//��now��������ǰ��ѯʱ��
		while(now<num&&valid[now].time<=time){
			if(!strcmp(valid[now].status,"in")) numCar++;//��������
			else numCar--;//�����뿪
			now++;//ָ����һ����¼ 
		} 
		printf("%d\n",numCar);//�����ʱ��У԰�ڵĳ����� 
	} 
	map<string,int>::iterator it;//�������г��ƺ�
	for(it=parkTime.begin();it!=parkTime.end();it++){
		if(it->second==maxTime){//����������ͣ��ʱ��ĳ��ƺ� 
			printf("%s ",it->first.c_str());
		}
	} 
	//������ͣ��ʱ��
	printf("%02d:%02d:%02d\n",maxTime/3600,maxTime%3600/60,maxTime%60);
	return 0; 
}
