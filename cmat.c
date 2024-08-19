#include "cmat.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int create_int_matrix(int height, int width, struct IntCMat* p_new_mat) {
    // create a matrix with 0 in shape [height, width]
    int N = height * width;
    (*p_new_mat).data = (int **)malloc(height * sizeof(int *));
    (*p_new_mat).arena = malloc(N * sizeof(int));
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = 0;
    (*p_new_mat).offset[1] = 0;
    for (int i = 0; i < height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width];
    }
    for (int j = 0; j < N; j++) {
        (*p_new_mat).arena[j] = 0;
    }
    return 0;
}

int create_float_matrix(int height, int width, struct FloatCMat* p_new_mat) {
    // create a matrix with 0.0 in shape [height, width]
    int N = height * width;
    (*p_new_mat).data = (float **)malloc(height * sizeof(float *));
    (*p_new_mat).arena = malloc(N * sizeof(float));
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = 0;
    (*p_new_mat).offset[1] = 0;
    for (int i = 0; i < height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width];
    }
    for (int j = 0; j < N; j++) {
        (*p_new_mat).arena[j] = 0.0;
    }
    return 0;
}

int create_double_matrix(int height, int width, struct DoubleCMat* p_new_mat) {
    // create a matrix with 0.0 in shape [height, width]
    int N = height * width;
    (*p_new_mat).data = (double **)malloc(height * sizeof(double *));
    (*p_new_mat).arena = malloc(N * sizeof(double));
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = 0;
    (*p_new_mat).offset[1] = 0;
    for (int i = 0; i < height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width];
    }
    for (int j = 0; j < N; j++) {
        (*p_new_mat).arena[j] = 0.0;
    }
    return 0;
}

int create_int_matrix_from_array(int height, int width, int* array, int array_length, int offset[2], struct IntCMat* p_new_mat) {
    // create a matrix with shape [height, width] at the slice [offset[0]:offset[0]+height, offset[1]:offset[1]+width] of array
    if (height * width != array_length) {
        return -1;
    }
    (*p_new_mat).data = (int **)malloc(height * sizeof(int *));
    (*p_new_mat).arena = array;
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width + offset[1]];
    }
    return 0;
}

int create_float_matrix_from_array(int height, int width, float* array, int array_length, int offset[2], struct FloatCMat* p_new_mat) {
    // create a matrix with shape [height, width] at the slice [offset[0]:offset[0]+height, offset[1]:offset[1]+width] of array
    if (height * width != array_length) {
        return -1;
    }
    (*p_new_mat).data = (float **)malloc(height * sizeof(float *));
    (*p_new_mat).arena = array;
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width + offset[1]];
    }
    return 0;
}

int create_double_matrix_from_array(int height, int width, double* array, int array_length, int offset[2], struct DoubleCMat* p_new_mat) {
    // create a matrix with shape [height, width] at the slice [offset[0]:offset[0]+height, offset[1]:offset[1]+width] of array
    if (height * width != array_length) {
        return -1;
    }
    (*p_new_mat).data = (double **)malloc(height * sizeof(double *));
    (*p_new_mat).arena = array;
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width + offset[1]];
    }
    return 0;
}

int create_int_matrix_from_stack(int height, int width, int array[], int array_length, int offset[2], struct IntCMat* p_new_mat) {
    // create a matrix with shape [height, width] at the slice [offset[0]:offset[0]+height, offset[1]:offset[1]+width] of array
    if (height * width != array_length) {
        return -1;
    }
    (*p_new_mat).data = (int **)malloc(height * sizeof(int *));
    (*p_new_mat).arena = (int *)array;
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width + offset[1]];
    }
    return 0;
}

int create_float_matrix_from_stack(int height, int width, float array[], int array_length, int offset[2], struct FloatCMat* p_new_mat) {
    // create a matrix with shape [height, width] at the slice [offset[0]:offset[0]+height, offset[1]:offset[1]+width] of array
    if (height * width != array_length) {
        return -1;
    }
    (*p_new_mat).data = (float **)malloc(height * sizeof(float *));
    (*p_new_mat).arena = (float *)array;
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width + offset[1]];
    }
    return 0;
}

