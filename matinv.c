#include<stdio.h>

// Function to claculate determinant of nxn matrix.

int det(float A[50][50],int m){
    int pr,j,p,q,t,r,s;
    float C[50],d=0,B[50][50];
    if (m==2){
        d=0;
        d = A[1][1]*A[2][2]-A[1][2]*A[2][1];
        return(d);
    }
    else{
    for(j=1 ; j<=m ; j++)
        r=1;
        s=1;
        for (p=1 ; p<=m ; p++){
            for(q=1 ; q<=m ; q++){
                if ((p!=1)&&(q!=j)){
                    B[r][s] = A[p][q];
                    s++;
                    if (s>m-1){
                        r++;
                        s=1;
                    }
                }
            }
        }
    }   for (t=1,pr=1 ; t<= 1+j ; t++){
            pr = (-1)*pr;
            C[j] = pr*det(B,m-1);
    }
    for (j=1 , d=0 ; j<=m ; j++){
        d = d + A[1][j]*C[j];
    }
    return(d);
}

//Program to calculate inverse of nxn matrix.

int main(){
    float A[50][50],B[49][49],C[50][50];
    int n = 2, m, i, j, ii, jj, k, l;
    printf("Enter the dimension of array ");
    scanf("%d",&m);
    printf("\n\nEnter the elements of %dx%d array ",m,m);
    for (i=0; i<m ; i++){
        for (j=0 ; j<m ; j++){
            scanf("%f",&A[i][j]);
        }
    }
    for (i=0 ; i<m ; i++){
        for (j=0 ; j<m ; j++){
            ii = 0;
            jj = 0;
            k = 0;
            firststop:
            if (k<=m-2){
                l = 0;
                secondstop:
                if (l<=m-2){
                    if((ii!=i)&&(jj!=j)){
                        B[k][l] = A[ii][jj];
                        l++;
                    }
                    jj++;
                    if (jj==m+1){
                        ii++;
                        jj = 1;
                    }
                    goto secondstop;
                }
                k++;
                goto firststop;
            }
            float aik = 1.0;
            for (int ik=0 ; ik<n ; ik++){
                int aik = aik*(-1);
            }
            int lk = m - 1;
            float kl = det(B,lk);
            C[i][j] = aik*k;
            n++;
        }
    }

    for (i=0 ; i<m ; i++){
        for(j=0 ; j<m ; j++){
            float T = C[i][j];
            C[i][j] = C[j][i];
            C[j][i] = T;
        }
    }

    float D = det(A,m);

    for (i=0 ; i<m ; i++){
        for (j=0 ; j<m ; j++){
            C[i][j] = C[i][j]/D;
        }
    }
}

