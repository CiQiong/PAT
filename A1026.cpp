#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int K=111;//窗口数
const int INF=1000000000;//无穷大
struct Player{
	int arriveTime,startTime,trainTime;//到达时间、开始时间及训练时长
	bool isVIP;//是否是VTP球员 
}newPlayer;//临时存放新读入的球员 
struct Table{
	int endTime,numServe;//当前占用该球桌的结束时间及已服务的人数
	bool isVIP;//是否是VIP球桌 
}table[K];//K个球桌 
vector<Player> player;//球员队列
int convertTime(int h,int m,int s){
	return h*3600+m*60+s;
} 
bool cmpArriveTime(Player a,Player b){
	return a.arriveTime<b.arriveTime;//按到达时间先后排序 
}
bool cmpStartTime(Player a,Player b){
	return a.startTime<b.startTime;//按开始时间排序 
}
//编号VIPi从当前VIP球员到下一个VIP球员
int nextVIPPlayer(int VIPi){
	VIPi++;//先将VIPi加1
	while(VIPi<player.size() && player[VIPi].isVIP==0){
		VIPi++;//只要当前球员不是VIP，就让VIPi后移一位 
	} 
	return VIPi;//返回下一个VIP球员的ID 
} 
//将编号为tID的球桌分配给编号为pID的球员
void allotTable(int pID,int tID){
	if(player[pID].arriveTime<=table[tID].endTime){//更新球员的开始时间 
		player[pID].startTime=table[tID].endTime;
	} else {
		player[pID].startTime=player[pID].arriveTime;
	}
	//该球桌的结束时间更新为新球员的结束时间，并让服务人员增加1
	table[tID].endTime=player[pID].startTime+player[pID].trainTime;
	table[tID].numServe++;
} 
int main(){
	int n,k,m,VIPtable;
	scanf("%d",&n);//球员数
	int stTime=convertTime(8,0,0);
	int edTime=convertTime(21,0,0);
	for(int i=0;i<n;i++){
		int h,m,s,trainTime,isVIP;
		scanf("%d:%d:%d %d %d",&h,&m,&s,&trainTime,&isVIP);
		newPlayer.arriveTime=convertTime(h,m,s);//到达时间
		newPlayer.startTime=edTime;//开始时间初始化为21点
		if(newPlayer.arriveTime>=edTime)continue;//21点以后的直接排除
		//训练时长
		newPlayer.trainTime=trainTime<=120?trainTime*60:7200;
		newPlayer.isVIP=isVIP;//是否是VIP
		player.push_back(newPlayer);//将newPlayer加入到队员队列中 
	} 
	scanf("%d%d",&k,&m);//球桌数及VIP球桌数 
	for(int i=1;i<=k;i++){
		table[i].endTime=stTime;//当前训练结束时间为8点
		table[i].numServe=table[i].isVIP=0;//初始化numServe与isVIP 
	} 
	for(int i=0;i<m;i++){
		scanf("%d",&VIPtable);//VIP球桌编号
		table[VIPtable].isVIP=1;//记为VIP球桌 
	}
	sort(player.begin(),player.end(),cmpArriveTime);//按到达时间排序
	int i=0,VIPi=-1;//i又来扫描所有球员，VIPi总是指向当前最前的VIP球员
	VIPi=nextVIPPlayer(VIPi);//找到第一个VIP球员的编号
	while(i<player.size()){
		int idx=-1,minEndTime=INF;//寻找最早能空闲的球桌
		for(int j=1;j<=k;j++){
			if(table[j].endTime<minEndTime){
				minEndTime=table[j].endTime;
				idx=j;
			} 
		}
		//idx为最早空闲的球桌编号
		if(table[idx].endTime>=edTime)break;//已经关门，直接break
		if(player[i].isVIP==1&&i<VIPi){
			i++;//如果i号是VIP球员，但是VIPi>i,说明i号球员已经在训练 
			continue; 
		} 
		
		if(table[idx].isVIP==1){
			if(player[i].isVIP==1){
				allotTable(i,idx);
				if(VIPi==i)VIPi==nextVIPPlayer(VIPi);//找到下一个VIP球员
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
				//最早空闲的VIP球桌编号是VIPidx
				if(VIPidx!=-1&&player[i].arriveTime>=table[VIPidx].endTime){
					
					
					allotTable(i,VIPidx);
					if(VIPi==i)VIPi=nextVIPPlayer(VIPi);
					i++;
				} else {
					
					allotTable(i,idx);
					if(VIPi==i)VIPi=nextVIPPlayer(VIPi);
					i++;
				} 
			}
		}
	} 
	sort(player.begin(),player.end(),cmpStartTime);//按开始时间排序
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
/*

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef struct Node
{
	int arrive, process, tag;
	int serve, wait;//...
}Node;
typedef struct Table
{
	int tag;
	int freeTime, num;//...
}Table;
bool CmpArrive(Node a, Node b)
{
	return a.arrive < b.arrive;
}
bool CmpServe(Node a, Node b)
{
	if(a.serve == b.serve)
		return a.arrive < b.arrive;
	else return a.serve < b.serve;
}
#define INF 0x6FFFFFFF
//vector<bool> visited;
vector<Node> user;
vector<Table> table;
void UpdateInfo(int userID, int tableID)
{
	user[userID].serve = max(user[userID].arrive, table[tableID].freeTime);
	user[userID].wait = user[userID].serve-user[userID].arrive;
	table[tableID].num++;
	table[tableID].freeTime = user[userID].serve+min(user[userID].process, 7200);
}
int main()
{
	//input
	int n;
	scanf("%d",&n);
	
	user.resize(n);
	for(int i = 0; i < n; ++i)
	{
		int h, m, s;
		scanf("%d:%d:%d %d%d",&h,&m,&s,&user[i].process,&user[i].tag);
		user[i].arrive = h*3600+m*60+s;
		user[i].process *= 60;
		user[i].serve = INF; user[i].wait = INF;//initial variable
	}
	int k, m;
	scanf("%d%d",&k,&m);
	
	table.resize(k);
	for(int i = 0; i < k; ++i)
		table[i].freeTime = 8*3600, table[i].tag = 0, table[i].num = 0;
	for(int i = 0; i < m; ++i)
	{
		int c;
		scanf("%d",&c); c--;
		table[c].tag = 1;
	}
	//process
	sort(user.begin(), user.end(), CmpArrive);
	//visited.assign(n, false);
	for(int i = 0; i < n; ++i)
	{
		if(user[i].serve != INF) continue;
		int minFreeTime = INF;
		for(int j = 0; j < k; ++j)
			minFreeTime = min(minFreeTime, table[j].freeTime);
		int timePoint = max(user[i].arrive, minFreeTime);
		if(timePoint >= 21*3600) break;
		vector<int> userList;
		vector<int> tableList;
		for(int j = i; j < n; ++j)
			if(user[j].serve == INF && user[j].arrive <= timePoint) userList.push_back(j);
		for(int j = 0; j < k; ++j)
			if(table[j].freeTime <= timePoint) tableList.push_back(j);
		
		bool flag = false;//record if it is served
		if(userList.size() == 1 && tableList.size() >1)//vip user look for vip table
		{
			if(user[userList[0]].tag == 1)
			{
				for(int j = 0; j < tableList.size(); ++j)
				{
					if(table[tableList[j]].tag == 1)
					{
						flag = true;
						UpdateInfo(userList[0], tableList[j]);
						break;
					}
				}
			}
		}
		else if(tableList.size() == 1 && userList.size() > 1)//vip table can for vip user first
		{
			if(table[tableList[0]].tag == 1)
			{
				for(int j = 0; j < userList.size(); ++j)
				{
					if(user[userList[j]].tag == 1)
					{
						flag = true;
						UpdateInfo(userList[j], tableList[0]);
						break;
					}
				}
			}
		}
		else if(tableList.size() > 1 && userList.size() > 1)//vip table can for vip user first
		{
			for(int t = 0; t < tableList.size(); ++t)
			{
				if(table[tableList[t]].tag == 1)
				{
					for(int u = 0; u < userList.size(); ++u)
					{
						if(user[userList[u]].tag == 1)
						{
							flag = true;
							UpdateInfo(userList[u], tableList[t]);
							break;
						}
					}
				}
			}
		}
		if(!flag) UpdateInfo(userList[0], tableList[0]);
		--i;
	}
	//output
	sort(user.begin(), user.end(), CmpServe);
	for(int i = 0; i < n; ++i)
	{
		if(user[i].serve >= 21*3600) break;
		int h1, m1, s1, h2, m2, s2;
		int t = user[i].arrive;
		h1 = t/3600; t %= 3600;
		m1 = t/60; t %= 60;
		s1 = t;
		t = user[i].serve;
		h2 = t/3600; t %= 3600;
		m2 = t/60; t %= 60;
		s2 = t;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", h1, m1, s1, h2, m2, s2, (user[i].wait+30)/60);
	}
	for(int i = 0; i < k; ++i)
	{
		if(i != k-1)
			printf("%d ",table[i].num);
		else printf("%d\n",table[i].num);
	}
	return 0;
}
*/ 
