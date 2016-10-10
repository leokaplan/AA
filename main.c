#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "frasco_poggi.c"



int count_time(int (*f)(int,int),int numfrascos,int altura){
    double timer = 0.0;
    int count = 0;
    double c;
    while(timer<2.0){
        c=clock();
        f(numfrascos,altura);
        timer += (clock()-c)/CLOCKS_PER_SEC;
        count++;
    }
    return count;
}


void run(char* s){
    int m,n,i,in;
    FILE* f = fopen(s,"r");
    fscanf(f,"%d %d",&m,&n);
    printf("%d",m);
    for(i=0;i<n;i++){
        fscanf(f,"%d", &in);
        printf("%d",count_time(frasco,m,in));
    }
    fclose(f);
}

int main(){
    //for arquivo in arquivos 
    run("arq1.in");
    

    return 0;
}
