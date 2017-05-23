//A1080
#include<cstdio>
#include<algorithm>
using namespace std;

struct Student{
	int GE,GI,sum;//���Գɼ������Գɼ����ɼ��ܺ�
	int r,stuID;//�������������
	int cho[6];//K��ѡ��ѧУ�ı�� 
}stu[40010];

struct School{
	int quota;//���������ܶ� 
	int stuNum;//��ǰʵ���������� 
	int id[40040];//���յ�ѧ����� 
	int lastAdmit;//��¼���һ������ѧ���ı�� 
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
	for(int i=0;i<m;i++){//��ʼ��ÿ��ѧУ 
		scanf("%d",&sch[i].quota);//�������������ܶ� 
		sch[i].stuNum=0;//��ǰʵ����������Ϊ0 
		sch[i].lastAdmit=-1;//���һ�����յ�ѧ�����Ϊ-1����ʾ������ 
	}
	for(int i=0;i<n;i++){//��ʼ��ÿ������ 
		stu[i].stuID=i;//�������Ϊi 
		scanf("%d%d",&stu[i].GE,&stu[i].GI);//���Գɼ������Գɼ� 
		stu[i].sum=stu[i].GE+stu[i].GI;//�ܳɼ� 
		for(int j=0;j<k;j++){
			scanf("%d",&stu[i].cho[j]);//K��������ѧУ��� 
		}
	} 
	sort(stu,stu+n,cmpStu);//��nΪ�������ɼ����� 
	for(int i=0;i<n;i++){//����ÿ������������ 
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
			stu[i].r=stu[i-1].r;
		} else {
			stu[i].r=i;
		}
	} 
	for(int i=0;i<n;i++){//��ÿλ����i���ж��䱻����ѧУ¼ȡ 
		for(int j=0;j<k;j++){//ö�ٿ���i��k��ѡ��ѧУ 
			int choice=stu[i].cho[j];//����i�ĵ�j��ѡ��ѧУ��� 
			int num=sch[choice].stuNum;//ѡ��ѧУ�ĵ�ǰ�������� 
			int last=sch[choice].lastAdmit;//ѡ��ѧУ�����һλ¼ȡѧ���ı�� 
			//�������δ�����ѧУ���һ��¼ȡ��ѧ���뵱ǰ�����ı����ͬ
			if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r)){
				sch[choice].id[num]=i;//¼ȡ�ÿ��� 
				sch[choice].lastAdmit=i;//��ѧУ�����һλ¼ȡ�Ŀ�����Ϊi 
				sch[choice].stuNum++;//��ǰ��������+1 
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
