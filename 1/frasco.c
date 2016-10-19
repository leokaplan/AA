
int frasco(int k,int n, char* altura){
    double min = 0;
    long double max = pow(2.0,n);
    double d = max-min;
    double s = pow(d,1.0/k);
    long long int i,j; 
    long long int x = strtoll(altura,0,2);
    /* 
    char* _max = calloc(n,sizeof(char));
    _max[n-1] = '1';
    char* _s = calloc(n,sizeof(char));
    _s[(n-1)/k] = '1';
    char* it = calloc(n,sizeof(char));
    char* jt = calloc(n,sizeof(char));
    char* one = calloc(n,sizeof(char));
    one[0]='1';
    */
    //numero de frascos disponiveis
    int bot = k;
    //printf("%lf %lf %lf\n",x/s,d,s );
    //comecando em 0 e andando em s 
    for(i=0;i<=max;i+=s){
    //for(;cmp(it,_max,n)<=0;it=add(it,_s,n)){
        //se quebrou
        //printf("%lld %lld %lld %lf\n",i,x-i,x,s);
        if(x-i<s){
        //if(cmp(altura,add(it,_s,n),n)<0){
            //se so sobrou um frasco
            if(bot == 1){
                //busca linear entre i-s e i
                for(j = i;j<=i+s;j++){
                /*
                zero(jt,n);
                jt = add(jt,it,n);

                for(;cmp(jt,add(it,_s,n),n)<=0;jt=add(jt,one,n)){
                */
                    if(j >= x){
                    //if(cmp(jt,altura,n)>=0){
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
