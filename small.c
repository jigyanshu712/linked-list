#include<stdio.h>
#include<stdlib.h>
struct node {
int info;
struct node *next;
};
struct node *dis(struct node *start);
int main(){
    int n,data,i,j;
    struct node *temp,*p,*start,*r,*s;
    start=NULL;
    printf("enter the number of nodes to be inserted : ");
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
    r=dis(start);
    j=start->info;
    start->info=r->info;
    r->info=j;
    s=start;
    printf("the smallest element in the begining : \n");

    while(s!=NULL){
        printf("%d\n",s->info);
        s=s->next;
    }


return 0;
}

 struct node *dis(struct node *start){
    struct node *q,*p;
    int temp;
    temp=start->info;
    p=start->next;
    q=start;
    while(p!=NULL){
            if(p->info<temp){
            temp=p->info;
            q=p;
        }
        p=p->next;
    }
    return q;


}

