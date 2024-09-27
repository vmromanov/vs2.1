#pragma once


int** matrix_creation(const char* file, int size);

/*
* @brief fills matrix with numbers
*/
int matrix_input(const char* namef, int& size, int** matrix);

/*
* @brief chek if matrix the ,agic square
*/
bool is_magic_square(int** matrix, int size);