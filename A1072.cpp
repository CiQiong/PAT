#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=1020;
const int INF=1000000000;

int n,m,k,DS,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV]={false};

void Dijkstra(int s){
	memset(vis,false,sizeof(vis));
	fill(d,d+MAXV,INF);
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n+m;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<n+m;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(G[u][v]+d[u]<d[v]){
					d[v]=d[u]+G[u][v];
				}
			}
		}
	}
} 

//将str[]转化为数字，若str为数字，则返回去掉G之后的数加上n
int getID(char str[]){
	int i=0,len=strlen(str),ID=0;
	while(i<len){
		if(str[i]!='G'){//只要不是G就转化为数字 
			ID=ID*10+(str[i]-'0');
		}
		i++; 
	}
	if(str[0]=='G')return n+ID;
	else return ID;
} 

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&DS);
	int u,v,w;
	char city1[5],city2[5];
	fill(G[0],G[0]+MAXV*MAXV,INF);
	for(int i=0;i<k;i++){
		scanf("%s %s %d",city1,city2,&w);
		u=getID(city1);
		v=getID(city2);
		G[u][v]=G[v][u]=w;//边权 
	} 
	//ansDis存放使最大的最短距离
	//ansAvg存放最小平均距离，ansID存放最终加油站ID
	double ansDis=-1,ansAvg=INF;
	int ansID=-1;
	for(int i=n+1;i<n+m;i++){//枚举所有加油站 
		double minDis=INF,avg=0;//minDis为最大的最近距离，avg为平均距离 
		Dijkstra(i);//求出d数组 
		for(int j=1;j<=n;j++){
			if(d[j]>DS){
				minDis=-1;
				break;
			}	
			if(d[j]<minDis) minDis=d[j];
			avg+=1.0*d[j]/n;
		} 
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansID=-1;
			ansDis=minDis;
			ansAvg=avg;
		} else if(minDis==ansDis&&avg<ansAvg){//更新平均最小距离
			ansID=i;
			ansAvg=avg; 
		}
	} 
	if(ansID==-1) printf("No Solution\n");
	else {
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
}

