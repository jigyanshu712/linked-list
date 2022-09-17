#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *link;
};
struct node *rear=NULL;
void insert(int item);
int del();
void display();
int isempty();
int peek();
int main(){
    int choice,item;
    while(1){
        system("cls");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. quit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
           case 1:
            printf("enter the element  for insertion : ");
            scanf("%d",&item);
            insert(item);
            break;
           case 2:
            printf("deleted element is %d\n",del());
            getch();
            break;
           case 3:
            printf("item at the front of the queue is %d\n",peek());
            getch();
            break;
           case 4:
            display();
            break;
           case 5 :
            exit(1);
           default:
            printf("wrong choice\n");

        }
    }
return 1;
}



void insert(int item){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->info=item;
  if(temp==NULL){
    printf("memory not available\n");
    getch();
    return;
  }
  if(isempty()){
    rear=temp;
    temp->link=rear;
  }
  else
  {
    temp->link=rear->link;
    rear->link=temp;
    rear=temp;
  }
}

int del(){
    int item;
    struct node  *temp;
    if(isempty()){
        printf("queue underflow\n");
        getch();
        exit(1);
    }
    if(rear->link==rear){
        temp=rear;
        rear=NULL;
    }
    else
    {

        temp=rear->link;
        rear->link=rear->link->link;
    }
    item=temp->info;
    free(temp);
    return item;
}

int peek(){
    if(isempty()){
            printf("queue underflow\n");
            exit(1);
    }
    return rear->link->info;
}

int isempty(){
    if(rear==NULL)
        return 1;
    else
        return 0;
}



void display(){
    struct node *p;
    if(isempty())
    {   printf("queue is empty\n");
        getch();
        return;
    }
    printf("queue is : \n");
    p=rear->link;
    do{
        printf("%d\n",p->info);
        p=p->link;
    }while(p!=rear->link);
    printf("\n");
    getch();
}
