#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int K=111;
const int INF=1000000000; 
struct Customer{
	int comeTime,serveTime;//客户到大的时间及服务时长 
}newCustomer;//newCustomer临时存放新客户的信息
vector<Customer> custom;//模拟队列
int convertTime(int h,int m,int s){
	return h*3600+m*60+s;//将时间转换为以秒为单位，方便比较和计算 
}
bool cmp(Customer a,Customer b){//按客户到达时间排序 
	return a.comeTime<b.comeTime;
} 
int endTime[K];//endTime[i]记录i号窗口的当前服务客户的结束时间
int main(){
	int c,w,totTime=0;//totTime记录总等待时长
	int stTime=convertTime(8,0,0);//开门时间
	int edTime=convertTime(17,0,0);//关门时间
	scanf("%d%d",&c,&w);//客户数，窗口数
	for(int i=0;i<w;i++){
		endTime[i]=stTime;//没有客户，初始化为stTime 
	}
	for(int i=0;i<c;i++){
		int h,m,s,serveTime;//时，分，秒，服务时长
		scanf("%d:%d:%d %d",&h,&m,&s,&serveTime);
		int comeTime=convertTime(h,m,s);//到达时间转换为以秒为单位
		if(comeTime>edTime) continue;//超过关门时间，不被计算
		newCustomer.comeTime=comeTime;
		newCustomer.serveTime=serveTime<=60?serveTime*60:3600;
		custom.push_back(newCustomer);//新客户加入 
	}
	sort(custom.begin(),custom.end(),cmp);//按到达时间排序
	for(int i=0;i<custom.size();i++){
		int idx=-1,minEndTime=INF;//选择当前最早服务结束的窗口
		for(int j=0;j<w;j++){
			if(endTime[j]<minEndTime){
				minEndTime=endTime[j];
				idx=j;
			}
		} 
		//idx为最早服务结束的编号，将客户custom[i]分配到该窗口
		if(endTime[idx]<=custom[i].comeTime){
			//如果客户custom[i]在窗口idx空闲之后才来，则直接接受服务
			endTime[idx]=custom[i].comeTime+custom[i].serveTime; 
		} else {//如果客户custom[i]来的太早，则需等待，等待时间计入totTime 
			totTime+=(endTime[idx]-custom[i].comeTime);
			endTime[idx]+=custom[i].serveTime;
		}
	} 
	if(custom.size()==0)printf("0.0");//没有在规定时间内的客户
	else printf("%.1f",totTime/60.0/custom.size());
	return 0;
} 

