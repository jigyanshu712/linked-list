#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next
};
void find(struct node *);

int main(){
    int i,n,data;
    struct node *start,*temp,*p;
    start=NULL;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("enter the %d element : ",i);
        scanf("%d",&data);
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        if(start==NULL)
        {
            start=temp;
            temp->next=NULL;
        }
        else
        {
            p=start;
            while(p->next!=NULL)
                p=p->next;
            p->next=temp;
            temp->next=NULL;
        }

    }
    find(start);
return 0;
}



void find(struct node *start){
int max,min;
struct node *p;
max=start->info;
min=start->info;
p=start;
while(p!=NULL){
    if(max<p->info){
            max=p->info;

    }

    if(min>p->info)
        min=p->info;

    p=p->next;


}
if(min==max)
    printf("the largest and smallest element is %d",max);
else
printf("the largest and smallest element is %d and %d",max,min);
}
