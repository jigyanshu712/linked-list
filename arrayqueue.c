#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue_arr[max];
int rear=-1;
int front=-1;
void insert(int item);
int del();
int peek();
void display();
int isfull();
int isempty();


int main(){
    int choice,item;
    while(1){
        system("cls");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display element at the front\n");
        printf("4. Display all the element of the queue\n");
        printf("5. Quit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
       case 1:
        printf("input the element for adding in queue : ");
        scanf("%d",&item);
        insert(item);
        break;
       case 2:
        item=del();
        printf("deleted element is %d\n",item);
        getch();
        break;
       case 3 :
        printf("Element at the front is %d\n",peek());
        getch();
        break;
       case 4 :
        display();
        break;
       case 5 :
        exit(1);
       default:
        printf("wrong choice\n");
        }
    }
return 0;
}

void insert(int item){
    if(isfull()){
        printf("queue overflow");
        getch();
        return;
    }
    if(front==-1)
        front=0;
    rear=rear+1;
    queue_arr[rear]=item;
}

int del(){
int item;
if(isempty()){
    printf("queue underflow\n");
    exit(1);
}
item=queue_arr[front];
front=front+1;
return item;
}

int peek(){
    if(isempty()){
        printf("queue underflow\n");
        getch();
        exit(1);
    }
    return(queue_arr[front]);
}

int isempty(){
    if(front==-1 || front==rear+1)
        return 1;
    else
        return 0;
}

int isfull(){
    if(rear==max-1)
        return 1;
    else
        return 0;
}

void display(){
    int i;
    if(isempty()){
        printf("Queue is empty\n");
        getch();
        return;
    }
    printf("queue is :\n\n");
    for(i=front;i<=rear;i++)
        printf("%d\n",queue_arr[i]);
    printf("\n\n");
    getch();
}
