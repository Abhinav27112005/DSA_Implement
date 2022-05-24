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

Node *createemptylist(Node *s1) // Creating a fuction for creating a empty list
{
    Start = NULL; //*Start Doesnot point any value so writing *Start=Null Gives error
}

Node *traverse(Node *start)
{
    Node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        /* code */
        printf("\t %d", ptr->info);
        ptr = ptr->next;
    }
    return start;
}

Node *insertbegin(Node *st, int item) // Inserting node at the beginning of the linked list
{
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    new->info = item;
    new->next = st;
    st = new;
    return st;
}
Node *insertEnd(Node *st, int item) // Inserting a Node at the end of the Linked List
{
    Node *ptr, *new;
    new = (Node *)malloc(sizeof(Node));
    new->info = item;
    new->next = NULL;
    ptr = st;
    while (ptr->next != NULL)
    {
        /* code */
        ptr = ptr->next;
    }
    ptr->next = new;
    return st;
}

Node *dele_beg(Node *st)
{
    Node *ptr;
    ptr = st;
    st = st->next;
    free(ptr);
    return st;
}

Node *dele_end(Node *st)
{
    Node *ptr, *p;
    ptr = st;
    while (ptr->next != NULL)
    {
        /* code */
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return st;
}

Node *insert_spe(Node *st, int data, int item) // Inserting a node in the list at specific positon
{
    Node *new, *ptr, *p;
    new = (Node *)malloc(sizeof(Node));
    new->info = data;
    p = ptr = st;

    while (p->info != item)
    {
        /* code */
        p = ptr;
        ptr = ptr->next;
    }
    p->next = new;
    new->next = ptr;
    return st;
}

Node *Delete_spe(Node *st, int item)
{
    Node *p, *ptr;
    ptr = st;
    p = ptr;
    while (p->info != item)
    {
        /* code */
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
    return st;
}

void menu()
{
    int choice, num, i = 0, num2;
    char ch;
    createemptylist(Start);
    do
    {
        /* code */
        system("cls");
        printf("\n1. Insert Element at Beginning!");
        printf("\n2. Insert Element at End Position!!");
        printf("\n3. Insert Element at Specific Position!");
        printf("\n4. Display the List");
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
            printf("\nEnter a Number You Want to Insert on The List: ");
            scanf("%d", &num);
            Start = insertbegin(Start, num);
            break;
        case 2:
            printf("\nEnter a Number You Want to Insert on the List: ");
            scanf("%d", &num);
            Start = insertEnd(Start, num);
            break;
        case 3:
            printf("\nEnter a Number You Want to Insert on the List: ");
            scanf("%d", &num);
            printf("\nEnter after which Number You want to Insert: ");
            scanf("%d", &num2);
            Start = insert_spe(Start, num, num2);
            break;
        case 4:
            printf("\nTraversing a List: ");
            Start = traverse(Start);
            break;
        case 5:
            printf("\nDeleting the Number!");
            Start = dele_beg(Start);
            break;
        case 6:
            printf("\nDeleting the Number!!");
            Start = dele_end(Start);
            break;
        case 7:
            printf("\nEnter the value after which the node has to be deleted: ");
            scanf("%d", &num);
            Start = Delete_spe(Start, num);
            break;
        case 8:
            exit(0);
        default:
            printf("\nEnter a Valid Choice!!");
            break;
        }
        i++;
        getch();
    } while (i);
}

int main(int argc, char const *argv[])
{
    menu();
    getch();
    return 0;
}
