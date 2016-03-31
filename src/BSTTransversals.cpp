/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int preorder_to_array(struct node *root, int *arr, int i)
{
	if (root == NULL)
		return i;
	arr[i] = root->data;
	i++;
	if (root->left != NULL)
		i = preorder_to_array(root->left, arr, i);
	if (root->right != NULL)
		i = preorder_to_array(root->right, arr, i);
	return i;
}

int inorder_to_array(struct node *root, int *arr, int i)
{
	if (root == NULL)
		return i;
	if (root->left != NULL)
		i = inorder_to_array(root->left, arr, i);
	arr[i] = root->data;
	i++;
	if (root->right != NULL)
		i = inorder_to_array(root->right, arr, i);
	return i;
}

int postorder_to_array(struct node *root, int *arr, int i)
{
	if (root == NULL)
		return i;
	if (root->left != NULL)
		i = postorder_to_array(root->left, arr, i);
	if (root->right != NULL)
		i = postorder_to_array(root->right, arr, i);
	arr[i] = root->data;
	i++;
	return i;
}
int pre_index = 0, post_index = 0, in_index = 0;
void inorder(struct node *root, int *arr){
	if (root!=NULL && arr!=NULL)
		inorder_to_array(root, arr, 0);
}
void preorder(struct node *root, int *arr){
	if (root!=NULL && arr!=NULL)
		preorder_to_array(root, arr, 0);
}
void postorder(struct node *root, int *arr){
	if (root!=NULL && arr !=NULL)
		postorder_to_array(root, arr, 0);
}
