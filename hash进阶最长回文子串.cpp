//������Ӵ�
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;//MODΪ����hashֵʱ��ģ��
const LL P=10000019;//PΪ����hashʱ�Ľ�����
const LL MAXN=200010;//MAXNΪ�ַ�������󳤶�
//powP[i]���P^i%MOD,H1��H2�ֱ���str��rstr��hashֵ
LL powP[MAXN],H1[MAXN],H2[MAXN];
//init������ʼ��powP����
void init(){
	powP[0]=1;
	for(int i=1;i<MAXN;i++){
		powP[i]=(powP[i-1]*P)%MOD;
	}
} 
//calH���������ַ���str��hashֵ
void calH(LL H[],string &str){
	H[0]=str[0];//H[0]��������
	for(int i=1;i<str.length();i++){
		H[i]=(H[i-1]*P+str[i])%MOD;
	} 
} 
//calSingleSubH����H[i...j]
int calSingleSubH(LL H[],int i,int j){
	if(i==0)return H[j];//H[0...j]��������
	return ((H[j]-H[i-1]*powP[j-i+1])%MOD+MOD)%MOD;//ȡ�����ָ����Ŀ��� 
} 
//�ԳƵ�Ϊi���ַ�����len����[l,r]����ֻ��İ뾶
//Ѱ�����һ������������hashL==hashR���Ļ��İ뾶
//�ȼ���Ѱ�ҵ�һ������������hashL!=hashR���Ļ��İ뾶��Ȼ���1����
//isEven������������ʱΪ0������ż����ʱΪ1
int binarySearch(int l,int r,int len,int i,int isEven){
	while(l<r){//������1==rʱ����(��Ϊ��Χ��[l.r])
		int mid=(l+r)/2;
		//����Ӵ�hashֵH1[H1L...H1R],�Ұ��Ӵ�hashֵH2[H2L...H2R]
		int H1L=i-mid+isEven,H1R=i;
		int H2L=len-1-(i+mid),H2R=len-1-(i+isEven);
		int hashL=calSingleSubH(H1,H1L,H1R);
		int hashR=calSingleSubH(H2,H2L,H2R);
		if(hashL!=hashR)r=mid;//hashֵ���ȣ�˵�����İ뾶<=mid
		else l=mid+1;//hashֵ��ȣ�˵�����İ뾶>mid	
	}
	return l-1;//���������İ뾶 
} 
int main(){
	init();
	string str;
	getline(cin,str);
	calH(H1,str);//����str��hash���� 
	reverse(str.begin(),str.end());//���ַ�����ת
	calH(H2,str);//����rstr��hash����
	int ans=0;
	//�����
	for(int i=0;i<str.length();i++){
		//�����Ͻ�Ϊ�ֽ��i�����ҳ��ȵ���Сֵ��1
		int maxLen=min(i,(int)str.length()-1-i)+1;
		int k=binarySearch(0,maxLen,str.length(),i,0);
		ans=max(ans,k*2+1); 
	} 
	//ż����
	for(int i=0;i<str.length();i++){
		//�����Ͻ�Ϊ�ֽ��i�����ҳ��ȵĽ�Сֵ��1(ע����Ϊi+1)
		int maxLen=min(i+1,(int)str.length()-1-i)+1;
		int k=binarySearch(0,maxLen,str.length(),i,1);
		ans=max(ans,k*2); 
	} 
	printf("%d\n",ans);
	return 0;
}
