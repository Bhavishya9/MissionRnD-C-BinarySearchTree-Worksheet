/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int no_of_elements = 0, rear = 0, front = 0,length_of_queue=0;
struct node **queue;

void insert_to_queue(struct node *item)
{
	length_of_queue++;
	queue = (struct node **)realloc(queue, length_of_queue);
	queue[rear++] = item;
	no_of_elements++;
}

struct node *delete_from_queue()
{
	struct node *item;
	item = queue[front];
	front++;
	no_of_elements--;
	return item;
}
int* BSTRighttoLeftRows(struct node* root)
{
	int size = 0,index=0;
	int *arr = (int *)malloc(size*sizeof(int));
	struct node *current = root;
	if (root == NULL)
	{
		return NULL;
	}
	while (no_of_elements != 0)
	{
		current = delete_from_queue();
		size++;
		arr = (int *)realloc(arr, size);
		arr[index++] = current->data;
		if (current->left != NULL)
			insert_to_queue(current->left);
		if (current->right != NULL)
			insert_to_queue(current->right);
	}
	return arr;
    
}
