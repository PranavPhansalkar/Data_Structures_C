#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
}*root,*ref;

void append()
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter node data: ");
	scanf("%d",&new_node->data);
	new_node->link = NULL;
	ref = root;

	if (root == NULL)
	{
		root=new_node;
	}
	else
	{
		while (ref->link != NULL)
		{
			ref = ref->link;
		}
		ref->link = new_node;
	}
}

void delete_node(int x)
{
	struct node* connect=root;
	struct node* pointer;
	int del = 1;
	ref = root->link;
	if (x == 1)
	{
		root = root->link;
		free(connect);
	}
	else
	{
		while (del != x-1)
		{
			connect = connect->link;
			del++;
		}
		pointer = connect-> link;
		connect->link = pointer->link;
		pointer->link = NULL;
		free(pointer);
	}
}

int length()
{
	int length = 0;
	struct node* ref = root;
	while (ref != NULL)
	{
		ref = ref->link;
		length++;
	}
	return length;
}

void reverse()
{
	int i = 0, j = (length() - 1);
	struct node* first, *last;
	first = last = root;
	while (i < j)
	{
		int k = 0;
		while (k < j)
		{
			last = last->link;
			k++;
		}
		int temp = first->data;
		first->data = last->data;
		last->data = temp; 
		first = first->link;
		last = root;
		i++; j--;
	}
}

void display()
{
	ref = root;
	while (ref != NULL)
	{
		printf("\n%d", ref->data);
		ref = ref->link;
	}
}
int main() 
{
	int exit = 0, no_of_nodes = 0, option = 0;
	while (exit == 0)
	{
		printf("\nChoose operation: 1.Append 2.Display 3.Delete 4.Length 5.Reverse the list 6.Exit.");
		scanf("%d", &option);

		switch (option)
		{
		case 1:printf("Enter number of nodes : ");
			scanf("%d", &no_of_nodes);
			for (int i = 0; i < no_of_nodes; i++)
			{
				append();
			}
			break;

		case 2:display();
			break;
		
		case 3: {int del = 0;
			scanf("%d", &del);
			delete_node(del); }
			break;
		
		case 4: printf("\nLength of the list is: %d",length());
			break;

		case 5:reverse();
			break;

		case 6:exit = 1;
			break;
		}
	}
	return 0;
}


