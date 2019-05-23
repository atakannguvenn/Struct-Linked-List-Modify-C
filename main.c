#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    char name[50];
    struct node *next;
};

void build_link(struct node *ap);
void display(struct node *bp, int starter);

main()
{
    struct node head;
    head.next=NULL;
    printf("Please enter 3 full names:\n");
    build_link(&head);
    display(head.next, 0);
    display(head.next, 1);
    display(head.next, 2);
    system("pause");
    return 0;
}

void build_link(struct node*tmp)
{
    int x;
    struct node *np;
    for(x = 0; x < 6; x++)
    {
        np=(struct node*) malloc(sizeof(struct node));
        scanf("%s",np->name);
        np->next=NULL;
        tmp->next=np;
        tmp=tmp->next;
    }
}

void display(struct node *np, int starter)
{
    int y = 0, z = 0, counter = 0, print_counter = 0;
    char lastnameholder[3][50], firstnameholder[3][50];
    if(starter == 0)
            printf("Names before mirroring the names\n");
        else if(starter == 1)
            printf("\nNames after mirroring the names\n");
        else if(starter == 2)
            printf("\nNames after mirroring and reversing the names\n");
    while(np!=NULL)
    {
        if(starter == 0){
            if(counter % 2 == 1){
                strcpy(lastnameholder[y],np->name);
                y++;
            }
            else{
                strcpy(firstnameholder[z],np->name);
                z++;
            }
        }
        else if(starter == 1){
            if(counter % 2 == 0){
                strcpy(np->name, lastnameholder[y]);
                y++;
            }
            else{
                strcpy(np->name, firstnameholder[z]);
                z++;
            }
        }
        else{
            strrev(np->name);
        }
        printf("%s ",np->name);
        if(print_counter % 2 == 1)
            printf("\n");
        print_counter++;
        np=np->next;
        counter++;
    }
}
