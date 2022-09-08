#include<stdio.h>
#include<stdlib.h>
struct node {
int info;
struct node *next;
};
void selection(struct node *start);
int main(){
    int n,data;
    struct node *temp,*start,*p;
    start=NULL;
    printf("enter the number of element in the list : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("enter the %d element : ",i);
        scanf("%d",&data);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        if(start==NULL){
            start=temp;
            temp->next=NULL;
        }
        else{
                p=start;
                while(p->next!=NULL){
                    p=p->next;
                }
                p->next=temp;
                temp->next=NULL;


        }
    }
      selection(start);
    printf("the sorted list is : \n");
    p=start;
    while(p!=NULL){
       printf("%d\n",p->info);
       p=p->next;
    }

return 0;
}
void selection(struct node *start){
struct node *p,*q;
int temp;
for(p=start;p->next!=NULL;p=p->next){
    for(q=p->next;q!=NULL;q=q->next){
        if(p->info>q->info){
            temp=p->info;
            p->info=q->info;
            q->info=temp;
        }

    }
}

}
