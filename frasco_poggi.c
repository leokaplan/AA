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
    
    if(bit+1 != n)
    {
        printf(" %d %d\n",bit+1,n);
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

