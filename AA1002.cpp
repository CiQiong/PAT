//������������ʽ���������ǵĺ� 
#include<cstdio>
int main(){
	double ans[1001]={0};//�����洢�ͣ�����ֵΪ������ֵΪ��ϵ�� 
	int a,b,temp;//��������ʽ��ϵ���Լ���ʱ���� 
	double c;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%lf",&temp,&c);//������������Լ���Ӧ��ϵ�� 
		ans[temp]+=c;
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		scanf("%d%lf",&temp,&c);//������������Լ���Ӧ��ϵ�� 
		ans[temp]+=c;
	}
	int ans1=0;
	for(int i=0;i<1001;i++){
		if(ans[i]!=0)ans1++;
	}
	printf("%d",ans1);
	for(int i=1000;i>=0;i--){
		if(ans[i]!=0)printf(" %d %.1f",i,ans[i]);
	}
	return 0;
}
