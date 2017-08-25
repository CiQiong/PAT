#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string> v;
	for(int j=0;j<n;j++){
		string name,pass;
		cin>>name>>pass;
		int flag = 0;
		for(int i=0;i<pass.length();i++){
			switch(pass[i]) {
                case '1' : pass[i] = '@'; flag = 1; break;
                case '0' : pass[i] = '%'; flag = 1; break;
                case 'l' : pass[i] = 'L'; flag = 1; break;
                case 'O' : pass[i] = 'o'; flag = 1; break;
            }
		}
		if(flag) {
            string temp = name + " " + pass;
            v.push_back(temp);
        }
	}
	int num=v.size();
	if (num!=0){
		cout<<num<<endl;
		for(int i=0;i<num;i++)cout<<v[i]<<endl;
	} else if(n==1)cout<<"There is 1 account and no account is modified";
	else cout<<"There are "<<n<<" accounts and no account is modified";
	return 0;
}
