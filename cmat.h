#ifndef CMAT_H
#define CMAT_H

#include <stdio.h>
#include <stdlib.h>

struct IntCMat {
    int* arena; // keep all the data in one arena
    int** data; // two dim indexing
    int shape[2];
    int arena_shape[2]; // to record the original matrix shape for sliced matrix indexing
    int offset[2]; // to offset sliced matrix index
};

struct FloatCMat {
    float* arena; // keep all the data in one arena
    float** data; // two dim indexing
    int shape[2];
    int arena_shape[2]; // to record the original matrix shape for sliced matrix indexing
    int offset[2]; // to offset sliced matrix index
};


int create_int_matrix(int height, int width, struct IntCMat* p_new_mat);

int create_float_matrix(int height, int width, struct FloatCMat* p_new_mat);

int create_int_matrix_from_array(int height, int width, int* array, int array_length, int offset[2], struct IntCMat* p_new_mat);

int create_float_matrix_from_array(int height, int width, float* array, int array_length, int offset[2], struct FloatCMat* p_new_mat);

int create_int_matrix_from_stack(int height, int width, int array[], int array_length, int offset[2], struct IntCMat* p_new_mat);

int create_float_matrix_from_stack(int height, int width, float array[], int array_length, int offset[2], struct FloatCMat* p_new_mat);

struct IntCMat slice_int_matrix(struct IntCMat mat, int slice0[2], int slice1[2]);

struct FloatCMat slice_float_matrix(struct FloatCMat mat, int slice0[2], int slice1[2]);

int assign_int_slice(struct IntCMat m1, struct IntCMat m2, int slice0[2], int slice1[2]);

int assign_float_slice(struct FloatCMat m1, struct FloatCMat m2, int slice0[2], int slice1[2]);

int matadd_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3);

int matadd_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3);

int matsub_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3);

int matsub_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3);

int matelm_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3);

int matelm_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3);

int mateld_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3);

int mateld_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3);

int print_int_matrix(struct IntCMat mat);

int print_float_matrix(struct FloatCMat mat);

int free_int_matrix(struct IntCMat m);

int free_float_matrix(struct FloatCMat m);

#endif