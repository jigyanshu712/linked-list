#include<stdio.h>
#include<stdlib.h>
struct node {
    float coef;
    int expo;
    struct node *link;

};
struct node *create(struct node *);
struct node *insert_s(struct node *,float,int);
struct node *insert(struct node *,float,int);
void display(struct node *ptr);
void poly_add(struct  node *,struct node *);
void poly_mult(struct node *,struct node *);
int main(){
    struct node *start1=NULL,*start2=NULL;
    printf("enter polynomial 1 :\n");
    start1=create(start1);
    printf("enter polynomial 2 :\n");
    start2=create(start2);
    printf("polynomial 1 is :  ");
    display(start1);
    printf("enter polynomial 2 is :  ");
    display(start2);
    poly_add(start1,start2);
    poly_mult(start1,start2);

return 0;
}

struct node *create(struct node *start){
    int i,n,ex;
    float co;
    printf("enter the number of terms :  ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("enter coefficient for term %d : ",i);
        scanf("%f",&co);
        printf("enter exponent for term %d :  ",i);
        scanf("%d",&ex);
        start=insert_s(start,co,ex);
    }
    return start;
}

struct node *insert_s(struct node *start,float co,int ex){
    struct node *ptr,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=co;
    temp->expo=ex;
    if(start==NULL || ex>start->expo){
        temp->link=start;
        start=temp;
    }
    else{
        ptr=start;
        while(ptr->link!=NULL && ptr->link->expo>=ex){
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;

    }
    return start;
}

struct node *insert(struct node *start,float co,int ex){
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=co;
    temp->expo=ex;
    if(start==NULL){
        temp->link=start;
        start=temp;
    }
    else{
        ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;
            temp->link=ptr->link;
            ptr->link=temp;

    }
    return start;

}


void display(struct node *ptr){
    if(ptr==NULL){
       printf("zero polynomial\n");
       return;
              }
    while(ptr!=NULL){
        printf("(%.1fx^%d)",ptr->coef,ptr->expo);
        ptr=ptr->link;
        if(ptr!=NULL)
            printf(" + ");
        else
            printf("\n");
    }

}


void poly_add(struct node *p1,struct node *p2){
struct node *start3;
start3=NULL;
while(p1!=NULL && p2!=NULL){
    if(p1->expo >p2->expo){
        start3=insert(start3,p1->coef,p1->expo);
        p1=p1->link;
    }
    else if(p2->expo > p1->expo){
        start3=insert(start3,p1->coef,p2->expo);
        p2=p2->link;
    }
    else if(p1->expo ==p2->expo){
        start3=insert(start3,p1->coef+p2->coef,p1->expo);

    p1=p1->link;
    p2=p2->link;
    }
}
while(p1!=NULL){
    start3=insert(start3,p1->coef,p1->expo);
    p1=p1->link;
}
while(p2!=NULL){
    start3=insert(start3,p2->coef,p2->expo);
    p2=p2->link;
}
printf("added polynomial is : ");
display(start3);
}

void poly_mult(struct node *p1,struct node *p2){
    struct node *start3;
    struct node *p2_beg=p2;
    start3=NULL;
    if(p1==NULL || p2==NULL){
        printf("Multiplied polynomial is zero polynomial\n");
        return;
    }

    while(p1!=NULL){
        p2=p2_beg;
        while(p2!=NULL){
            start3=insert_s(start3,p1->coef*p2->coef,p1->expo+p2->expo);
            p2=p2->link;
        }
        p1=p1->link;
    }
    printf("Multiplied polynomial is : ");
    display(start3);
}






























