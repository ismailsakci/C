#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double fpower(double x){
    return (50*exp(-25*x))/1000;
}
double leftrect(double(*f)(double),double a,double b,double n){
     double x0=a;
double delta=(b-a)/n;
    double toplam=0;
    
        for(int i=0;i<delta;i++){
           toplam=toplam+f(x0)*delta;
           x0=x0+delta;
        }
    return toplam;
}
double rightrect(double(*f)(double),double a,double b,double n){
     double x0=a;
    double delta=(b-a)/n;
    double toplam=0;
    
        for(int i=0;i<delta;i++){
           toplam=toplam+f(x0+i*delta)*delta;
            x0=x0+delta;
        }
    return toplam;
}
/*double trapezoid(double (*f)(double,double),double a,double b,double panel){

    double delta=(b-a)/panel;
    double toplam=0;
        for(int i=0;i<panel;i++){
           toplam=toplam+0.5*(leftrect(fpower,a,b,panel)+rightrect(fpower,a,b,panel))*delta;
        }

    return toplam; }
    
*/
double simpson(double (*f)(double, double), double a,double b,int n) {
    double h, x0, area;
    area= 0.0;
    x0=a;
    h = (b-a) / n;
    for (x0 = a; x0 <= b; x0 += h) {
        area += h * (f(x0, h) + 4 * f(x0 + h/2, h) + f(x0 + h, h)) / 6;
    }
    return area;
    }

int main() {
    double a;
    double b;
    int panel;
    int n;
    printf("enter the a and b");
    scanf("%lf %lf",&a,&b);
    double simpson_result;
    double adaptive_simpson_results;
    double leftrangular_method;
    double trapezoid_method;
     //double trapezoid_met=(leftrect(fpower, a,b,panel)+rightrect(fpower, a,b,panel))/2;
    for (int i = 1; i <= 10; i++) {
        panel= i * 10;
        simpson_result = simpson(fpower,a,b,panel);
        leftrangular_method= leftrect(fpower, a,b,panel);
        //trapezoid_method=trapezoid(fpower,a, b, panel);
        trapezoid_method=(leftrect(fpower, a,b,panel)+rightrect(fpower, a,b,panel))/2;
        printf("Number of panels: %d, left rectangular method:\t %lf \t trapezoid:\t %lf simpson method:  %lf \n ", panel,leftrangular_method ,trapezoid_method, simpson_result );
    }

    return 0;
}






















