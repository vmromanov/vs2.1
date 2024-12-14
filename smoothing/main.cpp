#include <iostream>
using namespace std;
#include "locale.h"
template <typename InputType, typename OutputType>
OutputType** smoosing(int size, InputType** inputMatrix) {
    OutputType** outputMatrix = new OutputType * [size];
    for (int i = 0; i < size; ++i) {
        outputMatrix[i] = new OutputType[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            OutputType neighborSum = 0;
            int count = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighborSum += (inputMatrix[ni][nj]);
                        ++count;
                    }
                }
            }
            outputMatrix[i][j] = (OutputType)(neighborSum / count);
        }
    }
    return outputMatrix;
}

int main() {
    const int size = 3;
    setlocale(LC_ALL, "RUS");
    double** inputMatrix = new double* [size];
    for (int i = 0; i < size; ++i) {
        inputMatrix[i] = new double[size];
    }
    double values[3][3] = {
        {1.5, 2, 3},
        {4.5, 5, 6},
        {7, 8, 9}
    };
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputMatrix[i][j] = values[i][j];
        }
    }
    int** outputMatrix = smoosing<double,int>(size, inputMatrix);
    cout << "Результирующая матрица:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << outputMatrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < size; ++i) {
        delete[] inputMatrix[i];
        delete[] outputMatrix[i];
    }
    delete[] inputMatrix;
    delete[] outputMatrix;
    return 0;
}