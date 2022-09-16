#include<stdio.h>
#include<stdlib.h>
struct node {
int info;
struct node *link;
};
struct node *top=NULL;
void push(int item);
int pop();
int peek();
int isempty();
void display();

int main(){
    int choice,item;
    while(1){
        system("cls");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. display item at the top\n");
        printf("4. display all items of the stack\n ");
        printf("5. quit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("enter the item to be pushed : ");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item=pop();
            printf("popped item is : ",item);
            getch();
            break;
        case 3:
            printf("item at the top is %d\n",peek());
            getch();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("wrong choice\n");

        }
    }
return 0;
}


void push(int item){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("stack overflow\n");
        getch();
        return ;
    }
    temp->info=item;
    temp->link=top;
    top=temp;
}


int pop(){
    struct node *temp;
    int item;
    if(isempty()){
        printf("stack overflow\n");
        getch();
        exit(1);
    }
    temp=top;
    item=temp->info;
    top=top->link;
    free(temp);
    return item;
}


int peek(){
if(isempty()){
    printf("stack underflow\n");
    getch();
    exit(1);

}
return top->info;
}

int isempty(){
if(top==NULL)
    return 1;
    else
        return 0;
}

void display(){
    struct node *ptr;
    ptr=top;
if(isempty()){
    printf("stack is empty\n");
    getch();
    return;
}
printf("stack elements :\n");
while(ptr!=NULL){
    printf("%d\n",ptr->info);
    ptr=ptr->link;
}
printf("\n");
getch();

}
