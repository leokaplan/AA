#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define debug 1

int* mochila(int* p,int* v,int n,int c){
    int* x = (int*)malloc(sizeof(int)*n);
    int j;
    for (j = n;j>0;j--){
        if(p[j] <=c){
            x[j] =1;
            c = c-p[j];
        }
        else{
            x[j] = c/p[j];
            c = 0;
        }
    }
    return x;
}


int count_time(int* (*f)(int*,int*,int,int),int* p,int* v,int n, int cap){
    double timer = 0.0;
    int count = 0;
    double c;
    while(timer<1.0){
        c=clock();
        f(p,v,n,cap);
        timer += (clock()-c)/CLOCKS_PER_SEC;
        count++;
    }
    return count;
}
void run(char* s){
    int nbits,n,i;
    char* in;
    FILE* f = fopen(s,"r");
    fscanf(f,"%d",&n);
    int* v = (int*)malloc(sizeof(int)*n);
    int* p = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        int a,b,c;
        fscanf(f,"%d %d %d\n",&a,&b,&c);
        v[a] = b;
        p[a] = c;
    }
    int cap;
    fscanf(f,"%d",&cap);
    printf("%d\n",count_time(mochila,p,v,n,cap));
    fclose(f);
}

int main(){
    run("data/m106.in");
    /*
    int k;
    for (k = 2;k<64;k*=2){
        run("data/bignum_32_01.dat",k);
        run("data/bignum_32_02.dat",k);
        run("data/bignum_64_01.dat",k);
        run("data/bignum_64_02.dat",k);
        run("data/bignum_128_01.dat",k);
        run("data/bignum_128_02.dat",k);
        run("data/bignum_192_01.dat",k);
        run("data/bignum_192_02.dat",k);
        run("data/bignum_256_01.dat",k);
        run("data/bignum_256_02.dat",k);
    }
    
    */
    return 0;
}
