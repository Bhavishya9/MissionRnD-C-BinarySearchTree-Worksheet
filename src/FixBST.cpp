/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *left_part(struct node *root, int rootdata)
{
	if (root == NULL)
		return 0;
	//if (root->right != NULL)
		left_part(root->left, rootdata);
	if (root->data > rootdata)
		return root;
	//if (root->right!=NULL)
		left_part(root->right, rootdata);
}

struct node *right_part(struct node *root, int rootdata)
{
	if (root == NULL)
		return 0;
	//if (root->right != NULL)
		right_part(root->left, rootdata);
	if (root->data < rootdata)
		return root;
	//if (root->right != NULL)
		right_part(root->right, rootdata);
}

void fix_bst(struct node *root){
	if (root != NULL)
	{
		struct node *left_sub_tree;
		struct node *right_sub_tree;
		left_sub_tree = left_part(root->left, root->data);
		right_sub_tree = right_part(root->right, root->data);
		int temp = left_sub_tree->data;
		left_sub_tree->data = right_sub_tree->data;
		right_sub_tree->data = temp;
	}
}
