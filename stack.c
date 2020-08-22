#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *top=NULL;
node* tao_node(int n){
    node *p=(node*)malloc(sizeof(node));
    if(p==NULL) return NULL;
    p->data= n;
    p->next=NULL;
    return p;
}
void push(int n){
    node *p=tao_node(n);
    if(top==NULL){
        top=p;
    }
    else{
        p->next=top;
        top=p;
    }
}
int pop(){
    if (top == NULL){
        return -1;
    }
    else {
        int n = top->data;
        node* del = top;
        top = top->next;
        free(del);
        return n;
    }
}
void doiCoSo(int n, int coso){
    while(n>0){
        push(n%coso);
        n/=coso;
    }
}
void hienthi(){
    while(top!=NULL){
        printf("%d", pop());
    }
    printf("\n");
}
void menu(){
    printf("\t\tMENU\n");
    printf("\t1. Chuyen sang he 2\n");
    printf("\t2. Chuyen sang he 8\n");
    printf("\t3. Chuyen sang he 16\n");
    printf("\t0. Exit\n");
    printf("\t\tVui long chon: ");
}

int main(){
    int chon, n;
    while (1){
        menu();
        scanf("%d",&chon);
        system("cls");

        switch(chon){
            case 1:
                printf("\tBan da chon chuyen he co so 2\n");
                printf("\tNhap so thap phan: ");
                scanf("%d",&n);
                doiCoSo(n,2);
                printf("So he co so 2 la: ");
                hienthi();
                break;
            case 2:
                printf("\tBan da chon chuyen he co so 8\n");
                printf("\tNhap so thap phan: ");
                scanf("%d",&n);
                doiCoSo(n,8);
                printf("So he co so 8 la: ");
                hienthi();
                break;
            case 3:
                printf("\tBan da chon chuyen he co so 16\n");
                printf("\tNhap so thap phan: ");
                scanf("%d",&n);
                printf("So he co so 16 la: ");
                printf("%x\n",n);
                break;
            case 0:
                exit(0);
            default:
                printf("\tChi nhap 0-3\n");
        }
        printf("\tBam phim bat ky de ve menu");
        getch();
        system("cls");
    }
}
