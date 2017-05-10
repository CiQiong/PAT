#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

//326
bool isPowerOfThree00(int n) {
	if(n==0)return false;
	while(n%3==0)n/=3;
	return n==1;
}
//326
bool isPowerOfThree01(int n) {
	if(n<=0)return false;
	return 1162261467%n==0;
}
int main(){
	int n,k=1;
	cin>>n;
	for(int i=0;i<n;i++){
		k=k*2;
	}
	cout<<k;
	return 0;
}
