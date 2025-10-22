#include <stdio.h>
struct polynomial{
    int coeff;
    int expo;
};
int main(){
    int i,j,k,n1,n2;
    printf("Enter the no. of terms for 1st polynomial");
    scanf("%d",&n1);
    struct polynomial p1[n1];
    for(i=0;i<n1;i++){
        printf("Enter the coefficient  and exponent for term %d:",i+1);
        scanf("%d%d",&p1[i].coeff,&p1[i].expo);
    }
    printf("Enter the no. of terms for 2nd polynomial");
    scanf("%d",&n2);
    struct polynomial p2[n2];
    for(i=0;i<n2;i++){
        printf("Enter the coefficient and exponent for term %d:",i+1);
        scanf("%d%d",&p2[i].coeff,&p2[i].expo);
    }
    printf("\nFirst Polynomial: ");
    for(i=0;i<n1;i++){
        printf("%dx^%d",p1[i].coeff,p1[i].expo);
        if(i!=n1-1){
            printf(" + ");
        }
    }
    printf("\nSecond Polynomial: ");
    for(i=0;i<n2;i++){
        printf("%dx^%d",p2[i].coeff,p2[i].expo);
        if(i!=n2-1){
            printf(" + ");
        }
    }
    i=0,j=0,k=0;
    struct polynomial res[n1+n2];
    while(i<n1 && j<n2){
        if(p1[i].expo==p2[j].expo){
            res[k].coeff=p1[i].coeff+p2[j].coeff;
            res[k].expo=p1[i].expo;
            i++,j++,k++;
        }
        else if(p1[i].expo>p2[j].expo){
            res[k]=p1[i];
            i++,k++;
        }
        else{
            res[k]=p2[j];
            j++,k++;
        }
    }
    while(i<n1){
        res[k]=p1[i];
            i++,k++;
    }
    while(j<n2){
        res[k]=p2[j];
            j++,k++;
    }
    printf("\nSum of the given polynomials is: ");
    for(i=0;i<k;i++){
        printf("%dx^%d",res[i].coeff,res[i].expo);
        if(i!=k-1){
            printf(" + ");
        }
    }
}