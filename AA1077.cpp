//
#include<iostream>
using namespace std;
int main(){
	int n,minlen=260;
	cin>>n;
	string ans, s;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,s);
		int len=s.length();
		for(int j=0;j<len/2;j++)swap(s[j],s[len-1-j]);
		if(i==0)ans=s;
		else{
			if(len<minlen)minlen=len;
			for(int j=0;j<minlen;j++){
				if(ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
			}
		}
	}
	if(ans.length()==0)cout<<"nai";
	else for(int i=ans.length()-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
