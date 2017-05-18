#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int K=111;//������
const int INF=1000000000;//�����
struct Player{
	int arriveTime,startTime,trainTime;//����ʱ�䡢��ʼʱ�估ѵ��ʱ��
	bool isVIP;//�Ƿ���VTP��Ա 
}newPlayer;//��ʱ����¶������Ա 
struct Table{
	int endTime,numServe;//��ǰռ�ø������Ľ���ʱ�估�ѷ��������
	bool isVIP;//�Ƿ���VIP���� 
}table[K];//K������ 
vector<Player> player;//��Ա����
int convertTime(int h,int m,int s){
	return h*3600+m*60+s;
} 
bool cmpArriveTime(Player a,Player b){
	return a.arriveTime<b.arriveTime;//������ʱ���Ⱥ����� 
}
bool cmpStartTime(Player a,Player b){
	return a.startTime<b.startTime;//����ʼʱ������ 
}
//���VIPi�ӵ�ǰVIP��Ա����һ��VIP��Ա
int nextVIPPlayer(int VIPi){
	VIPi++;//�Ƚ�VIPi��1
	while(VIPi<player.size() && player[VIPi].isVIP==0){
		VIPi++;//ֻҪ��ǰ��Ա����VIP������VIPi����һλ 
	} 
	return VIPi;//������һ��VIP��Ա��ID 
} 
//�����ΪtID��������������ΪpID����Ա
void allotTable(int pID,int tID){
	if(player[pID].arriveTime<=table[tID].endTime){//������Ա�Ŀ�ʼʱ�� 
		player[pID].startTime=table[tID].endTime;
	} else {
		player[pID].startTime=player[pID].arriveTime;
	}
	//�������Ľ���ʱ�����Ϊ����Ա�Ľ���ʱ�䣬���÷�����Ա����1
	table[tID].endTime=player[pID].startTime+player[pID].trainTime;
	table[tID].numServe++;
} 
int main(){
	int n,k,m,VIPtable;
	scanf("%d",&n);//��Ա��
	int stTime=convertTime(8,0,0);
	int edTime=convertTime(21,0,0);
	for(int i=0;i<n;i++){
		int h,m,s,trainTime,isVIP;
		scanf("%d:%d:%d %d %d",&h,&m,&s,&trainTime,&isVIP);
		newPlayer.arriveTime=convertTime(h,m,s);//����ʱ��
		newPlayer.startTime=edTime;//��ʼʱ���ʼ��Ϊ21��
		if(newPlayer.arriveTime>=edTime)continue;//21���Ժ��ֱ���ų�
		//ѵ��ʱ��
		newPlayer.trainTime=trainTime<=120?trainTime*60:7200;
		newPlayer.isVIP=isVIP;//�Ƿ���VIP
		player.push_back(newPlayer);//��newPlayer���뵽��Ա������ 
	} 
	scanf("%d%d",&k,&m);//��������VIP������ 
	for(int i=1;i<=k;i++){
		table[i].endTime=stTime;//��ǰѵ������ʱ��Ϊ8��
		table[i].numServe=table[i].isVIP=0;//��ʼ��numServe��isVIP 
	} 
	for(int i=0;i<m;i++){
		scanf("%d",&VIPtable);//VIP�������
		table[VIPtable].isVIP=1;//��ΪVIP���� 
	}
	sort(player.begin(),player.end(),cmpArriveTime);//������ʱ������
	int i=0,VIPi=-1;//i����ɨ��������Ա��VIPi����ָ��ǰ��ǰ��VIP��Ա
	VIPi=nextVIPPlayer(VIPi);//�ҵ���һ��VIP��Ա�ı��
	while(i<player.size()){
		int idx=-1,minEndTime=INF;//Ѱ�������ܿ��е�����
		for(int j=1;j<=k;j++){
			if(table[j].endTime<minEndTime){
				minEndTime=table[j].endTime;
				idx=j;
			} 
		}
		//idxΪ������е��������
		if(table[idx].endTime>=edTime)break;//�Ѿ����ţ�ֱ��break
		if(player[i].isVIP==1&&i<VIPi){
			i++;//���i����VIP��Ա������VIPi>i,˵��i����Ա�Ѿ���ѵ�� 
			continue; 
		} 
		
		if(table[idx].isVIP==1){
			if(player[i].isVIP==1){
				allotTable(i,idx);
				if(VIPi==i)VIPi==nextVIPPlayer(VIPi);//�ҵ���һ��VIP��Ա
				i++; 
			} else {
				
				if(VIPi<player.size()&&player[VIPi].arriveTime<=table[idx].endTime){
					allotTable(VIPi,idx);
					VIPi==nextVIPPlayer(VIPi);
				} else {
					
					allotTable(i,idx);
					i++;
				}
			}
		} else {
			if(player[i].isVIP==0){
				allotTable(i,idx);
				i++;
			} else {
				
				int VIPidx=-1,minVIPEndTime=INF;
				for(int j=1;j<=k;j++){
					if(table[j].isVIP==1&&table[j].endTime<minVIPEndTime){
						minVIPEndTime=table[j].endTime;
						VIPidx=j;
					}
				}
				//������е�VIP���������VIPidx
				if(VIPidx!=-1&&player[i].arriveTime>=table[VIPidx].endTime){
					
					
					allotTable(i,VIPidx);
					if(VIPi==i)VIPi=nextVIPPlayer(VIPi);
					i++;
				} 
			}
		}
	} 
	sort(player.begin(),player.end(),cmpStartTime);//����ʼʱ������
	for(i=0;i<player.size()&&player[i].startTime<edTime;i++){
		int t1=player[i].arriveTime;
		int t2=player[i].startTime;
		printf("%02d:%02d:%02d ",t1/3600,t1%3600/60,t1%60);
		printf("%02d:%02d:%02d ",t2/3600,t2%3600/60,t2%60);
		printf("%.0f\n",round((t2-t1)/60.0));
	} 
	for(i=1;i<=k;i++){
		printf("%d",table[i].numServe);
		if(i<k)printf(" ");
	}
	return 0;
	
}
