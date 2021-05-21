#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

//point myself
void init(DListNode *phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode *phead)
{
    for(DListNode *p = phead->rlink; p != phead; p = p->rlink)
    {
        printf(" <-|%d|-> ", p->data);
    }
    printf("\n");
}

void dinsert_first(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete_first(DListNode *head, DListNode *removed)
{
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void ddelete_want(DListNode *phead, element data)
{
	for(DListNode *p = phead->rlink; p != phead; p = p->rlink)
    {
        if(p->data == data) {
    		DListNode *removed = p;
    		removed->rlink->llink = removed->llink;
			removed->llink->rlink = removed->rlink;

			free(removed);
    	}
    }
}  
//search and delete target node

//search and is there?

int main(int argc, const char * argv[]) {
    
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    
    printf("\n삽입단계\n");
    for(int i = 0; i < 5; i++)
    {
        dinsert_first(head, i);
        print_dlist(head);
    }
    
    /*printf("\n삭제단계\n");
    for(int i = 0; i < 5; i++)
    {
        print_dlist(head);
        ddelete_first(head, head->rlink);
    }*/
    
    ddelete_want(head, 3);
	print_dlist(head); 
    
    free(head);
    return 0;
}

                       
