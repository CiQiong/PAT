#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int toll[25];//资费
struct Record{
	char name[25];//姓名
	int month,dd,hh,mm;//月，日，时，分
	bool status;//true表示记录为on-line，否则为off-line 
}rec[maxn],temp;
bool cmp(Record a,Record b){
	int s=strcmp(a.name,b.name);
	if(s!=0)return s<0;//优先按姓名字典序从小到大排序 
	else if(a.month!=b.month) return a.month<b.month;
	else if(a.dd!=b.dd) return a.dd<b.dd;
	else if(a.hh!=b.hh) return a.hh<b.hh;
	else return a.mm<b.mm;
} 

void get_ans(int on,int off,int &time,int &money){
	temp=rec[on];
	while(temp.dd<rec[off].dd||temp.hh<rec[off].hh||temp.mm<rec[off].mm){
		time++;//该记录总时间加1min
		money+=toll[temp.hh];//花费增加
		temp.mm++;//当前时间加1min
		if(temp.mm>=60){
			temp.mm=0;//进入下一个小时 
			temp.hh++;
		} 
		if(temp.hh>=24){
			temp.hh=0;//进入下一天 
			temp.dd++;
		}
	}
}

int main(){
	for(int i=0;i<24;i++){
		scanf("%d",&toll[i]);//资费 
	}
	int n;
	scanf("%d",&n);//记录数
	char line[10];//临时存放on-line/off-line的输入
	for(int i=0;i<n;i++){
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
		scanf("%s",line);
		if(strcmp(line,"on-line")==0){
			rec[i].status=true;
		} else {
			rec[i].status=false;
		}
	} 
	sort(rec,rec+n,cmp);//排序
	int on=0,off,next;
	while(on<n){//每次循环处理单个用户的所有记录
		int needPrint=0;
		next=on;//从当前位置开始寻找下一个用户
		while(next<n&&strcmp(rec[next].name,rec[on].name)==0){
			if(needPrint==0&&rec[next].status==true){
				needPrint=1;
			} else if(needPrint==1&&rec[next].status==false){
				needPrint=2;
			}
			next++;
		} 
		if(needPrint<2){
			on=next;
			continue;
		}
		int AllMoney=0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next){
			while(on<next-1&&!(rec[on+1].status==false)){
				on++;
			}
			off=on+1;
			if(off==next){
				on=next;
				break;
			}
			printf("%02d:%02d:%02d",rec[on].dd,rec[on].hh,rec[on].mm);
			printf("%02d:%02d:%02d",rec[off].dd,rec[off].hh,rec[off].mm);
			int time=0,money=0;
			get_ans(on,off,time,money);
			AllMoney+=money;
			printf("%d $%.2f\n",time,money/100.0);
			on=off+1;
		}
		printf("Total amount: $%.2f\n",AllMoney/100.0); 
	} 
	return 0;
}
