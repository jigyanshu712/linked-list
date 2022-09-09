#include<stdio.h>
#include<stdlib.h>
struct node{int info;
struct node *next;
};
void count(struct node*,int);
int main(){
    int n,i,data,t;
    struct node *temp,*start,*p;
    start=NULL;
    printf("enter the number of nodes  : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("enter the %d element : ",i);
        scanf("%d",&data);
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        if(start==NULL){
            start=temp;
            temp->next=NULL;
        }
        else{
            p=start;
            while(p->next!=NULL)
            p=p->next;
            p->next=temp;
            temp->next=NULL;
        }
    }
    printf("enter the element which we want to check the occurence : ");
    scanf("%d",&t);
    count(start,t);
return 0;
}


void count(struct node *start,int data){
    struct node *p;
    int count=0;
    p=start;
    while(p!=NULL){
        if(p->info==data)
        {
            count++;
        }
        p=p->next;
    }
    if(count==0)
        printf("%d element is not present",data);
    else
        printf("%d element occur in %d times",data,count);


}
