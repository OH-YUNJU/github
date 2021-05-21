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

TreeNode* max_value_node(TreeNode *node)
{
    TreeNode *curr = node;
    
    while(curr->right != NULL)
        curr = curr->right;
    return curr;
}

//right subtree Min
TreeNode* min_value_node(TreeNode *node)
{
    TreeNode *curr = node;
    
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

TreeNode* delete_node(TreeNode *root, int key)
{
    if(root == NULL) return NULL;
    
    if(key < root->key)
        root->left = delete_node(root->left, key);
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    else
    {
        //leaf node
        if(root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        //parent node
        TreeNode *temp = min_value_node(root->right);
        
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}


void preorder(TreeNode* root)
{
	if(root)
	{	
		printf(" %d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
 }


void inorder(TreeNode* root)
{
    if(root) //NULL이 아닌 경우
    {
        inorder(root->left);
        printf(" %d ", root->key);
        inorder(root->right);
    }
}


void postorder(TreeNode* root)
{
 	if(root)
		{	
			postorder(root->left);
			postorder(root->right);
			printf(" %d ", root->key);
		}
}


int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
    
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 25);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 30);
    
    inorder(root); printf("\n\n");
    preorder(root); printf("\n\n"); 
    postorder(root); printf("\n\n"); 
    
    if(search(root, 30))
        printf("\nThere is %d\n", 30);
    else
        printf("\nThere isn't %d\n", 30);
    
    return 0;
}
