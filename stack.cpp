#include<stdio.h>
#include<stdlib.h>

struct node {

	int data;
	struct node* link;
}*top;



void push()
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &(new_node->data));
	
	if (top == NULL)
	{
		new_node->link = NULL;
		top = new_node;
	}
	else 
	{
		new_node->link = top;
		top = new_node;
	}
}

void pop()
{
	struct node* temp=top;
	if (top == NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		top = top->link;
		free(temp);
	}
}


void display()
{
	struct node* temp = top;
	while (temp != NULL)
	{
		printf("\n%d",(temp->data));
		temp = temp->link;
	}

}



int main()
{
	int opt=0,choice=0;
	while (opt == 0)
	{
		printf("\nChoose operation: 1.Push 2.Pop 3. Display: ");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:push();
			break;

		case 2:pop();
			break;

		case 3:display();
			break;
		}
	}
	return 0;
}