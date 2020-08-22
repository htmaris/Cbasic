#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int a[row][col];
    int index=0;
    int hang1=0;
    int hang_cuoi=row-1;
    int cot_trai=0;
    int cot_phai= col-1;
    int i, j, k,h;
    while(index<= row*col)
    {
        for(i= cot_trai; i<= cot_phai; i++ )
        {
            index++;
            a[hang1][i]= index;
        }
        hang1++;
        if (index >= row * col) {
          break;
        }
        for(j=hang1; j<= hang_cuoi; j++ )
        {
            index++;
            a[j][cot_phai]= index;
        }
        if (index >= row * col) {
          break;
        }
        cot_phai--;
        for(k= cot_phai; k>= cot_trai; k-- )
        {
            index++;
            a[hang_cuoi][k]= index;
        }
        if (index >= row * col) {
          break;
        }
        hang_cuoi--;
        for(h= hang_cuoi; h>=hang1; h--)
        {
            index++;
            a[h][cot_trai]=index;
        }
        if (index >= row * col) {
          break;
        }
        cot_trai++;
    }
    for(int i=0; i< row; i++)
    {
        for(int j=0; j<col; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
    return 0;
}
