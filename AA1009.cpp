//������������ʽ�ĳ˻� 
#include<cstdio>
int main(){
	int a,b,temp;//��������ʽ��ϵ���Լ���ʱָ�� 
	double c,aaa[1001]={0},ans[2001]={0};
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d %lf",&temp,&c);//�������ָ���Լ���Ӧ��ϵ�� 
		aaa[temp]=c;
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		scanf("%d %lf",&temp,&c);//�������ָ���Լ���Ӧ��ϵ�� 
		for(int ii=0;ii<1001;ii++)ans[ii+temp]+=aaa[ii]*c;//�ֱ������ǰÿһ�� 
	}
	int ans1=0;
	for(int i=0;i<2001;i++)if(ans[i]!=0)ans1++;
	printf("%d",ans1);
	for(int i=2000;i>=0;i--)if(ans[i]!=0)printf(" %d %.1f",i,ans[i]);
	return 0;
}
