// Program of Linked List

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node // Self Referential Structure for creting a node
{
    /* data */
    int info;
    struct node *next;
};

typedef struct node Node;
Node *Start;

void createemptylist(Node *s1) // Creating a fuction for creating a empty list
{
    Start = NULL; //*Start Doesnot point any value so writing *Start=Null Gives error
}

void traverse(Node *p)
{
    while (p->next != NULL)
    {
        /* code */
        printf("\n%d", p->info);
        p = p->next;
    }
}

void insertbegin(int item) // Inserting node at the beginning of the linked list
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->info = item;
    if (Start == NULL)
    {
        /* code */
        p->next = NULL;
    }
    else
    {
        p->next = Start;
    }
    Start = p;
}
void insert_at_end(int item) // Inserting a Node at the end of the Linked List
{
    Node *p, *loc;
    p = (Node *)malloc(sizeof(Node));
    p->info = item;
    p->next = NULL;
    if (Start == NULL)
    {
        /* code */
        Start = p;
    }
    else
    {
        loc = Start;
        while (loc->next != NULL)
        {
            /* code */
            loc = loc->next;
        }
        loc->next = p;
    }
}

void dele_beg(void)
{
    Node *p;
    if (Start == NULL)
    {
        /* code */
        printf("\nList is Empty!!");
    }
    else
    {
        p = Start;
        Start = Start->next;
        printf("\nNumber which is to be deleted is %d", p->info);
        free(p);
    }
}

void dele_end()
{

    Node *p, *loc;
    if (Start == NULL)
    {
        /* code */
        printf("\nList is Empty");
    }
    else if (Start->next == NULL)
    {
        /* code */
        p = Start;
        Start = NULL;
        printf("\nNumber which is Deleted is %d", p->info);
        free(p);
    }
    else
    {
        loc = Start;
        p = Start->next;
        while (p->next != NULL)
        {
            /* code */
            loc = p;
            p = p->next;
        }
        loc->next = NULL;
        printf("\nNumber which is deleted is %d", p->info);
        free(p);
    }
}

Node *insert_spe(Node *Start, int item) // Inserting a node in the list at specific positon
{
    Node *new_node, *p, *loc;
    int temp;

    printf("\nEnter a Number after which Data is to be inserted: ");
    scanf("%d", &temp);
    new_node = (Node *)malloc(sizeof(Node));
    new_node->info = item;
    p = Start;
    loc = Start;
    while (p->info != temp)
    {
        /* code */
        p = p->next;
        }
}