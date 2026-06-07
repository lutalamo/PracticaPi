

int orden (const int * v){
    //me fijo que hayam 2 elementos por lo menos
    if (v[0] == -1 || v[1] == -1) return 0;

    if (v[2] == -1){
        if (v[0] < v[1]) return 1;
        if (v[0] > v[1]) return -1;
        return 0;
    }

    int ordenResto = orden(v+1);

    if (ordenResto == 0) return 0;

    if (ordenResto == 1){
        return v[0] < v[1];
    }
    if (v[0] > v[1]){
        return -1;
    }
    return 0;
}