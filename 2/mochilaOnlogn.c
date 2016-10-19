void quick(int p[],int v[], int esq, int dir){
    int pivot = esq;
    int i,_v,_p,j; 
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(v[j]/p[j] < v[pivot]/p[pivot]){     
            _v = v[j];              
            _p = p[j];              
            while(j > pivot){         
                v[j] = v[j-1];
                p[j] = p[j-1];
                j--;             
            }
            v[j] = _v;       
            p[j] = _p;       
            pivot++;          
        }  
    }
    if(pivot-1 >= esq){      
        quick(p,v,esq,pivot-1);
    }
    if(pivot+1 <= dir){       
        quick(p,v,pivot+1,dir);
    }
}

//guloso O(nlogn)
void mochila(int* p,int* v,int n,int c,int*x,int*ids){
    double peso = 0.0; // peso na mochila
    double valor = 0.0; // valor na mochila
    int i;
 
    // Ordena os objetos com relacao a razao entre valor/peso em O(n*log(n))
    quick(p,v,0, n-1);
    // Coloca o maior numero de objetos de forma completa na mochila,
    // em ordem de razao valor/peso em O(n)
    for(i=0; i<n; i++){
        // Case nao seja possivel colocar o objeto atual na mochila, 
        // entao sai do laco
        if(p[i] + peso > c) break; 
 
        x[i] = 1.0; // Coloca todo o objeto i na mochila
        valor += v[i]; // Atualiza o valor total na mochila
        peso += p[i]; // Atualiza o peso total na mochila
    }
 
    // Se nem todos os objetos couberam na mochila,
    // coloca apenas uma fracao do melhor objeto, em termos de valor/peso, 
    // ainda nao considerado
    if(i < n){
         // Coloca apenas a fracao possivel do objeto i na mochila
        x[i] = (c - peso)/(double)p[i];
        // Atualiza o valor total da mochila
        valor += ((double) v[i]) * x[i]; 
    }
 
}
