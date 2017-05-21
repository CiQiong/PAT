//A1098
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=111;
int origin[N],tempOri[N],changed[N];//原始数组、原始数组备份、目标数组
int n;//元素个数
bool isSame(int A[],int B[]){//判断数组A和数组B是否相同 
	for(int i=1;i<=n;i++){
		if(A[i]!=B[i]) return false;
	}
	return true; 
} 

void showArray(int A[]){
	for(int i=1;i<=n;i++){
		printf("%d",A[i]);
		if(i<n) printf(" ");
	}
	printf("\n");
}

bool insertSort(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(i!=2&&isSame(tempOri,changed)){
			flag=true;//中间步骤与目标相同，且不是初始序列 
		}
		//插入部分直接用sort代替
		sort(tempOri,tempOri+i+1);
		if(flag==true){
			return true;//flag==true说明已经到达目标数组，返回true 
		} 
	}
	return false;//无法到达目标数组返回false 
}

void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&tempOri[j+1]>tempOri[j]){
			j=j+1;
		}
		
		if(tempOri[j]>tempOri[i]){
			swap(tempOri[j],tempOri[i]);
			i=j;
			j=i*2;
		} else {
			break;
		}
	}
}

void heapSort(){//堆排序 
	bool flag=false;
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);//建堆 
	}
	for(int i=n;i>1;i--){
		if(i!=n&&isSame(tempOri,changed)){
			flag=true;
		}
		swap(tempOri[i],tempOri[i]);
		downAdjust(1,i-1);
		if(flag==true){
			showArray(tempOri);
			return;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&origin[i]);
		tempOri[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&changed[i]);//目标数组 
	}
	if(insertSort()){
		printf("Tnseration Sort\n");
		showArray(tempOri);
	} else {
		printf("Heap Sort\n");
		for(int i=1;i<=n;i++){
			tempOri[i]=origin[i];
		}
		heapSort();
	}
	return 0;
}
