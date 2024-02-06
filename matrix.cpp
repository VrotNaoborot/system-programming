#include <cstdio>
#include <random>
#include <ctime>

int** initMatrix(int rows, int cols) {
    //инициализация матрицы
    int** matrix = new int*[rows];

    //выделение памяти под каждый элемент массива
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    return matrix;
}

int** fillingMatrix(int** matrix, int rows, int cols) {
    //заполнение матрицы
    int start = 0;
    int end = 100;
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < cols; k++) {
            matrix[j][k] = rand()%(end - start + 1) + start;
        }
    }
    return matrix;
}

int** summMatrix(int** matrixA, int** matrixB, int rows, int cols) {
    //инициализация третьей матрицы
    int** matrixC = initMatrix(rows, cols);
    //заполнение
    for (int a = 0; a < rows; a++) {
        for (int b = 0; b < cols; b++) {
            matrixC[a][b] = matrixA[a][b] + matrixB[a][b];
        }
    }
    return matrixC;

}

void printMatrix(int** matrix, int rows, int cols) {
    printf("--------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Количество строк\n");
    scanf("%d", &rows);
    printf("Количество столбцов\n");
    scanf("%d", &cols);

    int** matrixA = initMatrix(rows, cols);
    int** matrixB = initMatrix(rows, cols);

    srand(time(0));

    matrixA = fillingMatrix(matrixA, rows, cols);
    matrixB = fillingMatrix(matrixB, rows, cols);
    
    int** matrixC = summMatrix(matrixA, matrixB, rows, cols);

    printMatrix(matrixA, rows, cols);
    printMatrix(matrixB, rows, cols);
    printMatrix(matrixC, rows, cols);
    return 0;
}
