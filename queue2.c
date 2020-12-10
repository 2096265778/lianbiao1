#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	    int data;
	        struct Node * next;
} NODE, *PNODE;
typedef struct Queue
{
	    PNODE pFront;
	        PNODE pTail;
} QUEUE, *PQUEUE;
void init(PQUEUE pQueue);
void show(PQUEUE pQueue);
int isEmpty(PQUEUE pQueue);
void enQueue(PQUEUE pQueue, int val);
void deQueue(PQUEUE pQueue, int *val);
void init(PQUEUE pQ)
{
	    pQ->pFront = (PNODE)malloc(sizeof(NODE));
	        if (NULL == pQ->pFront)
			    {
				            printf("内存分配失败");
					            exit(-1);
						        } else
								    {
									            pQ->pTail = pQ->pFront;
										            pQ->pTail->next = NULL;
											        }
}
int isEmpty(PQUEUE pQ)
{
	    if (pQ->pFront == pQ->pTail)
	    {
		            return 1;
			        }
	        return 0;
}
void enQueue(PQUEUE pQ, int val)
{
	    PNODE pNew = (PNODE)malloc(sizeof(NODE));
	        if (pNew == NULL)
			    {
				            printf("内存分配失败");
					            exit(-1);
						        }

		    pNew->data = val;

		        pQ->pTail->next = pNew;
			pQ->pTail = pNew;
}
void deQueue(PQUEUE pQ, int *val)
{
	    if (isEmpty(pQ)){
		            printf("队列为空");
			            return;
				        } else
						    {
							            PNODE q = pQ->pFront->next;
								            *val = q->data;
									            pQ->pFront->next=q->next;
										            free(q);
											            q=NULL;
												        }
}
void show(PQUEUE pQ)
{
	    if (isEmpty(pQ))
		        {
				        printf("队列为空\n");
					    } else
						        {
								        PNODE p = pQ->pFront->next;
									        while (p)
											        {
													            printf("%d,", p->data);
														                p=p->next;
																        }

										        printf("\n");
											    }
}
int main()
{
	    int val;
	        QUEUE q;
		    init(&q);
		        enQueue(&q, 1);
			    enQueue(&q, 2);
			        enQueue(&q, 3);
				    enQueue(&q, 4);
				        show(&q);
					    deQueue(&q, &val);
					        deQueue(&q, &val);
						    show(&q);
						        return 0;
}
