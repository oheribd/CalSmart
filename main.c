#include <stdio.h>
#include <stdlib.h>
void CalTotal (int a[5][4],float *p)
{
    float Total,m,e,r,k;
    int c,d;
    for(c=0; c<5; c++)
    {
        for(d=0; d<4; d++)
        {
            if(d==0)
                m=a[c][d]*0.3;
            if(d==1)
                e=a[c][d]*0.3;
            if(d==2)
                r=a[c][d]*0.3;
            if(d==3)
                k=a[c][d]*0.1;
        }
        p[c]=m+e+r+k;

    }
}
void Check (int a[5][4],int *q)
{
    int i,j,k,o;
    for(i=0;i<5;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
            if(a[i][j]>=30)
            {
               o=1;
               k=k+o;
            }
            else
                o=0;
        }
        q[i]=k;
    }

}

int main()
{
    int M,E,R,K,i,k,imax,imin;
    int a[5][4],c[5];
    float T[5];
    float max=-36767,min=36768;
    char Y;
    do
    {
        M=101;
        E=101;
        R=101;
        K=101;
        printf("Enter Score\n");

        for(i=0; i<5; i++)
        {
            printf("People %d\n",i+1);
            for(k=0; k<4; k++)
            {

                if(k==0)
                {
                    printf("Math: ");
                    while(M>100||M<0)
                    {
                        scanf("%d",&M);
                        if(M>100||M<0)
                            printf("Try Review\n");
                        else
                        {
                            a[i][k]=M;
                        }
                    }
                }
                if(k==1)
                {
                    printf("English: ");
                    while(E>100||E<0)
                    {

                        scanf("%d",&E);
                        if(E>100||E<0)
                            printf("Try Review\n");
                        else
                        {
                            a[i][k]=E;
                        }
                    }
                }
                if(k==2)
                {
                    printf("Reading: ");
                    while(R>100||R<0)
                    {
                        scanf("%d",&R);
                        if(R>100||R<0)
                            printf("Try Review\n");
                        else
                        {
                            a[i][k]=R;
                        }
                    }
                }
                if(k==3)
                {
                    printf("Knowledge: ");
                    while(K>100||K<0)
                    {
                        scanf("%d",&K);
                        if(K>100||K<0)
                            printf("Try Review\n");
                        else
                        {
                            a[i][k]=K;
                        }
                    }
                }
            }
            printf("\n");
            CalTotal(a,T);
            Check(a,c);
            M=101;
            E=101;
            R=101;
            K=101;
        }
        printf("\n");

        for(i=0; i<5; i++)
        {
            printf("Total people %d is %.2f %% ",i+1,T[i]);



            if(T[i]>=50&&c[i]==4)
            {
                printf("Pass \n");
            }
            else
            {
                printf("Don't pass\n");
            }

            if(T[i]<min)
            {
                min=T[i];
                imin=i;
            }
            if(T[i]>max)
            {
                max=T[i];
                imax=i;
            }

        }
        printf("\n");
        printf("Max is %.2f // People %d \n",max,imax+1);
        printf("min is %.2f\ // People %d \n",min,imin+1);
        printf("Do you want Continue(Y/N): ");
        scanf("%s",&Y);
    }
    while(Y=='Y');
    return 0;


}
