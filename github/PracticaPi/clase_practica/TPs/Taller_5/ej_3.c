#include <stdio.h>

int inter(int v1[], int dim1, int v2[], int dim2, int ans[]){
    int pos = 0;
    for (int i = 0; i < dim1; i++){
        for(int j = 0; j < dim2; j++){
            if (v1[i] == v2[j]){
                ans[pos] = v1[i];
                pos++;
                break;
            }
        }
    }
    return pos;
}

int main(){
    int v1[6] = {1, 2, 3, 4, 5, 6};
    int v2[4] = {3, 5, 6, 7};
    int ans[6] = {-1, -1, -1, -1, -1, -1};
    inter(v1, 6, v2, 4, ans);
    for(int i = 0; i < 6; i++){
        printf("%d, ", ans[i]);
    }
}