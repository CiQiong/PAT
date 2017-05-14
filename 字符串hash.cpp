//输入两个长度均不超过1000的字符串，求他们的最长公共子串的长度
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;//MOD为计算hash时的模数
const LL p=10000019;//P为计算hash时的进制数
const LL MAXN=1010;//MAXN为字符串最长长度
//powP[MAXN]存放P^i%MOD,H1和H2分别存放str1和str2的hash值
LL powP[MAXN],H1[MAXN]={0},H2[MAXN]={0};
//pr1存放str1的所有<子串hash值，字串长度>，pr2同理
vector<pair<int, int>> pr1,pr2;
//pair是一种模板类型。每个pair可以存放两个值，这两个值的类型无限制。也可以自己写struct对象放进去
//init函数初始化powP函数
void init(int len){
	powP[0]=1;
	for(int i=1;i<=len;i++){
		powP[i]=(powP[i-1]*P)%MOD;
	}
} 
//calH函数计算字符串str的hash值
void calH(LL H[],string &str){
	H[0]=str[0];//H[0]单独处理
	for(int i=1;i<str.length();i++){
		H[i]=(H[i-1]*P+str[i])%MOD;
	} 
} 
//calSingLeSubH计算H[i...j]
int calSingLeSubH(LL H[],int i,int j){
	if(i==0)return H[j];//H[0...j]单独处理
	return ((H[j]-H[i-1]*powP[j-i+1])%MOD+MOD)%MOD; 
} 
//calSubH计算所有子串的hash值，并将<子串hash值，子串长度>存入pr
void calSubH(LL H[],int len,vector<pair<int, int>>&pr){
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			int hashValue=calSingLeSubH(H,i,j);
			pr.push_back(make_pair(hashValue,j-i+i));/////////////??????????
		}
	}
} 
//计算pr1和pr2中相同的hash值，维护最大长度
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
