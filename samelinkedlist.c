#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;
};
void iden(struct node *start1,struct node *start2,int n1,int n2);
int main(){
    int n1,n2,i,data;
    struct node *start1,*start2,*temp,*p,*q;
    start1=NULL;
    start2=NULL;
    printf("enter the number of elements in list 1 : ");
    scanf("%d",&n1);
    for(i=1;i<=n1;i++){
         printf("enter the %d element : ",i);
         scanf("%d",&data);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        if(start1==NULL){
            start1=temp;
            temp->next=NULL;
        }
        else{
                p=start1;
        while(p->next!=NULL){
                p=p->next;

        }
        p->next=temp;
        temp->next=NULL;
        }
        }



    printf("enter the number of elements in list 2 : ");
    scanf("%d",&n2);
    for(i=1;i<=n2;i++){
         printf("enter the %d element : ",i);
         scanf("%d",&data);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        if(start2==NULL){
            start2=temp;
            temp->next=NULL;
        }
        else{
                q=start2;
        while(q->next!=NULL){
                q=q->next;

        }
        q->next=temp;
        temp->next=NULL;
        }
        }
        iden(start1,start2,n1,n2);

return 0;
}










void iden(struct node *start1,struct node *start2, int n1,int n2){
    int count=0;
    struct node *p,*q;
    p=start1;
    q=start2;
    while(p!=NULL && q!=NULL){
        if(n1==n2){
            if(p->info==q->info){
                count++;
            }
        }
        p=p->next;
        q=q->next;

    }

    if(count==n1&&n2==n1 ){
        printf("\n\nboth list are same\n");
    }
    else{
        printf("\n\nboth list are not same");
    }
}
