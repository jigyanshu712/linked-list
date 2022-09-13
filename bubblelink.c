#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;
};
void bubble_sort(struct node *start);
int main(){
    int n,data;
    struct node *temp,*p,*start,*q;
    start=NULL;
    printf("enter the number of nodes in  the linked list : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
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
    bubble_sort(start);
    printf("the sorted linked list : \n");

        q=start;
        while(q!=NULL){
            printf("%d\n",q->info);
            q=q->next;
        }
return 0;
}


void  bubble_sort(struct node *start){
    struct node *p,*q,*end;
    for(end=NULL;end!=start->next;end=q){
        for(p=start;p->next!=end;p=p->next){
            q=p->next;
            if(p->info>q->info){
                int temp;
                temp=p->info;
                p->info=q->info;
                q->info=temp;
            }
        }
    }
}
