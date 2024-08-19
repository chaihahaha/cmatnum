#ifndef CMAT_H
#define CMAT_H

#include <stdio.h>
#include <stdlib.h>

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



int create_int_matrix(int shape[2], struct int_cmat* p_new_mat);

int create_float_matrix(int shape[2], struct float_cmat* p_new_mat);

int create_double_matrix(int shape[2], struct double_cmat* p_new_mat);

int create_int_matrix_from_array(int shape[2], int* array, int array_length, int offset[2], struct int_cmat* p_new_mat);

int create_float_matrix_from_array(int shape[2], float* array, int array_length, int offset[2], struct float_cmat* p_new_mat);

int create_double_matrix_from_array(int shape[2], double* array, int array_length, int offset[2], struct double_cmat* p_new_mat);

int create_int_matrix_from_stack(int shape[2], int array[], int array_length, int offset[2], struct int_cmat* p_new_mat);

int create_float_matrix_from_stack(int shape[2], float array[], int array_length, int offset[2], struct float_cmat* p_new_mat);

int create_double_matrix_from_stack(int shape[2], double array[], int array_length, int offset[2], struct double_cmat* p_new_mat);

struct int_cmat slice_int_matrix(struct int_cmat mat, int slice0[2], int slice1[2]);

struct float_cmat slice_float_matrix(struct float_cmat mat, int slice0[2], int slice1[2]);

struct double_cmat slice_double_matrix(struct double_cmat mat, int slice0[2], int slice1[2]);

int assign_int_slice(struct int_cmat m1, struct int_cmat m2, int slice0[2], int slice1[2]);

int assign_float_slice(struct float_cmat m1, struct float_cmat m2, int slice0[2], int slice1[2]);

int assign_double_slice(struct double_cmat m1, struct double_cmat m2, int slice0[2], int slice1[2]);

int matadd_int(struct int_cmat m1, struct int_cmat m2, struct int_cmat m3);

int matadd_float(struct float_cmat m1, struct float_cmat m2, struct float_cmat m3);

int matadd_double(struct double_cmat m1, struct double_cmat m2, struct double_cmat m3);

int matsub_int(struct int_cmat m1, struct int_cmat m2, struct int_cmat m3);

int matsub_float(struct float_cmat m1, struct float_cmat m2, struct float_cmat m3);

int matsub_double(struct double_cmat m1, struct double_cmat m2, struct double_cmat m3);

int matelm_int(struct int_cmat m1, struct int_cmat m2, struct int_cmat m3);

int matelm_float(struct float_cmat m1, struct float_cmat m2, struct float_cmat m3);

int matelm_double(struct double_cmat m1, struct double_cmat m2, struct double_cmat m3);

int mateld_int(struct int_cmat m1, struct int_cmat m2, struct int_cmat m3);

int mateld_float(struct float_cmat m1, struct float_cmat m2, struct float_cmat m3);

int mateld_double(struct double_cmat m1, struct double_cmat m2, struct double_cmat m3);

int print_int_matrix(struct int_cmat mat);

int print_float_matrix(struct float_cmat mat);

int print_double_matrix(struct double_cmat mat);

int free_int_matrix(struct int_cmat m);

int free_float_matrix(struct float_cmat m);

int free_double_matrix(struct double_cmat m);

#endif
