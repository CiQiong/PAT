//�����������Ⱦ�������1000���ַ����������ǵ�������Ӵ��ĳ���
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;//MODΪ����hashʱ��ģ��
const LL p=10000019;//PΪ����hashʱ�Ľ�����
const LL MAXN=1010;//MAXNΪ�ַ��������
//powP[MAXN]���P^i%MOD,H1��H2�ֱ���str1��str2��hashֵ
LL powP[MAXN],H1[MAXN]={0},H2[MAXN]={0};
//pr1���str1������<�Ӵ�hashֵ���ִ�����>��pr2ͬ��
vector<pair<int, int>> pr1,pr2;
//pair��һ��ģ�����͡�ÿ��pair���Դ������ֵ��������ֵ�����������ơ�Ҳ�����Լ�дstruct����Ž�ȥ
//init������ʼ��powP����
void init(int len){
	powP[0]=1;
	for(int i=1;i<=len;i++){
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
//calSingLeSubH����H[i...j]
int calSingLeSubH(LL H[],int i,int j){
	if(i==0)return H[j];//H[0...j]��������
	return ((H[j]-H[i-1]*powP[j-i+1])%MOD+MOD)%MOD; 
} 
//calSubH���������Ӵ���hashֵ������<�Ӵ�hashֵ���Ӵ�����>����pr
void calSubH(LL H[],int len,vector<pair<int, int>>&pr){
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			int hashValue=calSingLeSubH(H,i,j);
			pr.push_back(make_pair(hashValue,j-i+i));/////////////??????????
		}
	}
} 
//����pr1��pr2����ͬ��hashֵ��ά����󳤶�
int getMax(){
	int ans=0;
	for(int i=0;i<pr1.size();i++){
		for(int j=0;j<pr2.size();j++){
			if(pr1[i].first==pr2.first){
				ans=max(ans,pr1[i].second);
			}
		}
	}
	return ans;
}
int main(){
	string
}
