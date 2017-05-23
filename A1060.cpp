#include<iostream>
#include<string>
using namespace std;
int n;//有效位数 
string deal(string s,int &e){
	int k=0;//s的下标 
	while(s.length()>0&&s[0]=='0'){
		s.erase(s.begin());//去掉s的前导零 
	}
	if(s[0]=='.'){//若去掉前导0后是小数点，则说明s是小于1的小数 
		s.erase(s.begin());//去掉小数点 
		while(s.length()>0&&s[0]=='0'){
			s.erase(s.begin());//去掉小数点后非零位前的所有0 
			e--;//每去掉一个0，指数e减1 
		}
	} else {//若去掉前导零后不是小数点，则找到后面的小数点删除 
		while(k<s.length()&&s[k]!='.'){//寻找小数点 
			k++;
			e++;//只要遇到的不是小数点，就让指数e++ 
		}
		if(k<s.length()){//while结束后k<s.length()，说明遇到了小数点 
			s.erase(s.begin()+k);//把小数点删除 
		}
	}
	if(s.length()==0){
		e=0;//如果去掉前导零后s的长度变为0，则说明这个数是0 
	}
	int num=0;
	k=0;
	string res;
	while(num<n){//只要精度还没有到n 
		if(k<s.length())res+=s[k++];//只要还有数字，就加到res末尾 
		else res+='0';//否则res末尾添加0 
		num++;//精度加1 
	}
	return res;
}

int main(){
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;//le1、le2分别是s1、s2的指数
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2){
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	} else {
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}
