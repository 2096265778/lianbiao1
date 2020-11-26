
#include<stdio.h>
#include<stdlib.h>
 
#define SWAMP(a,b)    (a)+=(b),(b)=(a)-(b),(a)-=(b)
 
void SwampTwoInt(int *a,int *b)
{
	    int temp=*a;
	        *a=*b;
		    *b=temp;
}
 
 
void ChooseSort(int a[],unsigned short Num)
{
	    unsigned short i=0,j=0,MinIndex=0;
	        int Temp;
		 
			printf("\r\nChooseSort\r\n");
				printf("raw data:\r\n");
					for(i=0;i<Num;++i){
								printf("%d ",a[i]);
									}
						printf("\r\n");
						 
						 
							for(i=0;i<Num;++i){
										MinIndex=i;
												for(j=i+1;j<Num;++j){
																if(a[j]<a[MinIndex]){
																					MinIndex=j;
																								}
																		}
														if(MinIndex!=i){
																		SWAMP(a[MinIndex],a[i]);
																				}
															}
								
								printf("sorted data:\r\n");
									for(i=0;i<Num;++i){
												printf("%d ",a[i]);
													}
										printf("\r\n\r\n");
}
 
 
void InsertSort(int a[],unsigned short Num)
{
		int temp;
			unsigned short i=0,j=0;
				
				printf("\r\nInsertSort\r\n");
					printf("raw data:\r\n");
						for(i=0;i<Num;++i){
									printf("%d ",a[i]);
										}
							printf("\r\n");
							 
								for(i=1;i<Num;++i){ //外循环遍历数组，i从1到Num
									 
											for(j=i;j>0;--j){ //j从i到0，j和j-1两两比较
															if(a[j]<a[j-1]){ //如果后一个比前一个小，交换。
																				SWAMP(a[j],a[j-1]);
																							}
																	}
												}
								 
									printf("sorted data:\r\n");
										for(i=0;i<Num;++i){
													printf("%d ",a[i]);
														}
											printf("\r\n\r\n");
}
 
 
 
 
void TestSwamp(void)
{
		int a=1,b=2;
		 
			printf("a=%d, b=%d\r\n",a,b);
				SWAMP(a,b);
					
					printf("after SWAMP(a,b); a==%d,b==%d\r\n",a,b);
					 
					 
						SwampTwoInt(&a,&b);
							printf("after SwampTwoInt(&a,&b); a==%d,b==%d\r\n",a,b);
								printf("\r\n");
}
 
 
int main(void)
{
		int a[]={4,6,1,3,2,  8,9,7,5,6,  2,4,5,1,2};
			TestSwamp();
			 
			 
				InsertSort(a, sizeof(a)/sizeof(a[0])  );
				 
				 
					ChooseSort(a, sizeof(a)/sizeof(a[0])  );
						
						system("pause");
							
							return 0;
}

