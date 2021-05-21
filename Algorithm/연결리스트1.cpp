#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link; //자기 참조 구조체
}ListNode;

ListNode* insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* delete_first(ListNode *head)
{
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = head->link;
    free(removed); //메모리 반납
    return head;
}

//search target node
ListNode* search_node(ListNode *head, int value)
{
    //is there? true(1), false(0)
    for(ListNode *p = head; p != NULL; p = p->link)
    {
        if(p->data == value)
            return p;
    }
    return NULL;
}

ListNode* delete_node(ListNode *head, int value) //원하는 노드 삭제 
{
    ListNode* removed = search_node(head, value);
    
    if (removed == NULL) {
    	return head;
    }
    	
    else if (head->data == value) {
    	delete_first(head);
    }
    
	else {
    	ListNode *p = head;
    
    	while(p != NULL && p->link != removed) {
    	p = p->link;
		}
    	p->link = removed->link;
		free(removed);
		return head;
	}
}

/*ListNode* delete_last(ListNode *head) //마지막 노드 삭제 
{ 
	ListNode *tmp; 
	
	tmp = head->link;
		while (tmp->link != NULL) {
			head = tmp;
			tmp = tmp->link; 
		}
		free(tmp);
		head->link = NULL;
}*/

void print_list(ListNode *head)
{
    for(ListNode *p = head; p != NULL; p = p->link)
    {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(int argc, const char * argv[]) {
    
    ListNode *head = NULL;
    for(int i = 0; i < 4; i++)
    {
        head = insert_first(head, i);
        print_list(head);
        
    }
    
	head = delete_node(head, 3);
    print_list(head);
    
    ListNode *search = search_node(head, 1);
    if (search) {
        printf("search = %d\n", search->data);
        print_list(head);
	}
    else
        printf("There isn't %d", 1);
    
    
    return 0;
}
