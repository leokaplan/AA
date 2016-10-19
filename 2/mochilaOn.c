int int_min(int a, int b){
    if(a<b) return a;
    else return b;
}
//mediana das medianas em O(n)
int find_median (int* p,int* v, int n,int* ids) {
    int group_size = 5;
    int* medians = (int*)calloc(n+1,sizeof(int));
    int aux,min,i,j; 
    for (i = 0; i < n; i++) {
        medians[i] = ids[i];
    }
 
    int n_medians = n;
    do {
        int store = 0;

        for (i = 0; i < n_medians; i += group_size) {
            int startIdx = i;
            int endIdx = i + int_min(group_size, n_medians - i);

            for (i = startIdx; i < endIdx; i++) {
                 min = i;
                 for (j = i+1; j < endIdx; j++) {
                   if(v[medians[j]]/p[medians[j]] < v[medians[min]]/p[medians[min]]) 
                     min = j;
                 }
                 if (i != min) {
                   aux = medians[i];
                   medians[i] = medians[min];
                   medians[min] = aux;
                 }
            }
            medians[store++] = medians[(startIdx + endIdx)/2]; 
        } 

        n_medians = store;
    } while(n_medians > 1);

    int id = medians[0];
    free(medians); 
    return id;
}

void mochila(int* p,int* v,int n,int c,int*x,int* ids){
    double peso = 0.0; // peso na mochila
    double valor = 0.0; // valor na mochila
    // caso base, temos uma mochila vazia ou nao temos objetos p pegar 
    if (n == 0 || c == 0) return;

    int i; 
    //acha a mediana entre os objetos em O(n)
    int median = find_median(p,v, n,ids); 
    //particiona os objetos em 3 grupos: densidade de valor menor, igual ou maior que a densidade da mediana 
    int* menor = (int*)calloc(n,sizeof(int));
    int* igual = (int*)calloc(n,sizeof(int));
    int* maior = (int*)calloc(n,sizeof(int));
    int menor_i=0;
    int igual_i=0;
    int maior_i=0;
    int maior_p=0;
    int id;
    for(i=0;i<n;i++){
        id = ids[i];
        if(v[id]/p[id] < v[median]/p[median]) menor[menor_i++] = id;
        if(v[id]/p[id] == v[median]/p[median]) igual[igual_i++] = id;
        if(v[id]/p[id] > v[median]/p[median]) {maior[maior_i++] = id;maior_p +=p[id];}
    }
    //se todos os elementos da parte mais valiosa couberem na mochila, adiciona todos O(n) no "pior caso"(sempre vai ser menor que n)
    if(maior_p < c){
        for(i=0;i<maior_i;i++){
            peso += p[maior[i]];    
            valor += v[maior[i]];
            x[maior[i]]=1.0;    
        }
        //se ainda temos espaco livre na mochila, tentamos preencher com o grupo igual a mediana 
        for(i=0;i<igual_i && peso<=c;i++){
            if(peso+p[igual[i]]<=c){
                peso += p[igual[i]];    
                valor += v[igual[i]];
                x[igual[i]]=1.0;    
            }
            else{
                x[igual[i]] = (c - peso)/(double)p[igual[i]];
                valor += ((double) v[igual[i]]) * x[igual[i]]; 
            }
        }
        //adicionamos o grupo inferior dividindo o problema em 2: f(n/2)
        mochila(p,v,menor_i,c,x,menor);
    }
    //se a parte maior nao cabe completamente,reduzimos nosso problema somente a parte maior, nem considerando o resto dos objetos: f(n/2)
    else{
        mochila(p,v,maior_i,c,x,maior);
    }
    free(menor);
    free(igual);
    free(maior);

}

