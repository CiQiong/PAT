int A[maxn],n;

//��ѡ������
void selectSort(){
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=i;j<=n;j++){
			if(A[j]<A[k]){
				k=j;
			}
		}
		int temp=A[i];
		A[i]=A[k];
		A[k]=temp;
	}
} 

//ֱ�Ӳ�������
void insertSort(){
	for(int i=0;i<n;i++){
		int temp=A[i],j=i;
		while(j>1&&temp<A[j-1]){
			A[j]=A[j-1];
			j--;
		}
		A[j]=temp;
	}
}
