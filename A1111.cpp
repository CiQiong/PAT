//A1111
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn=505;
int n,m;
int dis[maxn];
int distime[maxn];
int nums[maxn];
int pre[maxn];
int vis[maxn];
struct Edge{
    int w,time;
}edge[maxn][maxn];
struct disNode{
    int dis;  //统计距离
    int time; //统计时间
    int u;
    bool operator<(const disNode tmp)const{
        if(dis==tmp.dis)
            return time>tmp.time;
        else
            return dis>tmp.dis;
    }
};

struct timeNode{
    int time; //统计时间
    int nums; //统计路径的节点数
    int u;
    bool operator<(const timeNode tmp)const{
        if(time==tmp.time)
            return nums>tmp.nums;
        else
            return time>tmp.time;
    }
};
/*
求取最短路径，如果最短距离一样，取时间花费最小的
*/
void dijkstraDis(int s){
    int u;
    for(int i=0;i<n;i++){
        dis[i]=INF;
        vis[i]=0;
        pre[i]=-1;
    }
    priority_queue<disNode>q;
    disNode node;
    node.u=s;
    node.dis=dis[s]=0;
    node.time=dis[s]=0;
    q.push(node);
    while(!q.empty()){
        node=q.top();
        q.pop();
        u=node.u;
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v] && edge[u][v].w!=-1){
                //一开始都只判断了前一个，没判断后面一个。。。导致有个样例没过
                if((dis[u]+edge[u][v].w<dis[v])||(dis[u]+edge[u][v].w==dis[v] && distime[u]+edge[u][v].time<distime[v])){
                    dis[v]=dis[u]+edge[u][v].w;
                    distime[v]=distime[u]+edge[u][v].time;
                    node.dis=dis[v];
                    node.time=distime[v];
                    node.u=v;
                    pre[v]=u;
                    q.push(node);
                }
            }
        }
    }
}
/*
求取时间最小的，如果时间一样，取路径节点数最小的。
*/
void dijkstraTime(int s){
    int u;
    for(int i=0;i<n;i++){
        distime[i]=INF;
        vis[i]=0;
        pre[i]=-1;
        nums[i]=1;
    }
    priority_queue<timeNode>q;
    timeNode node;
    node.u=s;
    node.time=distime[s]=0;
    node.nums=nums[s]=1;
    q.push(node);
    while(!q.empty()){
        node=q.top();
        q.pop();
        u=node.u;
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v] && edge[u][v].w!=-1){
                if((distime[u]+edge[u][v].time<distime[v])||(distime[u]+edge[u][v].time==distime[v] && nums[u]+1<nums[v])){
                    distime[v]=distime[u]+edge[u][v].time;
                    nums[v]=nums[u]+1;
                    node.time=distime[v];
                    node.nums=nums[v];
                    node.u=v;
                    pre[v]=u;
                    q.push(node);
                }
            }
        }
    }
}

int main()
{
    int v1,v2,a,b,c;
    int s,t;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edge[i][j].w=-1;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d %d",&v1,&v2,&a,&b,&c);
        edge[v1][v2].w=b;
        edge[v1][v2].time=c;
        if(a==0){
            edge[v2][v1].w=b;
            edge[v2][v1].time=c;
        }
    }
    scanf("%d %d",&s,&t);
    dijkstraDis(s);
    int disAns=dis[t];
    int disPath[n+5];
    int disCnt=0;
    //最短路径
    int u=t;
    disPath[disCnt]=u;
    disCnt++;
    while(pre[u]!=-1){
        disPath[disCnt]=pre[u];
        u=pre[u];
        disCnt++;
    }

    dijkstraTime(s);
    int timeAns=distime[t];
    int timePath[n+5];
    int timeCnt=0;
    //最短时间路径
    u=t;
    timePath[timeCnt]=u;
    timeCnt++;
    while(pre[u]!=-1){
        timePath[timeCnt]=pre[u];
        u=pre[u];
        timeCnt++;
    }

    bool isSame=true;
    if(disCnt==timeCnt){
        for(int i=0;i<disCnt;i++){
            if(disPath[i]!=timePath[i]){
                isSame=false;
                break;
            }
        }
    }
    else
        isSame=false;

    if(isSame){
        printf("Distance = %d; Time = %d: %d",disAns,timeAns,s);
        for(int i=disCnt-2;i>=0;i--){
            printf(" -> %d",disPath[i]);
        }
    }
    else{
        printf("Distance = %d: %d",disAns,s);
        for(int i=disCnt-2;i>=0;i--){
            printf(" -> %d",disPath[i]);
        }
        printf("\n");
        printf("Time = %d: %d",timeAns,s);
        for(int i=timeCnt-2;i>=0;i--){
            printf(" -> %d",timePath[i]);
        }
    }

    return 0;
}
