#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	for(int i=1;i<nums.size();i++){
		if(nums[i]==numa[i-1]){
			return true;
		}
	}
	return false;
}

int romanToInt(string s) {
    int len=s.length();
     
}
string addStrings(string num1, string num2) {
	string c="";
    int a=num1.length();
    int b=num2.length();
    long carry=0;
    for(int i=0;i<=a||i<=b;i++){
    	long temp=(num1[i]-'0')+(num2[i]-'0')+carry;
    	carry=temp/10;
    	temp=temp%10;
    	c=to_string(temp)+c;
	}
	if(carry!=0){//如果最后的进位不为0，则直接赋给结果的最高位 
		c=to_string(carry)+c;
	}
	return c;
}
int sums(int n){
	int sum=0;
	while(n!=0){
		int temp=n%10;
		sum+=temp*temp;
		n/=10;
	}
	return sum;
}
bool isHappy(int n) {
	if(n==0)return false;
	int a,b;
	a=b=n;
	do{
		a=sums(a);
		b=sums(b);
		b=sums(b);
	}while(a!=b);
	if(a==1)return true;
	else return false;
}
bool isUgly(int num) {
	if(num==0)return false;
	while(num%2==0){
		num/=2;
	}
	while(num%3==0){
		num/=3;
	}
	while(num%3==0){
		num/=3;
	}
	return num==1;
}
bool isUgly(int num){
	if(num>0){
		for(int i=2;i<6;i++){
			while(num%i==0){
				num/=i;
			}
		}
	}
	return num==1;
}

int main(){
	
} 
