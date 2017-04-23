#include<iostream>
#include<string>
#include<map>
using namespace std;
bool check(char c){//检查字符c是否是规定字符 
	if(c>='0'&&c<='9')return true;
	if(c>='A'&&c<='z')return true;
	if(c>='a'&&c<='z')return true;
	return false;
} 
int main(){
	map<string,int> count;//count计数字符串出现的次数
	string str;
	getline(cin,str);//都去整行字符串 
	int i=0;//单词下标 
	while(i<str.length()){//遍历整行字符串 
		string word;
		while(i<str.length()&&check(str[i])==true){//如果是单词字符的话 
			if(str[i]>='A'&&str[i]<='Z'){//如果是大写字母 
				str[i]+=32;//转化为小写字母 
			}
			word+=str[i];//单词末尾加上这个字符 
			i++; //下标后移一位 
		}
		if(word!=""){//如果单词非空，令次数加1 
			if(count.find(word)==count.end())count[word]=1;//以前没出现过这个单词，次数置为1 
			else count[word]++; //以前出现过这个单词，次数加1 
		}
		while(i<str.length()&&check(str[i])==false){//如果i位不是单词字符 
			i++;//跳过这一位 
		} 
	} 
	string ans;//答案：出现次数最多的单词
	int max=0;//出现次数最多的单词出现的次数 
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++) {
		if(it->second>max){//寻找出现次数最多的单词
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0; 
}
