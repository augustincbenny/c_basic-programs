#include<stdio.h>
int main()
{
	int a[100][100],b[100][100],s[100][100],m,n,i,j;
	printf("enter the no of rows:");
	scanf("%d",&m);
	printf("enter the no of columns:");
	scanf("%d",&n);
    printf("enter the elements for the first matrix\n");
    for(i=0;i<m;i++)
    {
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("enter the elements for the second matrix\n");
    for(i=0;i<m;i++)
    {
		for(j=0;j<n;j++)
		scanf("%d",&b[i][j]);
	}
	printf("the sub=\n");
	for(i=0;i<m;i++)
    {
		for(j=0;j<n;j++)
		{
			s[i][j]=a[i][j]-b[i][j];
			printf("%3d",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
