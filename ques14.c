#include<stdio.h>
#include<stdlib.h>
struct node {
int info;
struct node *next;
};
int main(){
 int i,n,data;
 struct node *temp,*p,*start;
 start=NULL;
 printf("enter the number of nodes to be inserted : ");
 scanf("%d",&n);
 for(i=1;i<=n;i++){
    printf("enter the %d element : ",i);
    scanf("%d",&data);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL){
        temp->next=start;
        start=temp;
    }
    else{
        p=start;
        while(p->next!=NULL)
        p=p->next;
        temp->next=p->next;
        p->next=temp;
    }
 }
    p->next=NULL;
    temp->next=start;
    start=temp;
    printf("the list is : \n");
    p=start;
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
return 0;

 }