int create_double_matrix_from_stack(int height, int width, double array[], int array_length, int offset[2], struct DoubleCMat* p_new_mat) {
    // create a matrix with shape [height, width] at the slice [offset[0]:offset[0]+height, offset[1]:offset[1]+width] of array
    if (height * width != array_length) {
        return -1;
    }
    (*p_new_mat).data = (double **)malloc(height * sizeof(double *));
    (*p_new_mat).arena = (double *)array;
    (*p_new_mat).shape[0] = height;
    (*p_new_mat).shape[1] = width;
    (*p_new_mat).arena_shape[0] = height;
    (*p_new_mat).arena_shape[1] = width;
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + height; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * width + offset[1]];
    }
    return 0;
}

struct IntCMat slice_int_matrix(struct IntCMat mat, int slice0[2], int slice1[2]) {
    struct IntCMat empty_mat;
    empty_mat.data = NULL;
    empty_mat.arena = NULL;
    empty_mat.shape[0] = 0;
    empty_mat.shape[1] = 0;
    empty_mat.arena_shape[0] = 0;
    empty_mat.arena_shape[1] = 0;
    empty_mat.offset[0] = 0;
    empty_mat.offset[1] = 0;
    if (slice0[1] < 0) {
        slice0[1] += mat.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += mat.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1]) {
        return empty_mat;
    }
    slice0[1] = MIN(slice0[1], mat.shape[0]);
    slice1[1] = MIN(slice1[1], mat.shape[1]);
    struct IntCMat new_mat;
    int shape[2] = {slice0[1] - slice0[0], slice1[1] - slice1[0]};
    new_mat.data = (int **)malloc(shape[0] * sizeof(int *));
    new_mat.arena = mat.arena;
    new_mat.shape[0] = shape[0];
    new_mat.shape[1] = shape[1];
    new_mat.arena_shape[0] = mat.arena_shape[0];
    new_mat.arena_shape[1] = mat.arena_shape[1];
    int offset[2] = {mat.offset[0] + slice0[0], mat.offset[1] + slice1[0]};
    new_mat.offset[0] = offset[0];
    new_mat.offset[1] = offset[1];
    for (int i = 0; i < shape[0]; i++) {
        int arenai = i + offset[0];
        new_mat.data[i] = &mat.arena[arenai * new_mat.arena_shape[1] + offset[1]];
    }
    return new_mat;
}

struct FloatCMat slice_float_matrix(struct FloatCMat mat, int slice0[2], int slice1[2]) {
    struct FloatCMat empty_mat;
    empty_mat.data = NULL;
    empty_mat.arena = NULL;
    empty_mat.shape[0] = 0;
    empty_mat.shape[1] = 0;
    empty_mat.arena_shape[0] = 0;
    empty_mat.arena_shape[1] = 0;
    empty_mat.offset[0] = 0;
    empty_mat.offset[1] = 0;
    if (slice0[1] < 0) {
        slice0[1] += mat.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += mat.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1]) {
        return empty_mat;
    }
    slice0[1] = MIN(slice0[1], mat.shape[0]);
    slice1[1] = MIN(slice1[1], mat.shape[1]);
    struct FloatCMat new_mat;
    int shape[2] = {slice0[1] - slice0[0], slice1[1] - slice1[0]};
    new_mat.data = (float **)malloc(shape[0] * sizeof(float *));
    new_mat.arena = mat.arena;
    new_mat.shape[0] = shape[0];
    new_mat.shape[1] = shape[1];
    new_mat.arena_shape[0] = mat.arena_shape[0];
    new_mat.arena_shape[1] = mat.arena_shape[1];
    int offset[2] = {mat.offset[0] + slice0[0], mat.offset[1] + slice1[0]};
    new_mat.offset[0] = offset[0];
    new_mat.offset[1] = offset[1];
    for (int i = 0; i < shape[0]; i++) {
        int arenai = i + offset[0];
        new_mat.data[i] = &mat.arena[arenai * new_mat.arena_shape[1] + offset[1]];
    }
    return new_mat;
}

