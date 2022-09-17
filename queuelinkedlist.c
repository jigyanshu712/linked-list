#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
void insert(int item);
int del();
int peek();
int isempty();
void display();
int main(){
    int choice ,item;
    while(1){
        system("cls");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. display the element at the front\n");
        printf("4. display all the element of the queue\n");
        printf("5. quit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("input the element for adding in queue : ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            printf("deleted element is %d\n",del());
            getch();
            break;
        case 3:
            printf("element at the front of queue is %d\n",peek());
            getch();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default :
            printf("wrong choice\n");

        }

    }
return 0;
}



void insert(int item){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("memory is not available\n");
        getch();
        return;
    }
    temp->info=item;
    temp->link=NULL;
    if(front==NULL)
        front=temp;
    else
        rear->link=temp;
    rear=temp;
}

int del(){
struct node *temp;
int item;
if(isempty()){
    printf("queue underflow\n");
    getch();
    exit(1);
}
temp=front;
item=temp->info;
front=front->link;
free(temp);
return item;
}

int peek(){
if(isempty()){
    printf("queue underflow\n");
    getch();
    exit(1);
}
return(front->info);
}

int isempty(){
    if(front==NULL)
        return 1;
    else
        return 0;
}
void display(){
    struct node *ptr;
    ptr=front;
    if(isempty()){
        printf("queue is empty\n");
        getch();
        return;
    }
  while(ptr!=NULL){
    printf("%d\n",ptr->info);
    ptr=ptr->link;
  }
  printf("\n\n");
  getch();
}
