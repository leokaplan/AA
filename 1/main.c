#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "bin.c"
#define debug 1


char input_degrau[256];
long int test[10], degrau[10];

int frasco(int n, int k)
{
    int i,j,t,bit;
    int cont, pot, dg;

    bit = 0;
    pot = n/k;
    
    for(i=0; i<k; i++)
    {
        degrau[i] = 0;
        t = 1;
        for(j=0; j<pot; j++)
        {
            if(input_degrau[bit] == '1')
            {
                degrau[i] += t;
            }
            t *= 2;
            bit++;
        }
    }
    
        
    
    cont = pow(2,pot);
    
    for(j=k-1; j>=0; j--)
    {
        dg = 0;
        for(i=0; i<cont; i++)
        {
            dg++;
            if(dg > degrau[j])
            {
                test[k] = dg-1;
                break;
            }
        }
        
    }
    return(1);
}


int count_time(int (*f)(int,int),int numfrascos,int altura_max){
    double timer = 0.0;
    int count = 0;
    double c;
    struct timespec max_wait;
    while(timer<0.5){
        c=clock();
        f(altura_max,numfrascos);
        timer += (clock()-c)/CLOCKS_PER_SEC;
        count++;
    }
    return count;
}
void run(char* s,int k){
    int nbits,n,i;
    char o[100];
    sprintf(o, "%s%d", s,k);
    char* in;
    FILE* f = fopen(s,"r");
    FILE* f2 = fopen(o,"w");
    fscanf(f,"%d %d",&nbits,&n);
    fprintf(f2,"%d %d %d\n",nbits,n,k);
    in = (char*)malloc(sizeof(char)*nbits);
    for(i=0;i<n;i++){
        printf("%d/%d\n",i,n);
        fscanf(f,"%s", input_degrau);
        fprintf(f2,"%d\n",count_time(frasco,k,nbits));
    }
    fclose(f);
    fclose(f2);
}

int main(){
    int k;
    for (k = 2;k<=16;k*=2){
        printf("%d\n",k);
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
    

    return 0;
}
