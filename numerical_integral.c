#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#
double f1(double x){
    return(exp(-0.1*pow(x,2)));
}

double f2(double x){
    return(2*exp(-0.2*pow(x,1)));

}
double Left_rectangular_method(double startx,double endx, double panel,int f){
    double delta=(endx-startx)/panel;
    double toplam=0;
    if(f==1){
        for(int i=0;i<panel;i++){
           toplam=toplam+f1(startx+i*delta)*delta;
        }
    }
    else if(f==2){
        for(int i=0;i<panel;i++){
           toplam=toplam+f2(startx+i*delta)*delta;
        }
    }

    return toplam;
}
double Trapezoidal_method(double startx,double endx, double panel,int f){
    double delta=(endx-startx)/panel;
    double toplam=0;
    if(f==1){
        for(int i=0;i<panel;i++){
           toplam=toplam+0.5*(f1(startx+i*delta)+f1(startx+((i+1)*delta)))*delta;
        }
    }
    else if(f==2){
        for(int i=0;i<panel;i++){
           toplam=toplam+0.5*(f2(startx+i*delta)+f2(startx+((i+1)*delta)))*delta;
        }
    }

    return toplam;
}

int *number_of_panels_generator() {
    int *panels = malloc(20 * sizeof(int));       
    for (int i = 0; i < 20; i++) {
        panels[i] = 50 * (i + 1);
    }
    return panels;
}
 
int main (){
   double x,a,b,panel;
   int f;


   //printf("rectangular method is the %lf\n",f1(4));()
   int *myPanelVals = number_of_panels_generator();
    
    double rectAreaf1; 
    double rectAreaf2; 
    double trapAreaf1; 
    double trapAreaf2;

    printf("\t\t\tRect. f1\tTrap.f1\t\tRect. f2\tTrap. f2\tRect. area\tTrap. area\n");
    for(int i;i<20;i++){
        double rectAreaf1 = Left_rectangular_method(0,30,myPanelVals[i],1);
        double rectAreaf2 = Left_rectangular_method(0,30,myPanelVals[i],2);
        double trapAreaf1 = Trapezoidal_method(0,30,myPanelVals[i],1);
        double trapAreaf2 = Trapezoidal_method(0,30,myPanelVals[i],2);
        printf("Number of panels: %d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", myPanelVals[i], rectAreaf1, trapAreaf1, rectAreaf2, trapAreaf2, rectAreaf2-rectAreaf1, trapAreaf2-trapAreaf1);
    }
   


    return 0;
}
