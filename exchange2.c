#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;
};
int main(){
int i,n,data;
struct node *temp,*p,*start,*q;
start=NULL;
printf("enter the no. of nodes in the list : ");
scanf("%d",&n);
for(i=1;i<=n;i++){
    printf("enter the %d element : ",i);
    scanf("%d",&data);
    temp=(struct node*)malloc(sizeof(struct node));
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
        temp->next=start->next;
        p->next=start;
        start->next=NULL;
        start=temp;


printf("the list is : \n");
p=start;
while(p!=NULL){
    printf("%d\n",p->info);
    p=p->next;
}

return 0;
}
