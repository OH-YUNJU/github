#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search(TreeNode *node, int key)
{
    /*Binary Search*/
    if(node == NULL) return NULL;
    if(node->key == key) return node;
    else if(node->key > key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* new_node(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode *node, int key)
{
    if(node == NULL) return new_node(key);
    
    if(key < node->key)
        node->left = insert_node(node->left, key);
    else if(key > node->key)
        node->right = insert_node(node->right, key);
    
    return node;
}

void postorder(TreeNode* root)
{
 	if(root)
		{	
			postorder(root->left);
			postorder(root->right);
			printf("%d\n", root->key);
		}
}


int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
    int num;
    
    while(scanf("%d", &num) != EOF) {
    	root = insert_node(root, num);
	}
	
	postorder(root);
    
    return 0;
}
