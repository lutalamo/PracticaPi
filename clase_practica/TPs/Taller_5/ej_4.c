#include <stdio.h>

int inter(int v1[], int dim1, int v2[], int dim2, int ans[]){
    int i = 0, j = 0, k = 0;
    while (i < dim1 && j < dim2)
        if (v1[i] < v2[j]){
            i++;
        }
        else if (v2[j] < v1[i]){
            j++;
        }
        else {                      
            ans[k++] = v1[i++];  
            j++;
        }
    return k; // cantidad escrita en ans
}

int main(){
    int v1[6] = {1, 3, 7, 9, 14, 18};
    int v2[4] = {2, 3, 9, 18};
    int ans[6] = {-1, -1, -1, -1, -1, -1};
    int k = inter(v1, 6, v2, 4, ans);
    for(int i = 0; i < 6; i++){
        printf("%d, ", k);
    }
}
