#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    char arr[100];
} TreeNode;

TreeNode* search(TreeNode *node, char arr)
{
    /*Binary Search*/
    if(node == NULL) return NULL;
    if(node == *arr) return node;
    else if(node->arr > arr)
        return search(node, arr);
    else
        return search(node, arr);
}

TreeNode* new_node(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode *node, char *arr)
{
    if(node == NULL) return new_node(arr);
    
    if(key < arr)
        node->left = insert_node(node->left, arr);
    else if(key > node->arr)
        node->right = insert_node(node->right, arr);
    
    return node;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
	char arr[501];
    int count, N, M; 
 
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; ++i) {
        scanf("%s", arr);
        root = insert_node(root, arr);
    }
 
    for(int i = 0; i < M; ++i) {
        scanf("%s", arr);
        
        if(search(root, arr)) {
            ++count;
        }
    }
 
    printf("%d", count);
    
    return 0;
}
