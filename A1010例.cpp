#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL Map[256];//0~9��a~z��0~35�Ķ�Ӧ 
LL inf=(1LL<<63)-1;//long long�����ֵ2^63-1,ע������� 
void init(){//����ӳ���ϵ 
	for(char c='0';c<='9';c++){
		Map[c]=c-'0';//��'0'~'9'ӳ�䵽0~9 
	}
	for(char c='a';c<='z';c++){
		Map[c]=c-'a'+10;//'a'~'z'ӳ�䵽10~35 
	}
} 
LL convertNum10(char a[],LL radix,LL t){//��aת��Ϊʮ���ƣ�tΪ�Ͻ� 
	LL ans=0;
	int len=strlen(a);
	for(int i=0;i<len;i++){
		ans=ans*radix+Map[a[i]];//����ת�� 
		if(ans<0||ans>t)return -1;//����򳬹�N1��ʮ���� 
	} 
	return ans; 
}
int cmp(char N2[],LL radix,LL t){//N2��ʮ������t�Ƚ� 
	int len=strlen(N2);
	LL num=convertNum10(N2,radix,t);//��N2ת��Ϊʮ����
	if(num<0)return 1;//������϶���N2����t 
	if(t>num)return -1;//t�ϴ󣬷���-1 
	else if(t==num) return 0;//��ȣ�����0 
	else return 1;//num�ϴ󣬷���1�� 
}
LL binarySearch(char N2[],LL left,LL right,LL t){//2�����N2�Ľ��� 
	LL mid;
	while(left<=right){
		mid=(left+right)/2;
		int flag=cmp(N2,mid,t);//�ж�N2ת��Ϊʮ���ƺ���t�Ƚ� 
		if(flag==0)return mid;//�ҵ��⣬����mid 
		else if(flag==-1)left=mid+1;//��������������� 
		else right=mid-1;//��������������� 
	} 
	return -1;//�ⲻ���� 
} 
int findLargestDigit(char N2[]){//��������λ 
	int ans=-1,len=strlen(N2);
	for(int i=0;i<len;i++){
		if(Map[N2[i]]>ans){
			ans=Map[N2[i]];
		}
	}
	return ans+1;//������λΪans��˵���������ĵ�����ans+1; 
} 
char N1[20],N2[20],temp[20];
int tag,radix;
int main(){
	init();
	scanf("%s%s%d%d",N1,N2,&tag,&radix);
	if(tag==2){//�����Ա�֤�Ժ��һ���� 
		strcpy(temp,N1);
		strcpy(N1,N2); 
		strcpy(N2,temp);
	}
	LL t=convertNum10(N1,radix,inf);//��N1��radix����ת��Ϊʮ���� 
	LL low=findLargestDigit(N2);//�ҵ�N2������λ��1�����ɶ����½� 
	LL high=max(low,t)+1;//�Ͻ� 
	LL ans=binarySearch(N2,low,high,t);//����
	if(ans==-1)printf("Impossible\n");
	else printf("%lld\n",ans);
	return 0; 
}