struct DoubleCMat slice_double_matrix(struct DoubleCMat mat, int slice0[2], int slice1[2]) {
    struct DoubleCMat empty_mat;
    empty_mat.data = NULL;
    empty_mat.arena = NULL;
    empty_mat.shape[0] = 0;
    empty_mat.shape[1] = 0;
    empty_mat.arena_shape[0] = 0;
    empty_mat.arena_shape[1] = 0;
    empty_mat.offset[0] = 0;
    empty_mat.offset[1] = 0;
    if (slice0[1] < 0) {
        slice0[1] += mat.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += mat.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1]) {
        return empty_mat;
    }
    slice0[1] = MIN(slice0[1], mat.shape[0]);
    slice1[1] = MIN(slice1[1], mat.shape[1]);
    struct DoubleCMat new_mat;
    int shape[2] = {slice0[1] - slice0[0], slice1[1] - slice1[0]};
    new_mat.data = (double **)malloc(shape[0] * sizeof(double *));
    new_mat.arena = mat.arena;
    new_mat.shape[0] = shape[0];
    new_mat.shape[1] = shape[1];
    new_mat.arena_shape[0] = mat.arena_shape[0];
    new_mat.arena_shape[1] = mat.arena_shape[1];
    int offset[2] = {mat.offset[0] + slice0[0], mat.offset[1] + slice1[0]};
    new_mat.offset[0] = offset[0];
    new_mat.offset[1] = offset[1];
    for (int i = 0; i < shape[0]; i++) {
        int arenai = i + offset[0];
        new_mat.data[i] = &mat.arena[arenai * new_mat.arena_shape[1] + offset[1]];
    }
    return new_mat;
}

int assign_int_slice(struct IntCMat m1, struct IntCMat m2, int slice0[2], int slice1[2]) {
    if (slice0[1] < 0) {
        slice0[1] += m1.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += m1.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1] || slice0[1] - slice0[0] != m2.shape[0] || slice1[1] - slice1[0] != m2.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m1.data[slice0[0] + i][slice1[0] + j] = m2.data[i][j];
        }
    }
    return 0;
}

int assign_float_slice(struct FloatCMat m1, struct FloatCMat m2, int slice0[2], int slice1[2]) {
    if (slice0[1] < 0) {
        slice0[1] += m1.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += m1.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1] || slice0[1] - slice0[0] != m2.shape[0] || slice1[1] - slice1[0] != m2.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m1.data[slice0[0] + i][slice1[0] + j] = m2.data[i][j];
        }
    }
    return 0;
}

int assign_double_slice(struct DoubleCMat m1, struct DoubleCMat m2, int slice0[2], int slice1[2]) {
    if (slice0[1] < 0) {
        slice0[1] += m1.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += m1.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1] || slice0[1] - slice0[0] != m2.shape[0] || slice1[1] - slice1[0] != m2.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m1.data[slice0[0] + i][slice1[0] + j] = m2.data[i][j];
        }
    }
    return 0;
}

int matadd_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return 0;
}

int matadd_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return 0;
}

int matadd_double(struct DoubleCMat m1, struct DoubleCMat m2, struct DoubleCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return 0;
}

int matsub_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return 0;
}

int matsub_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return 0;
}

int matsub_double(struct DoubleCMat m1, struct DoubleCMat m2, struct DoubleCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return 0;
}

int matelm_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] * m2.data[i][j];
        }
    }
    return 0;
}

int matelm_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] * m2.data[i][j];
        }
    }
    return 0;
}

int matelm_double(struct DoubleCMat m1, struct DoubleCMat m2, struct DoubleCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] * m2.data[i][j];
        }
    }
    return 0;
}

int mateld_int(struct IntCMat m1, struct IntCMat m2, struct IntCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] / m2.data[i][j];
        }
    }
    return 0;
}

int mateld_float(struct FloatCMat m1, struct FloatCMat m2, struct FloatCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] / m2.data[i][j];
        }
    }
    return 0;
}

