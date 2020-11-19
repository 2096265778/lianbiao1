#include <stdio.h>
#define N 50

int main ()
{
	int a[N],m,n,x,i,count =0;

	printf("Please input two integers:\n");
	scanf("%d%d",&n,&m);
	x=n;
	for(i=1;i<=n;i++){
		a[i]=i;
	}
	do{
		for(i=1;i<=n;i++){
			a[i]=i;
		}

		do{
			for(i=1;i<=n;i++){
				if(a[i] !=0){
					count++;
				}

				if(count ==m){
					a[i]=0;
					count=0;
					x--;
					printf("%d",i);
				}
			}
		}while(x>0);

		return 0;
	}
}
