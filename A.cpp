#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		vector<int> N(n);
		bool result=true;
		for(int j=0;j<n;j++){
			cin>>N[j];         
			for(int l=0;l<j;l++){
				if(N[l]==N[j]||abs(N[j]-N[l])==abs(j-l))result=false;
			}
		}
		cout<<(result==true?"YES\n":"NO\n");
	}
	return 0;
}
