#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *link;
};
struct node *create(struct node *start);
struct node *insert_s(struct node *start,int data);
struct node *insert(struct node *start,int data);
void display(struct node *start);
void merge(struct node *p1,struct node *p2);
int main(){
    struct node *start1=NULL,*start2=NULL;
    start1=create(start1);
    start2=create(start2);
    printf("list 1 : \n");
    display(start1);
    printf("list 2 : \n");
    display(start2);
    merge(start1,start2);
return 0;
}

struct node *create(struct node *start){
    int i,n,data;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    for(i=1;i<=n;i++){
        printf("enter the %d element : ",i);
        scanf("%d",&data);
        start=insert_s(start,data);
    }
    return start;
}


struct node *insert_s(struct node *start,int data){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL || data<=start->info){
        temp->link=start;
        start=temp;
        return start;
    }
    else
    {
        p=start;
        while(p->link!=NULL && p->link->info<data){
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
    }
    return start;
}


struct node *insert(struct node *start,int data){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL){
        temp->link=start;
        start=temp;
        return start;
    }
    else
    {

        p=start;
        while(p->link!=NULL){
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
    }
    return start;

}


void display( struct node *start){
    struct node *p;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    p=start;
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->link;
    }
    printf("\n");
}


void merge(struct node *p1,struct node *p2){
struct node *start3;
start3=NULL;
while(p1!=NULL && p2!=NULL){
    if(p1->info<p2->info){
        start3=insert(start3,p1->info);
        p1=p1->link;
    }
    else if(p2->info <p1->info){
        start3=insert(start3,p2->info);
        p2=p2->link;
    }
    else if(p1->info==p2->info){
        start3=insert(start3,p1->info);
        p1=p1->link;
        p2=p2->link;
    }

}
while(p1!=NULL){
    start3=insert(start3,p1->info);
    p1=p1->link;
}
while(p2!=NULL){
    start3=insert(start3,p2->info);
    p2=p2->link;
}
printf("merged list is :  \n");
display(start3);
}
