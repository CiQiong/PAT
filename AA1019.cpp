//������������һ������ʮ���ƣ��жϵ�һ�����ڵڶ������������ǲ��ǻ���
#include<cstdio>
bool Judge(int z[],int num){//�ж��Ƿ��ǻ���//���Ա��� 
	for(int i=0;i<=num/2;i++){
		if(z[i]!=z[num-1-i])return false;
	}
	return true;
} 
int main(){
	int n,b,z[40],num;
	scanf("%d%d",&n,&b);
	do{
		z[num++]=n%b;
		n/=b;
	}while(n!=0);//����ת��//���Ա��� 
	if(Judge(z,num))printf("Yes\n");
	else printf("No\n");
	for(int i=num-1;i>=0;i--){
		printf("%d",z[i]);
		if(i!=0)printf(" ");
	}
	return 0;
}
