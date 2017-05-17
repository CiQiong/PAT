//A1014
#include<cstdio>
#include<queue>
#include<algorithm>//min(,)
using namespace std;
const int maxNode=1111;
int n,m,k,query,q;
int convertToMinute(int h,int m){
	return h*60+m;//将时间单位转换为min，方便事件处理 
}
struct Window{
	int endTime,popTime;
	queue<int> q; 
}window[20];
int ans[maxNode],needTime[maxNode];//服务结束时间和服务需要时间
int main(){
	int inIndex=0;//当前第一个未入队的客户编号
	scanf("%d%d%d%d",&n,&m,&k,&query);
	for(int i=0;i<k;i++){
		scanf("%d",&needTime[i]);//读入服务需要时间 
	}
	for(int i=0;i<n;i++){
		window[i].popTime=window[i].endTime=convertToMinute(8,0);
	}
	for(int i=0;i<min(n*m,k);i++){
		//循环入队
		window[inIndex%n].q.push(inIndex);
		//更新窗口的服务结束时间endTime
		window[inIndex%n].endTime+=needTime[inIndex];
		//对窗口第一个用户，更新popTime
		if(inIndex<n) window[inIndex].popTime=needTime[inIndex];
		//当前入队的客户服务时间直接保存作为答案（不会再修改）
		ans[inIndex]=window[inIndex%n].endTime;
		inIndex++; 
	}
	for(;inIndex<k;inIndex++){//处理剩余客户的入队 
		int idx=-1,minPopTime=1<<30;//寻找所有窗口的最小popTime
		for(int i=0;i<n;i++){
			if(window[i].popTime<minPopTime){
				idx=i;
				minPopTime=window[i].popTime;
			}
		} 
		//找到最小的popTime的窗口编号为idx，下面更新该窗口的队列情况
		//引用，下文中用W代替window[idx]，行文更清晰
		Window& W=window[idx];
		W.q.pop();//队首客户离开
		W.q.push(inIndex);//客户inIndex入队
		W.endTime+=needTime[inIndex];//更新该窗口队列的endTime
		W.popTime+=needTime[W.q.front()];//更新该窗口的popTime
		//客户inIndex的服务结束时间为该窗口的endTime
		ans[inIndex]=W.endTime; 
	}
	for(int i=0;i<query;i++){
		scanf("%d",&q);
		if(ans[q-1]=needTime[q-1]>=convertToMinute(17,0)){
			printf("Sorry\n");//服务开始时间达到17:00，输出Sorry 
		} else {
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
	}
	return 0;
} 
