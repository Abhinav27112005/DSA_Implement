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

Node *insert_spe(Node *start, int item) // Inserting a node in the list at specific positon
{
    Node *new_node, *p, *loc;
    int temp;

    printf("\nEnter a Number after which Data is to be inserted: ");
    scanf("%d", &temp);
    new_node = (Node *)malloc(sizeof(Node));
    new_node->info = item;
    p = start;
    loc = start;
    while (p->info != temp)
    {
        /* code */
        p = p->next;
    }
    p = p->next;
    loc = p->next;
    p->next = new_node;
    new_node->next = loc;
    return start;
}

Node *Delete_spe(Node *start, int item)
{
    int temp;
    Node *ptr;
    if (start == NULL)
    {
        /* code */
        printf("list is Empty");
    }
    printf("\nEnter a Number You want to Delete!!");
    scanf("%d", &temp);
    ptr = start;

    while (ptr->info != temp)
    {
        /* code */
        ptr = ptr->next;
    }
    printf("\nNumber You Have Deleted is : %d", ptr->info);
    free(ptr);
    return start;
}

int main(int argc, char const *argv[])
{
    int choice, num;
    char ch;
    system("cls");
    createemptylist(Start);
    do
    {
        /* code */
        printf("\n1. Insert Element at Beginning!");
        printf("\n2. Insert Element at End Position!!");
        printf("\n3. Insert Element at Specific Position!");
        printf("\n4. Traverse the List");
        printf("\n5. Delete Element at Beginning!");
        printf("\n6. Delete Element at Last!");
        printf("\n7. Delete Element at Specific Position!");
        printf("\n8. Exit");
        printf("\n\n\nEnter Your Choice!!");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* code */
            printf("\nEnter a Number You Want to Enter: ");
            scanf("%d", &num);
            insertbegin(num);
            break;
        case 2:
            printf("\nEnter a Number You Want to Enter: ");
            scanf("%d", &num);
            insert_at_end(num);
            break;
        case 3:
            printf("\nEnter a Number You Want to Enter: ");
            scanf("%d", &num);
            Start = insert_spe(Start, num);
            break;
        case 4:
            printf("\nTraversing a List: ");
            traverse(Start);
            break;
        case 5:
            printf("\nDeleting the Number!");
            dele_beg();
            break;
        case 6:
            printf("\nDeleting the Number!!");
            dele_end();
            break;
        case 7:
            printf("\nEnter a Number You Want to Delete: ");
            scanf("%d", &num);
            Start = Delete_spe(Start, num);
            break;
        case 8:
            exit(0);
        default:
            printf("\nEnter a Valid Choice!!");
            break;
        }
    } while (choice);

    return 0;
}