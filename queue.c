#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* link;
}*root=NULL;

void enqueue()
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = root;
    printf("Enter node data: ");
    scanf("%d",&new_node->data);
    root = new_node;
    if(root==NULL)
    {
        new_node->link=NULL;
    }
    else
    {
        root->link=temp;
    }

}


void dequeue()
{
    struct node* temp=root, *del;
    if(temp->link == NULL)
    {
        free(temp);
        root =NULL;
    }
    else
    {
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        del = temp->link;
        temp->link=NULL;
        free(del);
    }
}


void display()
{
    struct node* temp=root;
    if(root == NULL)
    {
        printf("\nNo elements present in queue.");
    }
    else
    {
        while(temp->link!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->link;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    int exit = 0,option=0;
    while(exit == 0)
    {
        printf("\nChoose operation: 1. Enqueue 2. Dequeue 3. Display the queue. 4.Exit.");
        scanf("\n%d",& option);
        switch(option)
        {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: exit = 1;
                break;
            default: printf("Invalid option.");
        }
    }
}