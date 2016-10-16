#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define debug 1

int frasco(int k,int n, char* altura){
    double min = 0;
    double max = pow(2.0,n);
    long long int x = strtoll(altura,0,2);
    double d = max-min;
    double s = pow(d,1.0/k);
    double pivot = s*s/2;
    long long int i,j; 
    //numero de frascos disponiveis
    int bot = k;
    //printf("%lf %lf %lf\n",x/s,d,s );
    //comecando em 0 e andando em s 
    for(i=0;i<=max;i+=s){
        //se quebrou
        //printf("%lld %lld %lld %lf\n",i,x-i,x,s);
        if(x-i<s){
            //se so sobrou um frasco
            if(bot == 1){
                //busca linear entre i-s e i
                for(j = i;j<=i+s;j++){
                    if(j >= x){
                        return 1;
                    } 
                }
            }
            else{
                //volta um passo e
                i = i - s;
                if(i<0) i = 0;
                //divide o intervalo em subintervalos
                s = pow(s,1.0/k);
                //um frasco quebrou
                bot--;
            }
        }
        //se nao quebrou continua
    }
} 


int count_time(int (*f)(int,int,char*),int numfrascos,int altura_max, char* altura){
    double timer = 0.0;
    int count = 0;
    double c;
    while(timer<1.0){
        c=clock();
        f(numfrascos,altura_max,altura);
        timer += (clock()-c)/CLOCKS_PER_SEC;
        count++;
    }
    return count;
}
void run(char* s,int k){
    int nbits,n,i;
    char* in;
    FILE* f = fopen(s,"r");
    fscanf(f,"%d %d",&nbits,&n);
    printf("%d %d %d\n",nbits,n,k);
    in = (char*)malloc(sizeof(char)*nbits);
    for(i=0;i<n;i++){
        fscanf(f,"%s", in);
        printf("%d\n",count_time(frasco,k,nbits,in));
    }
    fclose(f);
}

int main(){
    int k;
    for (k = 2;k<64;k+=2){
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
