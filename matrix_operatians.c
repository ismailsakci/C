#include<stdio.h>
#include<stdlib.h>

void printmatrix(double **matrix, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%lf",matrix[i][j]);
        }
        printf("\n");
    }
}

   
double determinant(double **matrix, int size) {
    double det = 0.0;

    if (size== 1) {
        det = matrix[0][0];
    }

    else if (size== 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    else if (size== 3) {
        det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }
    return det;
}

int symmetric(double **matrix, int size)
{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i != j){
                if(matrix[i][j] != matrix[j][i]){
                return 0;
                }
            }
        }
    }
    return 1;

}

int main (){
    double **matrix;
    int size;
    printf("enter the matrix size: ");
    scanf("%d",&size);
    matrix = (double**)malloc(size*sizeof(double*));
    for(int i=0;i<size;i++){
        *(matrix+i) = (double*)malloc(size*sizeof(double));
    }
    printf("enter the matrix elements\n");
    int i, j=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
    if(!(symmetric(matrix, size))){
        printf("is not symmetric\n");
        return 0;
    }
    int flag=0;
    double det;
    for(i=0;i<size;i++){
        printf("******* Matrix #%d *******\n", i+1);
        printmatrix(matrix, i+1);
        det = determinant(matrix, i+1);
        if(det <= 0){
            flag = 1;
        }
        printf("\ndeterminant : %lf\n", det);
        printf("***************\n\n");
    }
    
    if(flag==1){
        printf("\nIs not positive definite\n");
    }
    else{
        printf("\nIs a positive definite");
    }
    



    return 0;
}
