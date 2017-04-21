#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,p,a[maxn];
int binarySearch(int i,long long x){//�ҵ�iλ������Ӧ����λ�� a[i]*p>=x 
	if(a[n-1]<=x)return n;//���������ҲС��x���ͷ���n
	int l=i+1,r=n-1,mid;//���ַ���ߵ������ұߵ������м����
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]<=x){
			l=mid+1;
		}else {
			r=mid;
		}
	} 
	return l;//����ʱl==r����˷���l��r������
	 
} 
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=1;//��󳤶ȣ���ֵΪ1(��ʾ������һ����) 
	for(int i=0;i<n;i++){
		int j=binarySearch(i,(long long)a[i]*p);
		//int j=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;
		//�����һ�䣬����upper_bound��õ�һ����������Ԫ�ص�Ԫ�ص�λ�� 
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);
	return 0; 
}
