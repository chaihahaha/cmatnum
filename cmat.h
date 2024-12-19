#ifndef CMAT_H
#define CMAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef USE_ACCELERATE
#include "cblas_new.h"
#else
#include "cblas.h"
#endif

struct int_cmat {
    int* arena; // keep all the data in one arena
    int** data; // two dim indexing
    int shape[2];
    int arena_shape[2]; // to record the original matrix shape for sliced matrix indexing
    int offset[2]; // to offset sliced matrix index
};

struct float_cmat {
    float* arena; // keep all the data in one arena
    float** data; // two dim indexing
    int shape[2];
    int arena_shape[2]; // to record the original matrix shape for sliced matrix indexing
    int offset[2]; // to offset sliced matrix index
};

struct double_cmat {
    double* arena; // keep all the data in one arena
    double** data; // two dim indexing
    int shape[2];
    int arena_shape[2]; // to record the original matrix shape for sliced matrix indexing
    int offset[2]; // to offset sliced matrix index
};

typedef struct int_cmat int_cmat;
typedef struct float_cmat float_cmat;
typedef struct double_cmat double_cmat;
#define pairint (int[2])

int is_contiguous_double(double_cmat m);

int create_int_matrix(int shape[2], int_cmat* p_new_mat);

int create_float_matrix(int shape[2], float_cmat* p_new_mat);

int create_double_matrix(int shape[2], double_cmat* p_new_mat);

int create_int_matrix_from_array(int shape[2], int* array, int array_length, int offset[2], int_cmat* p_new_mat);

int create_float_matrix_from_array(int shape[2], float* array, int array_length, int offset[2], float_cmat* p_new_mat);

int create_double_matrix_from_array(int shape[2], double* array, int array_length, int offset[2], double_cmat* p_new_mat);

int_cmat slice_int_matrix(int_cmat mat, int slice0[2], int slice1[2]);

float_cmat slice_float_matrix(float_cmat mat, int slice0[2], int slice1[2]);

double_cmat slice_double_matrix(double_cmat mat, int slice0[2], int slice1[2]);

int create_slice_double_matrix_contiguous(double_cmat *dst, double_cmat mat, int slice0[2], int slice1[2]);

int create_double_contiguous_from_slice(double_cmat *dest, double_cmat *src);

int assign_int_slice(int_cmat m1, int_cmat m2, int slice0[2], int slice1[2]);

int assign_float_slice(float_cmat m1, float_cmat m2, int slice0[2], int slice1[2]);

int assign_double_slice(double_cmat m1, double_cmat m2, int slice0[2], int slice1[2]);

int assign_double_clone(double_cmat m1, double_cmat m2);

int matlincomb_double_contiguous(double_cmat res, int n_mats, double_cmat* mats, int8_t* coeffs);

int matadd_int(int_cmat m1, int_cmat m2, int_cmat m3);

int matadd_float(float_cmat m1, float_cmat m2, float_cmat m3);

int matadd_double(double_cmat m1, double_cmat m2, double_cmat m3);

int matsub_int(int_cmat m1, int_cmat m2, int_cmat m3);

int matsub_float(float_cmat m1, float_cmat m2, float_cmat m3);

int matsub_double(double_cmat m1, double_cmat m2, double_cmat m3);

int matelm_int(int_cmat m1, int_cmat m2, int_cmat m3);

int matelm_float(float_cmat m1, float_cmat m2, float_cmat m3);

int matelm_double(double_cmat m1, double_cmat m2, double_cmat m3);

int mateld_int(int_cmat m1, int_cmat m2, int_cmat m3);

int mateld_float(float_cmat m1, float_cmat m2, float_cmat m3);

int mateld_double(double_cmat m1, double_cmat m2, double_cmat m3);

int matneg_double(double_cmat m1, double_cmat m2);

int print_int_matrix(int_cmat mat);

int print_float_matrix(float_cmat mat);

int print_double_matrix(double_cmat mat);

int free_int_matrix(int_cmat m);

int free_float_matrix(float_cmat m);

int free_double_matrix(double_cmat m);

#endif
