#include<stdio.h>
int main()
{
	int a[100][100],trans[100][100],m,n,i,j;
	printf("enter the no of rows:");
	scanf("%d",&m);
	printf("enter the no of columns:");
	scanf("%d",&n);
    printf("enter the elements the matrix\n");
    for(i=0;i<m;i++)
    {
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("the transpose of the matrix =:\n");
    for(i=0;i<m;i++)
    {
		for(j=0;j<n;j++)
		trans[j][i]=a[i][j];
	}
	for(i=0;i<n;i++)
    {
		for(j=0;j<m;j++)
		printf("%3d",trans[i][j]);
		printf("\n");
	}
	return 0;
}
