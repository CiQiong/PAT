//���͵��Ķ������
//��Ŀ����;
//��������double����ÿ������������ÿ���������ֱ�Ϊa��b��c 
//�ֱ����ÿ�����������ڵ�λ��(W/T/L)��Ȼ�����ù�ʽans=(a*b*c*0.65-1)*2�����
#include<cstdio>
int main(){
	char s[4]={"WTL"};
	double ans=1.0,max,a;
	int index;
	for(int i=0;i<3;i++){
		max=0.0;
		for(int j=0;j<3;j++){
			scanf("%lf",&a);
			if(a>max){
				max=a;
				index=j;
			}
		}
		ans*=max;
		printf("%c ",s[index]);
	}
	printf("%.2f",(ans*0.65-1)*2);
	return 0;
} 
