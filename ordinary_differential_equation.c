#include<stdio.h>
#include<math.h>
double ydizi[200];
double y1dizi[200];
double y2dizi[200];
double y3dizi[200];
double y4dizi[200];


double fturev(double x,double y){
   
    double result=-6*exp(-2*x)+y+10;
    return result;
    
}

double fsade(double x){
    double result=2*exp(-2*x)+9*exp(x)-10;
   
    printf("\n\n");
    
    return result;
}
void euler(double(*dydx)(double,double), double *result,double xfirst, double yfirst,double xlast,double stepsize){
    double x0= xfirst;
    double y0 = yfirst;

    double y1;
    int counter = 0;
    double donguNum =(xlast-xfirst)/stepsize;
    printf("\n");
      printf("--------eurler--------------\n");
    for(double i=0;i<=donguNum;i+=1){
       // printf("Step %d - y(%lf): %lf\n", counter,x0,y0);
       ydizi[counter]=y0;
      double  fPrimex1 =dydx(x0, y0);
        y1 = y0 + fPrimex1*stepsize;
        x0+=stepsize;
        y0 = y1;
        counter++;
    }
    *result = y1;

}
void kr4(double (*f)(double, double), double *kr4x, double xfirst, double yfirst, double xlast, double h) {
  double x0=xfirst;
  double y0=yfirst;
  double k1,k2,k3,k4;
  double y1;
  int counter=0;
  double donguNum =(xlast-xfirst)/h;
      printf("runga kutta4.derece\n");
  for(double i=0;i<=donguNum;i+=1){
    y3dizi[counter]=y0;
    k1=f(x0,y0);
    k2=f(x0+(h/2),y0+((h*k1)/2));
    k3=f(x0+h/2,y0+(k2*h)/2);
    k4=f(x0+h,y0+k3*h);
    y1=y0+ ((k1/6) + ((2*k2)/6) + ((2*k3)/6)  + (k4/6)) * h;
    x0=x0+h;
    y0=y1;
    //printf("\n\n f(%lf)= %lf\n",x0,y1);
    counter++;
  }
  *kr4x=y1; 
}
void  fexact( double xfirst, double yfirst, double xlast, double h){

for (int i = 0; i <= (xlast-xfirst)/h; i++) {
      double xdegisim = xfirst + i * h;
      y4dizi[i]=fsade(xdegisim);
    
    }
}

int main() {
  double x0,y0,xlast,stepsize;
  printf("enter the vaules of the variable ");
  scanf("%lf",&x0);
   printf("enter the vaules of the variable ");
  scanf("%lf",&y0);
   printf("enter the vaules of the variable ");
  scanf("%lf",&xlast);
   printf("enter the vaules of the variable ");
  scanf("%lf",&stepsize);

    double result;
    double kr4x;
    euler(fturev, &result, x0,  y0,xlast, stepsize);
    kr4(fturev, &kr4x, x0, y0, xlast, stepsize);
   fexact(x0,y0,xlast,stepsize);

   /* printf("exact\n");
    for (int i = 0; i <= (xlast-x0)/stepsize; i++) {
      double xdegisim = x0 + i * stepsize;
      y4dizi[i]=fsade(xdegisim);
     
    }*/
    double percentage=
printf(" \t\t\tEuler\t|\t\tRK4\t|\t|\tEXACT\n");
   // for(int i=0;i<101;i++){
        printf("--y(%lf)|\t%lf\t|\t%lf\t|\t%lf\t|\n", xlast,ydizi[100],y3dizi[100],y4dizi[100]);
       // x0+= stepsize;
  //  }
    
  
    
    return 0;
}



