#include "listw.c" 

int main() 
{
	LinkList *list = CreateList();
	Insert(list, 1, 10);
	Insert(list, 1, 20);
	Delete(list, 2);
	Insert(list, 1, 30);
	Insert(list, 1, 40);
	printf("链表的元素个数为： %d\n", Sizeof(list));
	printf("%d %d %d\n", GetData(list, 1), GetData(list, 2), GetData(list, 3));
	printf("链表的第2个元素为： %d\n", GetData(list, 2));
	printf("最后一个获胜者的编号是： %d\n", CreateList(list, 11, 3));
	return 0;
}
