
#define index(bit_pos, base) ((int) bit_pos/base)
#define bit_select(value, bit_pos, base) (int)((value[index(bit_pos,base)]>>bit_pos%base) & 1)
#define bit_set(value,bit_pos,base, bit) value[index(bit_pos,base)] ^= (-bit ^value[index(bit_pos,base)]) & (1<<(bit_pos%base))



int cmp(char * a, char *b, int n){
    int bit_pos,sum;

    for(bit_pos=n-1;bit_pos>=0;bit_pos--){

        sum = bit_select(a,bit_pos,2) - bit_select(b,bit_pos,2);

        if(sum != 0)
            return sum;
    }
    return sum;
}

int zero(char*a,int n){
    int i;
    for(i=0;i<n-1;i++){
        a[i]='0';
    }
}
char* add(char* a, char* b, int n){
    int bit_pos,sum;
    int carry = 0;
    char* r = calloc(n,sizeof(char));
    for(bit_pos=n-1;bit_pos>=0;bit_pos--){

        sum = bit_select(a,bit_pos,2) + bit_select(b,bit_pos,2);
        if(carry) sum += carry;
        if(sum == 2){
            r[bit_pos]='0';
            carry = 1;
        }
        else{
            r[bit_pos] = '0'+sum;
        }
    }
    return r;
    
}