int mateld_double(struct DoubleCMat m1, struct DoubleCMat m2, struct DoubleCMat m3) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m3.data[i][j] = m1.data[i][j] / m2.data[i][j];
        }
    }
    return 0;
}

int print_int_matrix(struct IntCMat mat) {
    printf("[\n");
    for (int row = 0; row < mat.shape[0]; row++) {
        for (int col = 0; col < mat.shape[1]; col++) {
            printf("%d, ", mat.data[row][col]);
        }
        printf("\n");
    }
    printf("]\n");
    return 0;
}

int print_float_matrix(struct FloatCMat mat) {
    printf("[\n");
    for (int row = 0; row < mat.shape[0]; row++) {
        for (int col = 0; col < mat.shape[1]; col++) {
            printf("%f, ", mat.data[row][col]);
        }
        printf("\n");
    }
    printf("]\n");
    return 0;
}

int print_double_matrix(struct DoubleCMat mat) {
    printf("[\n");
    for (int row = 0; row < mat.shape[0]; row++) {
        for (int col = 0; col < mat.shape[1]; col++) {
            printf("%f, ", mat.data[row][col]);
        }
        printf("\n");
    }
    printf("]\n");
    return 0;
}

int free_int_matrix(struct IntCMat m) {
    free(m.data);
    free(m.arena);
    return 0;
}

int free_float_matrix(struct FloatCMat m) {
    free(m.data);
    free(m.arena);
    return 0;
}

int free_double_matrix(struct DoubleCMat m) {
    free(m.data);
    free(m.arena);
    return 0;
}

#ifndef INCLUDE_CMAT
int main() {
    int rows = 3;
    int cols = 4;

    struct IntCMat array_2d;
    create_int_matrix(rows, cols, &array_2d);
    array_2d.data[1][2] = 10;
    print_int_matrix(array_2d);
    free_int_matrix(array_2d);

    struct DoubleCMat array_double;
    create_double_matrix(rows, cols, &array_double);
    array_double.data[1][2] = 1.487;
    print_double_matrix(array_double);

    int offset[2] = {0, 0};

    struct DoubleCMat array_double3;
    double double_array3[6] = {1.1,2.2,3.3,4.4,5.5,6.6};
    create_double_matrix_from_stack(2, 3, double_array3, 6, offset, &array_double3);
    print_double_matrix(array_double3);

    int assign_slice_double_lr0[2] = {1, 3};
    int assign_slice_double_lr1[2] = {0, 3};
    assign_double_slice(array_double, array_double3, assign_slice_double_lr0, assign_slice_double_lr1);
    print_double_matrix(array_double);
    free_double_matrix(array_double);

    struct IntCMat array_int3;
    int int_array3[6] = {11,22,33,44,55,66};
    create_int_matrix_from_stack(2, 3, int_array3, 6, offset, &array_int3);
    print_int_matrix(array_int3);

    struct DoubleCMat array_double2;
    double* double_array2 = (double*)malloc(6 * sizeof(double));
    for (int i=0; i < 6; i++) {
        double_array2[i] = double_array3[i];
    }
    create_double_matrix_from_array(2, 3, double_array2, 6, offset, &array_double2);
    print_double_matrix(array_double2);
    int slice_double_lr0[2] = {1, 3};
    int slice_double_lr1[2] = {1, -1};
    struct DoubleCMat slice_double2 = slice_double_matrix(array_double2, slice_double_lr0, slice_double_lr1);
    print_double_matrix(slice_double2);
    free_double_matrix(array_double2);

    struct IntCMat array_int2;
    int* int_array2 = (int*)malloc(6 * sizeof(int));
    for (int i=0; i < 6; i++) {
        int_array2[i] = int_array3[i];
    }
    create_int_matrix_from_array(2, 3, int_array2, 6, offset, &array_int2);
    print_int_matrix(array_int2);
    int slice_lr0[2] = {0, -1};
    int slice_lr1[2] = {1, -1};
    struct IntCMat slice_int2 = slice_int_matrix(array_int2, slice_lr0, slice_lr1);
    print_int_matrix(slice_int2);
    free_int_matrix(array_int2);

    return 0;
}
#endif
