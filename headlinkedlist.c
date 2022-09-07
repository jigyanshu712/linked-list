#include<stdio.h>
#include<stdlib.h>
struct node {
int info;
struct node *link;
};
struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatend(struct node *head, int data);
struct node *addbefore(struct node *head,int data,int item);
struct node *addatpos(struct node *head,int data,int pos);
struct node *del(struct node *head,int data);
struct node *reverse(struct node *head);
int main(){
     int choice ,data,item,pos;
     struct node *head;
     head=(struct node *)malloc(sizeof(struct node));
     head->info=0;
     head->link=NULL;
     head=create_list(head);
     while(1){
        system("cls");
        printf("1. Display\n");
        printf("2. addatend\n");
        printf("3. add before node\n");
        printf("4. add at position\n");
        printf("5. Delete\n");
        printf("6. Reverse\n");
        printf("7. Quit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            display(head);
            break;
        case 2 :
            printf("enter the element to be inserted : ");
            scanf("%d",&data);
            head=addatend(head,data);
            break;
        case 3 :
            printf("enter the element to be inserted : ");
            scanf("%d",&data);
            printf("enter the element before which to insert : ");
            scanf("%d",&item);
            head=addbefore(head,data,item);
            break;
        case 4:
            printf("enter the element to be inserted : ");
            printf("%d",&data);
            printf("enter the position at which to insert : ");
            scanf("%d",&pos);
            head=addatpos(head,data,pos);
            break;
        case 5:
            printf("enter the element to be deleted : ");
            scanf("%d",&data);
            head=del(head,data);
            break;
        case 6:
            head=reverse(head);
            break;
        case 7:
            exit(1);
        default:
            printf("invalid choice \n");
            }
     }

return 0;
}




struct node *create_list(struct node *head){
    int i,n,data;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the element to be inserted : ");
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
}


void display(struct node *head){
struct node *p;
if(head->link==NULL){
    printf("list is empty\n");
    getch();
    return;}
    p=head->link;
    printf("list is : \n");
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->link;
    }
    printf("\n");
    getch();
}


struct node *addatend(struct node *head,int data){
    struct node *p,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    p=head;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=temp;
    temp->link=NULL;
    return head;
}


struct node *addbefore(struct node *head,int data,int item){
    struct node *temp,*p;
    p=head;
    while(p->link!=NULL){
        {
        if(p->link->info==item){
            temp=(struct node *)malloc(sizeof(struct node));
            temp->info=data;
            temp->link=p->link;
            p->link=temp;
            return head;
        }
        p=p->link;
        }
        printf("%d not present in the list\n", item);
        getch();
        return head;
            }
}

struct node *addatpos(struct node *head,int data,int pos){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    p=head;
    for(int i=1;i<=pos-1;i++){
        p=p->link;
        if(p==NULL){
            printf("there are less than %d elements\n",pos);
            getch();
            return head;
                    }

    }
    temp->link=p->link;
    p->link=temp;
    return head;
    }

struct node *del(struct node *head,int data){
    struct node  *temp,*p;
    p=head;
    while(p->link!=NULL){
        if(p->link->info==data){
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return head;
        }
        return head;
    }
    printf("element %d not found\n",data);
    return head;
}


struct node *reverse(struct node *head){
    struct node *prev,*ptr,*next;
    ptr=head->link;
    prev=NULL;
    while(ptr!=NULL){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    head->link=prev;
    return head;

}




