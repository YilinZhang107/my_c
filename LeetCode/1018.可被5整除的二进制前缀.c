bool* prefixsDivBy5(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    bool *b = malloc(sizeof(bool)*ASize);
    int num= 0;
    for(int i=0; i<ASize; i++){
        num *=2;
        num += A[i];
        num = num%10;
        b[i] = (num%5==0);
    }
    return b;
}