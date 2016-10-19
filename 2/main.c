#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define debug 1
#include "mochilaOn_densidade.c"




int count_time(void (*f)(int*,int*,int,int,int*,int*),int* p,int* v,int n, int cap,int*x,int*ids){
    double timer = 0.0;
    int count = 0;
    double c;
    while(timer<1.0){
        c=clock();
        f(p,v,n,cap,x,ids);
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
    int* v = (int*)calloc(n,sizeof(int));
    int* p = (int*)calloc(n,sizeof(int));
    int* x = (int*)calloc(n,sizeof(int));
    int* ids = (int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        int a,b,c;
        fscanf(f,"%d %d %d\n",&a,&b,&c);
        v[a-1] = b;
        p[a-1] = c;
        ids[i]=i;
    }
    int cap;
    fscanf(f,"%d",&cap);
    printf("%d %d\n",n,count_time(mochila,p,v,n,cap,x,ids));
    fclose(f);
    free(v);
    free(p);
    free(x);
    free(ids);
}

int main(){
    run("data/m50.in");
    run("data/m106.in");
    run("data/m1096.in");
    run("data/m124.in");
    run("data/m11519.in");
    run("data/m1282.in");
    run("data/m103741.in");
    run("data/m13477.in");
    run("data/m145.in");
    run("data/m1499.in");
    run("data/m15768.in");
    run("data/m169.in");
    run("data/m1753.in");
    run("data/m18448.in");
    run("data/m197.in");
    run("data/m2051.in");
    run("data/m21584.in");
    run("data/m230.in");
    run("data/m2399.in");
    run("data/m25253.in");
    run("data/m269.in");
    run("data/m2806.in");
    run("data/m29546.in");
    run("data/m314.in");
    run("data/m3283.in");
    run("data/m34568.in");
    run("data/m367.in");
    run("data/m3841.in");
    run("data/m40444.in");
    run("data/m429.in");
    run("data/m4493.in");
    run("data/m47319.in");
    run("data/m501.in");
    run("data/m5256.in");
    run("data/m55363.in");
    run("data/m58.in");
    run("data/m586.in");
    run("data/m6149.in");
    run("data/m64774.in");
    run("data/m67.in");
    run("data/m685.in");
    run("data/m7194.in");
    run("data/m75785.in");
    run("data/m78.in");
    run("data/m801.in");
    run("data/m8416.in");
    run("data/m88668.in");
    run("data/m91.in");
    run("data/m937.in");
    run("data/m9846.in");
    return 0;
}
