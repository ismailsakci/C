
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define IS pow(10,-12)
#define VT 0.026
#define N 1
#define tolerance 0.00001

double CALCULATE_ID(double VD) {
double ID;
    ID=IS*(exp((VD)/(N*VT))-1);
    return ID;
}

double bisect( double ID ,double VD1, double VD2){
    int iteration =0;
  
   double mid = (VD1 + VD2) / 2.0;
    while (fabs(VD2-VD1) >= tolerance){
        
        if (CALCULATE_ID(VD1) * CALCULATE_ID(mid) < 0.0)
        {
            VD2 = mid;
        }
        else if (CALCULATE_ID(VD2) *CALCULATE_ID(mid) < 0.0)
        {
            VD1 = mid;
        }
        mid = (VD1+ VD2) / 2.0;
        iteration++;
    }
   printf("Bisection Method: Maximum iterations reached. Approximate root: %d\n", iteration);
    return mid;
}

int main(){
double VD;
double ID;

printf("\nenter the VD of the VOLTAGE");
scanf("%lf",&VD);
printf("\n ID =%lf",CALCULATE_ID(VD));


double VD1,VD2;
printf("\nenter the VD1");
scanf("%lf",&VD1);
printf("\nenter the VD2");
scanf("%lf",&VD2);

double rootBisection = bisect(1,VD1,VD2);
 printf("Root  = %lf\n", rootBisection);


return 0;
}
