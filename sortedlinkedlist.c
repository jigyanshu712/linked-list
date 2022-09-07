#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
void display(struct node *start);
struct node *insert(struct node *start,int data);
void search(struct node *start, int data);

int main(){
    int choice ,data;
    struct node *start=NULL;
    while(1){
        system("cls");
    printf("1. insert\n");
    printf("2. Display\n");
    printf("3. Search\n");
    printf("4. quit\n");
    printf("enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("enter the element to be inserted : ");
        scanf("%d",&data);
        start=insert(start,data);
        break;
    case 2:
        display(start);
        break;
    case 3:
        printf("enter the element to be searched  : ");
        scanf("%d",&data);
        search(start,data);
        break;
    case 4:
        exit(1);
    default :
        printf("invalid choice\n");
    }
    }
return 0;
}


struct node *insert(struct node *start,int data){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL || data<start->info){
        temp->link=start;
        start=temp;
        return start;
    }
    else{
        p=start;
        while(p->link!=NULL && p->link->info<data)
            p=p->link;
        temp->link=p->link;
        p->link=temp;
    }
    return start;
}



void search(struct node *start,int data){
    struct node *p;
    int pos;
    if(start==NULL || data<start->info){
        printf("%d not found in the list\n",data);
        getch();
        return ;
    }
    p=start;
    pos=1;
    while(p!=NULL && p->info<=data){
        if(p->info==data){
            printf("%d found at position %d\n",data,pos);
            getch();
            return;
        }
        p=p->link;
        pos++;
    }
    printf("%d not found in the list\n",data);
    getch();
}

void display(struct node *start){
    struct node *q;
    if(start==NULL){
        printf("list is empty");
        getch();
        return ;
    }
    q=start;
    printf("list is : \n");
    while(q!=NULL){
        printf("%d\n",q->info);
        q=q->link;
    }
    printf("\n");
    getch();
}
