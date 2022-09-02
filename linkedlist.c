#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node* next;
};
struct node* create_list( struct node  *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data ,int item);
struct node *addatpos(struct node *start ,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);


int main(){
    struct node *start=NULL;
    int choice,data,item,pos;
    while(1){
            system("cls");

        printf("1. create list\n");
        printf("2. Display\n");
        printf("3. count\n");
        printf("4. search\n");
        printf("5. add at beginning\n");
        printf("6.  add at end\n");
        printf("7. add after node\n");
        printf("8. add before node\n");
        printf("9.  add at position\n");
        printf("10. delete\n");
        printf("11. reverse\n");
        printf("12. quit\n\n");
        printf("enter your choice :  ");
        scanf("%d",&choice);



        switch(choice){
        case 1:
               start=create_list(start);
               break;
        case 2:
               display(start);
               break;
        case 3:
               count(start);
               break;
        case 4:
               printf("enter the element to be searched : ");
               scanf("%d",&data);
               search(start,data);
               break;
        case 5:
               printf("enter the element to be inserted : ");
               scanf("%d",data);
               start=addatbeg(start,data);
               break;
        case 6:
              printf("enter the element to be inserted : ");
              scanf("%d",&data);
              start=addatend(start,data);
               break;
        case 7:
               printf("enter the element to be inserted : ");
               scanf("%d",&data);
               printf("enter the element after which to be insert :  ");
               scanf("%d",&item);
               start=addafter(start,data,item);
               break;
        case 8:
               printf("enter the element to be inserted : ");
               scanf("%d",&data);
               printf("enter the element before which to be insert :  ");
               scanf("%d",&item);
               start=addbefore(start,data,item);
               break;
        case 9:
               printf("enter the element to be inserted : ");
               scanf("%d",&data);
               printf("enter the position at which to insert :  ");
               scanf("%d",&pos);
               start=addatpos(start,data,pos);
               break;
        case 10:
                printf("enter the element to be deletd : ");
                scanf("%d",&data);
                start=del(start,data);
                break;
        case 11:
                start=reverse(start);
                break;
        case 12:
                exit(1);
        default :
                 printf("wrong choice\n");

        }
            }


return 0;
}



void display(struct node *start){
    struct node  *p;
    if(start==NULL){
        printf("list is empty\n");
        getch();
        return;}
        p=start;
        printf("list is :\n");
        while(p!=NULL){
            printf("%d\n",p->info);
            p=p->next;
        }
        printf("\n\n");
        getch();
}



void count(struct node *start){
    int count=0;
    struct node* p;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    p=start;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    printf("number of elements are %d\n",count);
    printf("\n\n");
    getch();
}


void search(struct node *start , int item){
    struct node *p=start;
    int pos=1;
    while(p!=NULL){
        if(p->info==item){
                printf("item %d found at position %d\n",item,pos);
                getch();
                return ;

        }
        p=p->next;
        pos++;
    }
    printf("item %d not found in list\n",item);
    getch();
}


struct node* addatbeg(struct node  *start,int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=start;
    start=temp;
    return start;

}

struct node*addatend(struct node *start,int data){
    struct node *p ,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    while(p->next!=NULL){
            p=p->next;

          }
    p->next=temp;
    temp->next=NULL;
    return start;

}


struct node* addafter(struct node* start,int data,int item){
    struct node *temp,*p;
   p=start;
   while(p!=NULL){
         if(p->info==item){
         temp=(struct node*)malloc(sizeof(struct node));
         temp->info=data;
         temp->next=p->next;
         p->next=temp;
         return start;
         }
         p=p->next;

         }
    printf("%d not present in this list\n",item);
    return start;
}



struct node* addbefore(struct node*start,int data ,int item){
    struct node *temp,*p;
  if(start==NULL){
     temp=(struct node*)malloc(sizeof (struct node));
     temp->info=data;
     temp->next=start;
     start=temp;
     return start;
     }
     if(item==start->info){
             temp=(struct node*)malloc(sizeof (struct node));
             temp->info=data;
             temp->next=start;
             start=temp;
             return start;
             }
      p=start;
      while(p->next!=NULL){
        if(p->next->info==item){
             temp=(struct node*)malloc(sizeof (struct node));
             temp->info=data;
             temp->next=p->next;
             p->next=temp;
             return start;
        }
        p=p->next;
      }
}



struct node* addatpos(struct node*start,int data ,int pos){
    struct node*temp,*p;
    int i;
     temp=(struct node*)malloc(sizeof (struct node));
     temp->info=data;
     if(pos==1){
        temp->next=start;
        start=temp;
        return start;
     }
     p=start;
     for(i=1;i<pos-1 && p!=NULL;i++){
        p=p->next;
     }
     if(p==NULL)
        printf("there are less than %d elemnts\n",pos);
     else{
        temp->next=p->next;
        p->next=temp;
     }
     return start;
}


struct node *del(struct node *start,int data){
    struct node *temp,*p;
    if(start==NULL){
        printf("list is empty\n");
        return start;}
        if(start->info==data){
            temp=start;
            start=start->next;
            free(temp);
            return start;
        }
        p=start;
        while(p->next!=NULL){
            if(p->next->info==data)
            {
                temp=p->next;
                p->next=temp->next;
                free(temp);
                return start;

            }
            p=p->next;
        }
        printf("element %d is not found\n",data);
        getch();
        return start;

}


struct node*reverse(struct node *start){
    struct node *prev,*ptr,*link;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL){
            link=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=link;

    }
    start=prev;
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
    start=addatbeg(start,data);
    for(i=2;i<=n;i++){
        printf("enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;



}







