#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
const int P=10000019;
vector<int> ans;
//�ַ���hash
long long hashFunc(string str){
	long long H=0;//ʹ��long long�������
	for(int i=0;i<str.length();i++){
		H=(H*P+str[i]-'a')%MOD;
	} 
	return H;
} 
int main(){
	string str;
	while(getline(cin,str),str!="#"){//һֱ����strֱ������#Ϊֹ 
		long long id=hashFunc(str);//���ַ���strת��Ϊ����
		ans.push_back(id); 
	}
	sort(ans.begin(),ans.end());//����
	int count=0;
	for(int i=0;i<ans.size();i++){
		if(i==0||ans[i]!=ans[i-1]){
			count++;//ͳ�Ʋ�ͬ�����ĸ��� 
		}
	} 
	cout<<count<<endl; 
}
