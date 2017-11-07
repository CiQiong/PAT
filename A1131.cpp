#include <cstdio>
#include <vector>
using namespace std;
const int maxv=10000;
int arc[maxv][maxv];//储存在哪条地铁线上
int minscnt=0x7fffffff,mintrans=0x7fffffff;//最小的经站和最小换乘
int lastline=0,transfercnt=0;//上一条地铁线，
vector<int> v[maxv];//邻接表
vector<int> ans,line;//ans保存结果路径,line保存当前路径
void dfs(const int s,const int e,int vis[],int stationcnt,int transfercnt,int lastline)
{
    vis[s]=1;
    line.push_back(s);//保存当前路径
    if(s==e)//找到终点
    {
        if(stationcnt<minscnt||(stationcnt==minscnt&&transfercnt<mintrans))
        {
            minscnt=stationcnt;
            mintrans=transfercnt;
            ans.clear();
            ans=line;
        }
    }
    for(auto it=v[s].begin();it!=v[s].end();++it)
    {
        if(!vis[*it])//判断transfercnt
        {
            lastline==0?dfs(*it,e,vis,stationcnt+1,1,arc[s][*it]):
            lastline==arc[s][*it]?
            dfs(*it,e,vis,stationcnt+1,transfercnt,arc[s][*it]):
            dfs(*it,e,vis,stationcnt+1,transfercnt+1,arc[s][*it]);
        }
    }
    vis[line.back()]=0;//回置0
    line.pop_back();//扔掉它
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int m,u,w;
        scanf("%d %d",&m,&u);
        for(int j=2;j<=m;++j)
        {
            scanf("%d",&w);
            arc[u][w]=arc[w][u]=i;//储存line
            v[u].push_back(w);//邻接表
            v[w].push_back(u);
            u=w;
        }
    }
    scanf("%d",&k);
    while(k--)
    {
        int s,e;
        scanf("%d %d",&s,&e);//接下来5行进行每次初始化
        int vis[maxv]={0};
        minscnt=0x7fffffff;
        mintrans=0x7fffffff;
        line.clear();
        ans.clear();
        dfs(s,e,vis,1,1,0);
        printf("%d\n",ans.size()-1);
        auto it=ans.begin(),p=it+1;
        int last=arc[*it][*p];
        while(true)//按要求打印
        {
            while(p!=ans.end()&&arc[*(p-1)][*p]==last)++p;
            printf("Take Line#%d from %04d to %04d.\n",last,*it,*(p-1));
            if(p==ans.end())break;
            it=p-1;
            last=arc[*it][*p];
        }
    }
    return 0;
}

/*
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
int line[10000][10000], visit[10000];
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}
void dfs(int node, int end, int cnt, int &minCnt, int &minTransfer) {
    if (node == end && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], end, cnt + 1, minCnt, minTransfer);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre][temp] = line[temp][pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        int minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(a);
        visit[a] = 1;
        dfs(a, b, 0, minCnt, minTransfer);
        visit[a] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = a;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, b);
    }
    return 0;
}
*/
