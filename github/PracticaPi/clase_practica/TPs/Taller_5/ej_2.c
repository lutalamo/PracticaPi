#include <stdio.h>

int dondeEsta(int v[], int dim, int n, int ans[]){
    int j;
    for(int i = 0; i < dim; i++){
        if ( v[i] == n ){
            ans[j] = i; 
            j++;
        }
    }
    return j;
}

int main(){
    int v[6] = {1, 2, 3, 5, 2, 2};
    int ans[6]; 
    dondeEsta(v, 6, 2, ans);
    for ( int i = 0; i < 6; i++){
        ans[i] = 0;
    }
    

}