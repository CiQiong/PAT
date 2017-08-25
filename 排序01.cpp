
#include<iostream>
using namespace std;
//int A[maxn],n;

//ºÚµ•—°‘Ò≈≈–Ú£∫
void selectSort(){
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(A[j]<A[i])swap(A[i],A[j]);
		}
	}
} 



int main(){
	int n=6;
	int A[6]={6,5,1,3,2,4};
	
	for(int i=1;i<n;i++){
		cout<<A[i];
	}
	return 0;
}
