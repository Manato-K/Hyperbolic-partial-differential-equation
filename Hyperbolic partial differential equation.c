/* Hyperbolic partial differential equation */
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define M 10
#define N 100
float g(float x)
{ return(0.0); }
int main(void)
{
    int i,j,m,n;
    float c,k,h,r,u[M+1][N+1],v,er;
    c=1.0;
    h=0.2;
    k=0.02;
    r=k/h*c;
    for(j=0;j<=N;j++) {
        for(i=0;i<=M;i++) {
            if(j==0) {
                u[i][j]=0.05*h*i*(2-h*i);
            } else {
                u[i][j]=0.0;
            }
        }
    }

    for(j=0;j<N;j++) {
        if(j==0) {
            for(i=1;i<M;i++)
                u[i][1]=(1.0-r*r)*u[i][0]+(u[i+1][0]
                +u[i-1][0])*r*r/2.0+k*g(i*h);
        } else {
            do {
                er=0.0;
                for(i=1;i<M;i++) {
                    v=2.0*(1.0-r*r)*u[i][j]
                    +r*r*(u[i+1][j]+u[i-1][j])-u[i][j-1];
                    er+=fabs(u[i][j+1]-v);u[i][j+1]=v;
                }
            } while(er>1.0e-5);
        }
    }
    for(j=0;j<=N;j++) {
    printf("%7.3f ",k*j);
    for(i=0;i<=M;i++) printf("%7.3f",u[i][j]);
    printf("\n");
    }
}

/*


*/