#include<stdio.h>
#include<math.h>
/*
void getMatrix(double mat[2][2]) {
  int i, j;
  printf("Enter elements of the matrix:\n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      (scanf("%lf", &mat[i][j])) 
    
    }
  }
}
void display(double mat[2][2]) {
    // Loop over the rows
    for (int i = 0; i < 2; i++) {
        // Loop over the columns
        for (int j = 0; j < 2; j++)
            // Print each element
            printf("%lf ", mat[i][j]);
        // Print a newline at the end of each row
        printf("\n");
    }
}
*/
double determinant(double a1,double a2,double a3,double a4 ){
 double   det=a1*a3-a2*a4;
 return det;
      
}

void find_roots(double a,double b,double c,double d,double *roots){
    double discriminat;
    int i;
discriminat=b*b-(4*a*c);
if(discriminat>0){
    roots[0]=(-b-sqrt(discriminat))/(2*a);
    roots[1]=(-b-sqrt(discriminat))/(2*a);
    roots[2]=(-b-sqrt(discriminat))/(2*a);
    roots[3]=(-b+sqrt(discriminat))/(2*a);
    printf("%lf + %lf calculate roots\n",roots[0],roots[1]);
    printf("%lf + %lf calculate roots\n",roots[2],roots[3]);
}
else if(discriminat==0){
    roots[0]=-b/2*a;
    roots[1]=0;
    roots[2]=-b/2*a;
    roots[3]=0;
    printf("%lf + %lf  calculate roots\n",roots[0],roots[1]);
    printf("%lf +%lf   calculate roots\n",roots[2],roots[3]);
}
else if(discriminat<0){
    roots[0]=-b/(2*a);
    roots[1]=(sqrt(fabs((discriminat))))/(2*a);
    roots[2]=(-1*b/(2*a));
    roots[3]=(-1*sqrt(fabs((discriminat))))/(2*a);
    printf(" %lf + %lfi  calculate roots \n",roots[0],roots[1]);
      printf("%lf +%lfi  calculate roots\n ",roots[2],roots[3]);
}
}




int main (){
   double a1,a2,a3,a4,roots[4];
   printf("enter the element of the 2x2 matrix;\n");
   scanf("%lf %lf %lf %lf",&a1,&a2,&a3,&a4);
   printf("matrix entered:\n");
   printf("%lf\t%lf\n",a1,a2);
   printf("%lf\t%lf\n",a3,a4);


   printf("******************************\n");
   printf("\ncalculating eigenvalues...\n");
   find_roots(a1,a2,a3,a4,roots);

  



    return 0;
}
