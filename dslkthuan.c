#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhvien
{
    char name[30];
    int age;
    float avg;
} sinhvien;
typedef struct Tnode
{
    sinhvien data;
    struct Tnode *next;
} Tnode;
typedef struct List
{
    Tnode *first, *last;
} List;
void init(List *l)
{
    l->first=l->last=NULL;
}
Tnode* create_node(sinhvien *sv)
{
    Tnode *p;
    p= (Tnode* )malloc(sizeof(Tnode));
    if(p==NULL)
        return NULL;
    p->data= *sv;
    p->next=NULL;
    return p;
}
void scan_sv(sinhvien *sv)
{
    printf("Nhap ho ten sinh vien: ");
    fflush(stdin);
    gets(sv->name);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->age);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->avg);
}
void print_sv(sinhvien *sv)
{
    printf("|%30s|%5d|%4.1f|\n", sv->name, sv->age, sv->avg);
}
void add(List *l, sinhvien *sv)
{
    Tnode *p;
    scan_sv(sv);
    p=create_node(sv);
    if(l->first==NULL)
    {
        l->first=l->last=p;
    }
    else
    {
        l->last->next=p;
        l->last=p;
    }
    p->next=NULL;

}

void scan_list(List *l, sinhvien *sv)
{
    int n;
    printf("Nhap vao so sinh vien: ");
    scanf("%d", &n);
    init(l);
    for(int i=0; i<n; i++)
    {
        printf("\nNhap sinh vien thu %d\n", i+1);
        add(l,sv);
    }
}
void print_list(List *l, sinhvien sv)
{
    Tnode *k;
    printf("|%4s|%30s|%5s|%4s|\n", "STT", "Ho va ten", "Tuoi", "Avg");
    int i=1;
    for(k=l->first; k!=NULL; k=k->next)
    {
        printf("|%4d|%30s|%5d|%4.1f|\n", i, k->data.name, k->data.age, k->data.avg);
        i++;
    }
}
void insert_sv(List *l, sinhvien sv){
    Tnode *p,*k;
    p=(Tnode*)malloc(sizeof(Tnode));
    char ht[20];
    printf("\n Nhap sinh vien can chen: ");
    scan_sv(&sv);
    p=create_node(&sv);
    printf("\nMuon chen sau sinh vien nao: ");
    fflush(stdin);
    gets(ht);
    k=l->first;
    while (k!=NULL && strcmp(k->data.name,ht)!=0)
    {
        k=k->next;
    }
    if (k==NULL)
        printf("\nKhong tim thay");
    else
    {
        if (k->next==NULL)
            k->next=p;
        else
        {
            p->next=k->next;
            k->next=p;
        }
        printf("\n da chen xong\n");
    }

}
void delete_node(List *l)
{
    char ht[20];
    printf("\nNhap hoten can xoa: ");
    fflush(stdin);
    gets(ht);
    Tnode *k;
    Tnode *p;
    k=l->first;
    while (k!=NULL &&strcmp(k->data.name,ht)!=0)
    {
        p=k;
        k=k->next;
    }
    if (k==NULL)
        printf("\n khong tim thay phan tu can xoa\n");
    else
    {
        //nếu phân tủ cần xóa ở đàu hoặc cuối
        if (k->	next ==NULL){
            p->next =NULL;

        }
        else if (k==l->	first ){
            l->first =k->next ;
        }
            //nếu phần tử cần xóa nằm ở giữa.đi đến phần tử đứng trước phần tử cần xóa, lưu địa chỉ k, cho k->next lưu giữ ptu của pt đứng sau
        else{
            p->next =k->next ;
        }
        free(k);
        printf("\nda xoa xong\n");
    }
}
void edit_sv(List *l, sinhvien sv){
    char ht[20];
    printf("Nhap sinh vien can sua: ");
    fflush(stdin);
    gets(ht);
    Tnode *k, *p, *q;
     printf("Nhap thong tin sinh vien de sua: \n");
     scan_sv(&sv);
    q=create_node(&sv);
    k=l->first;
    while(k!=NULL && strcmp(k->data.name, ht)!=0){
        p=k;
        k=k->next;
    }
    if(k==NULL){
        printf("Khong tim thay phan tu can sua!");
    }
    else
    if(k->next==NULL){
        p->next=q;
        q->next= NULL;
    }
    else if(k==l->first){
        q->next=k->next;
        l->first=q;
    }
    else{
        q->next=k->next;
        p->next=q;
    }
    print_list(l, sv);

}
int main()
{
    List l;
    sinhvien sv;
    printf("MENU\n1) Tao danh sach sinh vien\n2) Hien thi\n3) Chen sinh vien\n4) Xoa sinh vien\n5)Sua sinh vien\n6) Ket thuc");
    int chon;
    do{
            printf("\nChon cong viec ban muon: ");
    scanf("%d", &chon);
    switch(chon){
        case 1:
    scan_list(&l,&sv);
    break;
    case 2:
    print_list(&l, sv);
    break;
    case 3:
    insert_sv(&l, sv);
    print_list(&l, sv);
    break;
    case 4:
    delete_node(&l);
    print_list(&l, sv);
    break;
    case 5:
        edit_sv(&l, sv);
        break;
    }
    }while(chon!=6);
    return 0;
}
