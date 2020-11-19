#include "listw.h"
LinkList* CreateList() {
		LinkList *head;
			head = (LinkList*)malloc(sizeof(LinkList));
				head->next = NULL;
					return head;
}
int Sizeof(LinkList *l) {
		struct node *p = l->next;
			int k = 0;
				while (p) {
							k++;
									p = p->next;
										}
					return k;
}
void Insert(LinkList *l, int k, dataType x) {
		if (k<1) exit (1);
			struct node *p = l;
				int i = 0;
					while (p && i<k-1) {
								p = p->next;
										i++;
											}
						if (!p) exit(1);
							struct node *s = (struct node*)malloc(sizeof(struct node));
								s->data = x;
									s->next = p->next;
										p->next = s;
}
void Delete(LinkList *l, int k) {
		if (k<1) exit(1);
			struct node *p = l;
				int i = 0;
					while (p->next && i<k-1) {
								p = p->next;
										i++;
											}
						if (p->next==NULL) exit(1);
							struct node *q = p->next;
								p->next = q->next;
									free(q);
}
int Empty(LinkList *l) {
		return l->next == NULL;
}
dataType GetData(LinkList *l, int k) {
		if (k<1) exit(1);
			struct node *p = l;
				int i = 0;
					while (p && i<k) {
								p = p->next;
										i++;
											}
						if (!p) exit(1);
							return p->data;
}
struct node* Find(LinkList *l, dataType x) {
		struct node *p = l->next;
			while (p && p->data!=x)
						p = p->next;
				return p;
}
void Print(LinkList *l) {
		struct node *p = l->next;
			while (p) {
						printf("%d ", p->data);
								p = p->next;
									}
				printf("\n");
}
void ClearLinkList(LinkList *l) {
		struct node *p, *q;
			while (p) {
						q = p;
								p = p->next;
										free(q);
											}
				l->next = NULL;

					return;

}
dataType CreateList(Node *list,int n,int m) {
	        Node *p = (Node*)malloc(sizeof(Node));
		        Node *s,*t;
			        p->data = 1;
				        p->next = NULL;
					        Node *q = p;
						        for(int i=2; i<=n;++i){
										Node *r = (Node*)malloc(sizeof(Node));
												r->data = i;
														r->next = NULL;
																q->next = r;
																		q = r;
																				}
									q->next = p;
											s = p;
													while(s->next !=s){
																	for(int i=1; i<m; ++i){
																						t = s;
																						                                s = s->next;
																													}
																			t->next = s->next;
																					free(s);
																							s = t->next;
																									}
														return s->data;
}

