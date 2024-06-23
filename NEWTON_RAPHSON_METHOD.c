#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define  PI 3.14159265358979323846
#define  d 0.5
#define  l 1.4
#define  lamda 3.6
#define  a 2.28

double funcK(){
    return( (tan( (2*PI*(d + l))/(lamda) ))/(2*PI*( (d)/(lamda) )) );
}

double f(double x){
    return tan(x)-(funcK()*x);

}
double fturev(double x){
    return (1/cos(x))*(1/cos(x))-funcK();

}

double func_er(double x){
   return (  ( pow( (a/d), 2 ) * ( pow( (x/PI), 2 ) ) + 1 )/( pow( ((2*a)/lamda), 2 ) + 1 )  );
}

double degRad(double degree)
{
    return ( degree * (PI/180) );
}

double newtonmethod(double x,double tol, int *sayac){
    *sayac = 0;
    double valX = f(x);
    double valXPrime = fturev(x);
    double x2 = x - ( (valX)/(valXPrime) );
    (*sayac)++;
    while( !(fabs( x - x2 ) <= tol) ){
        x = x2;
        valX = f(x);
        valXPrime = fturev(x);
        x2 = x - ( (valX)/(valXPrime) );
        (*sayac)++;
    }

    return x2;
}
double *tolerance_val_generator()
{
    double *tols = (double *)malloc(6*sizeof(double));
    int i;
    for(i=0;i<6;i++){
        *(tols + i) = pow(10, -1*(6-i));
    }

    return tols;
}

int main (){
   int sayac;
  double degree;
   printf("enter the degreee  (between 90 and 270)\n");
   scanf("%lf",&degree);

   while(!(90<degree && degree<270)){
    printf("enter the degreee  (between 90 and 270)\n");
    scanf("%lf",&degree);
   }
   double radyan=degRad(degree);
   double *tol = tolerance_val_generator();
   printf("\n\n");
   for(int i=0;i<6;i++){
    printf("tolerance: %lf\n",tol[i]);
    printf("root of f(x) where x of radians %lf\n",newtonmethod(radyan, tol[i], &sayac));
    printf("diaelectric constant is (er)%lf\n", func_er(newtonmethod(radyan, tol[i], &sayac)));
    printf("number of the iterations %d\n\n\n",sayac);
   }

    return 0;
}
