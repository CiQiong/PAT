#include<stdio.h>

void sort(int s[],int f[],int n)//�Ѹ��������ʼʱ��ͽ���ʱ�䰴����ʱ���������
{
    int a,b;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(f[i]>f[j])
            {a=f[i];f[i]=f[j];f[j]=a;
            b=s[i];s[i]=s[j];s[j]=b;}
        }
    }
}


int activemanage(int s[],int f[],bool a[],int n)
{
    a[0]=1;
    int i;
    int j=1,count=1;
    for(i=1;i<n;i++)
    {
        if(s[i]>=f[j])
        {
            a[i]=1;
            j=i;
            count++;
        }
        else a[i]=0;
    }
    return count;
}

int main()
{
    int i,n;
    int p;
    int s[100],f[100];
    bool a[100];
    printf("�����Ŀ����\n");
    scanf("%d",&n);
    printf("�����������Ŀ�Ŀ�ʼ�ͽ���ʱ��\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }
    sort(s,f,n);
    p=activemanage(s,f,a,n);
    printf("���ŵĽ�Ŀ����Ϊ:%d\n",p);
    printf("��Ŀ��ѡȡ���Ϊ(0��ʾ��ѡ 1��ʾѡȡ):\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
