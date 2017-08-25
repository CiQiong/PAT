#include<iostream>
#include<stack>
using namespace std;
int main(){
	string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string a;
	cin>>a;
	int sum=0;
	for(int i=0;i<a.length();i++){
		sum+=(a[i]-'0');
	}
	stack<int> st;
	do{
		st.push(sum%10);
		sum/=10;
	}while(sum);
	cout<<s[st.top()];
	st.pop();
	while(!st.empty()){
		cout<<" "<<s[st.top()];
		st.pop();
	}
	return 0;
}
