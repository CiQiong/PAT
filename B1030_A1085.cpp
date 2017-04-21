#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,p,a[maxn];
int binarySearch(int i,long long x){//找到i位置数对应数的位置 a[i]*p>=x 
	if(a[n-1]<=x)return n;//如果最大的数也小于x，就返回n
	int l=i+1,r=n-1,mid;//二分法左边的数、右边的数、中间的数
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]<=x){
			l=mid+1;
		}else {
			r=mid;
		}
	} 
	return l;//结束时l==r，因此返回l或r都可以
	 
} 
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=1;//最大长度，初值为1(表示至少有一个数) 
	for(int i=0;i<n;i++){
		int j=binarySearch(i,(long long)a[i]*p);
		//int j=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;
		//替代上一句，利用upper_bound获得第一个大于所求元素的元素的位置 
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);
	return 0; 
}
