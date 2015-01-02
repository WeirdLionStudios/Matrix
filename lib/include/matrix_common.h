#ifndef _LIB_MATRIX_COMMON_H
#define _LIB_MATRIX_COMMON_H

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <math.h>

using namespace std;

void init_rand_matrix(double** ptr, int dim, int max);
void init_rand_vector(double* ptr, int dim, int max);
void print_vector(string header, double* vector, int dim);
void print_matrix(string header, double** matrix, int dim);
double get_laplace_determinant(double** matrix, int dim);
double** get_submatrix(double** matrix, int dim, int row, int col);

#endif

