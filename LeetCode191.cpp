#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int hammingWeight(uint32_t n) {
	int count=0;
	while(n){
		count+=n&1;
		n=n>>1;
	}
	return count;
}

int hammingWeight2(uint32_t n) {
	int count=0;
	while(n){
		if(n%2==1)count++;
		n/=2;
	}
	return count;
}

int hammingWeight3(uint32_t n) {
	int count=0;
	while(n){
		n&=n-1;
		count++;
	}
	return count;
}
int main(){
	
	return 0;
} 
