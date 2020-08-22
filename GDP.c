#include<stdio.h>
#include<conio.h>
int main (){
     int nam =2014;
    float GDP,GDP_2014;
    float toc_do_tang_truong;
    printf("Nhap GDP nam 2014: ");
    scanf("%f",&GDP_2014);
    GDP = GDP_2014;
    printf("Nhap toc do tang truong (%%): ");
    scanf("%f",&toc_do_tang_truong);
    printf("%8s%8s\n","Nam","GDP");
    while (GDP<=2*GDP_2014)
    {
        printf("%8d%8.1f\n",nam,GDP);
        nam++;
        GDP*=toc_do_tang_truong;

    }
    return 0;
}
