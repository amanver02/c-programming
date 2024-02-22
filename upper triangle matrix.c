#include <stdio.h>
void printUpperTriangular(int matrix[][10], int rows, int cols) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
    if (j >= i) {
    printf("%d\t", matrix[i][j]);} else {
    printf("\t");}}
    printf("\n");}}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns (up to 10): ");
    scanf("%d %d", &rows, &cols);
    if (rows > 10 || cols > 10) {
        printf("Error: Matrix size should be up to 10x10.\n");
        return 1;}

        
    int matrix[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the upper triangular matrix
    printUpperTriangular(matrix, rows, cols);

    return 0;
}