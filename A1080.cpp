//A1080
#include<cstdio>
#include<algorithm>
using namespace std;

struct Student{
	int GE,GI,sum;//初试成绩、面试成绩、成绩总和
	int r,stuID;//排名，考生编号
	int cho[6];//K个选择学校的编号 
}stu[40010];

struct School{
	int quota;//招生人数总额 
	int stuNum;//当前实际招生人数 
	int id[40040];//招收的学生编号 
	int lastAdmit;//记录最后一个招收学生的编号 
}sch[110];

bool cmpStu(Student a,Student b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.GE>b.GE;
}
bool cmpID(int a,int b){
	return stu[a].stuID<stu[b].stuID;
}

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){//初始化每个学校 
		scanf("%d",&sch[i].quota);//输入招生人数总额 
		sch[i].stuNum=0;//当前实际招生人数为0 
		sch[i].lastAdmit=-1;//最后一个招收的学生编号为-1，表示不存在 
	}
	for(int i=0;i<n;i++){//初始化每个考生 
		stu[i].stuID=i;//考生编号为i 
		scanf("%d%d",&stu[i].GE,&stu[i].GI);//初试成绩、面试成绩 
		stu[i].sum=stu[i].GE+stu[i].GI;//总成绩 
		for(int j=0;j<k;j++){
			scanf("%d",&stu[i].cho[j]);//K个可申请学校编号 
		}
	} 
	sort(stu,stu+n,cmpStu);//给n为考生按成绩排序 
	for(int i=0;i<n;i++){//计算每个考生的排名 
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
			stu[i].r=stu[i-1].r;
		} else {
			stu[i].r=i;
		}
	} 
	for(int i=0;i<n;i++){//对每位考生i，判断其被哪所学校录取 
		for(int j=0;j<k;j++){//枚举考生i的k个选择学校 
			int choice=stu[i].cho[j];//考生i的第j个选择学校编号 
			int num=sch[choice].stuNum;//选择学校的当前招生人数 
			int last=sch[choice].lastAdmit;//选择学校的最后一位录取学生的编号 
			//如果人数未满或该学校最后一个录取的学生与当前考生的编号相同
			if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r)){
				sch[choice].id[num]=i;//录取该考生 
				sch[choice].lastAdmit=i;//该学校的最后一位录取的考生变为i 
				sch[choice].stuNum++;//当前招生人数+1 
				break;
			} 
		}
	}
	for(int i=0;i<m;i++){
		if(sch[i].stuNum>0){
			sort(sch[i].id,sch[i].id+sch[i].stuNum,cmpID);
			for(int j=0;j<sch[i].stuNum;j++){
				printf("%d",stu[sch[i].id[j]].stuID);
				if(j<sch[i].stuNum-1){
					printf(" ");
				}
			}
		}
		printf("\n");
	} 
	return 0;
} 
