#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search(TreeNode *node, int key)
{

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

TreeNode* insert_node(TreeNode *node, char A, char B, char C)
{
    node->key = A; 
	 
    if(B != '.')
        node->left = new_node(B);
    else if(C != '.')
        node->right = new_node(C);
    
    //return node;
}

/*TreeNode* max_value_node(TreeNode *node)
{
    TreeNode *curr = node;
    
    while(curr->right != NULL)
        curr = curr->right;
    return curr;
}

TreeNode* min_value_node(TreeNode *node)
{
    TreeNode *curr = node;
    
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}*/

void preorder(TreeNode* root)
{
	if (root == NULL)
		return;	
	printf(" %d ", root->key);
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(TreeNode* root)
{
    if (root == NULL)
		return;
    inorder(root->left);
    printf(" %d ", root->key);
    inorder(root->right);
    
}

void postorder(TreeNode* root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\n", root->key);
		
}


int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
    TreeNode* tmp;
    int num;
    
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; i++) {
    	char A, B, C;
    	scanf("%c %c %c", &A, &B, &C);
    	getchar();
    	tmp = search(root, A);
    	
    	if (tmp != NULL)
            insert_node(tmp, A, B, C);
        else
        	insert_node(root, A, B, C);
    }
    
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
	
	return 0;
}
