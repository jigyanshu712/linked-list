#include<stdio.h>
#include<stdlib.h>
struct node {
int info;
struct node *prev;
struct node *next};

struct node* create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start ,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *add_after(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
int main(){
    int choice ,data,item;
    struct node *start=NULL;
    while(1){
        system("cls");
        printf("1. create list\n");
        printf("2. Display\n");
        printf("3. Add to Empty List\n");
        printf("4. Add to beginning\n");
        printf("5.  add to end\n");
        printf("6. add after\n");
        printf("7. add before\n");
        printf("8. Delete\n");
        printf("9. Reverse\n");
        printf("10. quit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            start=create_list(start);
            break;
        case 2 :
            display(start);
            break;
        case 3 :
            printf("enter the element to be inserted : ");
            scanf("%d",&data);
            start=addtoempty(start,data);
            break;
        case 4:
            printf("enter the  element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg(start,data);
            break;
        case 5:
            printf("enter the element to be inserted : ");
            scanf("%d", &data);
            start=addatend(start,data);
            break;
        case 6:
            printf("enter the element  to be inserted : ");
            scanf("%d",&data);
            printf("enter the element after which to be insert : ");
            scanf("%d",&item);
            start=add_after(start,data,item);
            break;
        case 7:
             printf("enter the element  to be inserted : ");
            scanf("%d",&data);
            printf("enter the element after which to be insert : ");
            scanf("%d",&item);
            start=addbefore(start,data,item);
            break;
        case 8:
            printf("enter the element to be deleted : ");
            scanf("%d",&data);
            start=del(start,data);
            break;
        case 9:
            start=reverse(start);
            break;
        case 10:
            exit(1);
        default :
            printf("wrong choice");

        }


    }
return 0;
}





void display(struct node *start){
    struct node *p;
    if(start==NULL){
        printf("list is empty\n");
        getch();
        return;
    }
    p=start;
    printf("list is :\n");
    p=start;
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
    printf("\n");
    getch();
}


struct node *addatbeg(struct node *start,int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=start;
    start->prev=temp;
    start=temp;
    return start;
}

struct node *addtoempty(struct node *start,int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=NULL;
    start=temp;
    return start;
}


struct node *addatend(struct node *start,int data){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    while(p->next!=NULL){
        p=p->next;}
        p->next=temp;
        temp->next=NULL;
        temp->prev=p;
        return start;

}



struct node *add_after(struct node *start,int data,int item){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    while(p!=NULL){
        if(p->info==item){
            temp->prev=p;
            temp->next=p->next;
            if(p->next!=NULL)
                p->next->prev=temp;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    printf("%d not present in the list\n",item);
    return start;
}


struct node *addbefore(struct node *start,int data,int item){
    struct node *temp,*q;
    if(start==NULL){
        printf("list is empty\n");
        getch();
        return start;
    }
    if(start->info==item){
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->prev=NULL;
        temp->next=start;
        temp->prev=temp;
        start=temp;
        return start;
    }
    q=start;
    while(q!=NULL){
        if(q->info==item){
            temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->prev=q->prev;
            temp->next=q;
            q->prev->next=temp;
            q->prev=temp;
            return start;
        }
        q=q->next;

    }
    printf("%d not present in the list\n",item);
    getch();
    return start;
}


struct node *create_list(struct node *start){
    int i,n,data;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;
    printf("enter the element to be inserted : ");
    scanf("%d",&data);
    start=addtoempty(start,data);
    for(i=2;i<=n;i++){
        printf("enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;
}

struct node *reverse(struct node *start){
    struct node *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL){
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    printf("list reversed\n");
    return start;
}


struct node *del(struct
                  node *start,int data){
    struct node *temp;
    if(start==NULL){
        printf("list is empty\n");
        getch();
        return start;
    }
    if(start->next==NULL)
    if(start->info==data){
        temp=start;
        start=NULL;
        free(temp);
        return start;
    }
    else{
        printf("element %d not found\n",data);
        getch();
        return start;
    }
    if(start->info==data){
        temp=start;
        start=start->next;
        start->prev=NULL;
        free(temp);
        return start;

    }
    temp=start->next;
    while(temp->next!=NULL){
        if(temp->info==data){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            return start;

        }
        temp=temp->next;
    }
    if(temp->info==data){
        temp->prev->next=NULL;
        free(temp);
        return start;
    }
    printf("element %d not found\n",data);
    getch();
    return start;

}




