#include <stdio.h>
#include <stdlib.h>

void control(int **A, int **M, int N);
int main()
{
    int i, j;
    int N = 5;
    int **A, **M;

    // Allocate memory for matrix M
    M = (int**)calloc(N, sizeof(int*));
    if(M == NULL){
        printf("Memory allocation ERROR: M matrix initialization!\n");
        return -1;
    }
    for(i=0; i<N; i++){
        M[i] = (int*)calloc(N, sizeof(int));
        if(M[i] == NULL){
            printf("Memory allocation ERROR: M matrix row initialization!\n");
            return -1;
        }
    }

    // Allocate memory for matrix A
    A = (int**)calloc(N, sizeof(int*));
    if(A == NULL){
        printf("Memory allocation ERROR: A matrix initialization!\n");
        return -1;
    }
    for(i=0; i<N; i++){
        A[i] = (int*)calloc(2, sizeof(int));
        if(A[i] == NULL){
            printf("Memory allocation ERROR: A matrix row initialization!\n");
            return -1;
        }
    }

    printf("Enter lesson's start time and duration: \n");
    for(i=0; i<N; i++){
        scanf("%d %d", &A[i][0], &A[i][1]);
    }

    control(A, M, N);

    printf("Lessons that conflict with each other:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(M[i][j] == 1){
                printf("%d->%d ", i, j);
            }
        }
        printf("\n");
    }

    // Free allocated memory
    for(i=0; i<N; i++){
        free(M[i]);
    }
    free(M);

    for(i=0; i<N; i++){
        free(A[i]);
    }
    free(A);

    return 0;
}

void control(int **A, int **M, int N)
{
    int i, j;
    int end_time_i;

    for(i=0; i<N; i++){
        end_time_i = A[i][0] + A[i][1];
        for(j=0; j<N; j++){
            if(i != j){
                if(A[j][0] < end_time_i && A[j][0] >= A[i][0]){
                    M[i][j] = M[j][i] = 1;
                }
            }
        }
    }
}
