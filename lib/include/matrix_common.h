/**
* -----------------------------------------------------------|
* |		        libmatrix 1.0			     |
* |			Author: Venio			     |
* -----------------------------------------------------------|
*
* miscellaneous function for matrices and vectors in c++ such as
* printing, randimly populating, row and column swapping and determinants
*
**/

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

void swap_col(double** matrix, int dim, int col1, int col2);
void swap_row(double** matrix, int dim, int row1, int row2);

void copy_matrix(double** src, double** dest, int dim);
void copy_vector(double* src, double* dest, int dim);

#endif

