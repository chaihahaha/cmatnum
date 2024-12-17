#include "cmat.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int is_contiguous_double(double_cmat m) {
    if (m.offset[1] == 0 && m.arena_shape[1] == m.shape[1]) {
        return 1;
    }
    return 0;
}

int create_int_matrix(int shape[2], int_cmat* p_new_mat) {
    // create a matrix with 0 in shape [shape[0], shape[1]]
    int N = shape[0] * shape[1];
    (*p_new_mat).data = (int **)malloc(shape[0] * sizeof(int *));
    (*p_new_mat).arena = malloc(N * sizeof(int));
    (*p_new_mat).shape[0] = shape[0];
    (*p_new_mat).shape[1] = shape[1];
    (*p_new_mat).arena_shape[0] = shape[0];
    (*p_new_mat).arena_shape[1] = shape[1];
    (*p_new_mat).offset[0] = 0;
    (*p_new_mat).offset[1] = 0;
    for (int i = 0; i < shape[0]; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * shape[1]];
    }
    for (int j = 0; j < N; j++) {
        (*p_new_mat).arena[j] = 0;
    }
    return 0;
}

int create_float_matrix(int shape[2], float_cmat* p_new_mat) {
    // create a matrix with 0.0 in shape [shape[0], shape[1]]
    int N = shape[0] * shape[1];
    (*p_new_mat).data = (float **)malloc(shape[0] * sizeof(float *));
    (*p_new_mat).arena = malloc(N * sizeof(float));
    (*p_new_mat).shape[0] = shape[0];
    (*p_new_mat).shape[1] = shape[1];
    (*p_new_mat).arena_shape[0] = shape[0];
    (*p_new_mat).arena_shape[1] = shape[1];
    (*p_new_mat).offset[0] = 0;
    (*p_new_mat).offset[1] = 0;
    for (int i = 0; i < shape[0]; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * shape[1]];
    }
    for (int j = 0; j < N; j++) {
        (*p_new_mat).arena[j] = 0.0;
    }
    return 0;
}

int create_double_matrix(int shape[2], double_cmat* p_new_mat) {
    //printf("create mat\n");
    //printf("shape %d %d\n", shape[0], shape[1]);
    // create a matrix with 0.0 in shape [shape[0], shape[1]]
    int N = shape[0] * shape[1];
    (*p_new_mat).data = (double **)malloc(shape[0] * sizeof(double *));
    (*p_new_mat).arena = malloc(N * sizeof(double));
    (*p_new_mat).shape[0] = shape[0];
    (*p_new_mat).shape[1] = shape[1];
    (*p_new_mat).arena_shape[0] = shape[0];
    (*p_new_mat).arena_shape[1] = shape[1];
    (*p_new_mat).offset[0] = 0;
    (*p_new_mat).offset[1] = 0;
    for (int i = 0; i < shape[0]; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * shape[1]];
    }
    for (int j = 0; j < N; j++) {
        (*p_new_mat).arena[j] = 0.0;
    }
    //printf("create mat finished\n");
    return 0;
}

int create_int_matrix_from_array(int shape[2], int* array, int array_length, int offset[2], int_cmat* p_new_mat) {
    // create a matrix with shape [shape[0], shape[1]] at the slice [offset[0]:offset[0]+shape[0], offset[1]:offset[1]+shape[1]] of array
    if (shape[0] * shape[1] != array_length) {
        return -1;
    }
    (*p_new_mat).data = (int **)malloc(shape[0] * sizeof(int *));
    (*p_new_mat).arena = array;
    (*p_new_mat).shape[0] = shape[0];
    (*p_new_mat).shape[1] = shape[1];
    (*p_new_mat).arena_shape[0] = shape[0];
    (*p_new_mat).arena_shape[1] = shape[1];
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + shape[0]; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * shape[1] + offset[1]];
    }
    return 0;
}

int create_float_matrix_from_array(int shape[2], float* array, int array_length, int offset[2], float_cmat* p_new_mat) {
    // create a matrix with shape [shape[0], shape[1]] at the slice [offset[0]:offset[0]+shape[0], offset[1]:offset[1]+shape[1]] of array
    if (shape[0] * shape[1] != array_length) {
        return -1;
    }
    (*p_new_mat).data = (float **)malloc(shape[0] * sizeof(float *));
    (*p_new_mat).arena = array;
    (*p_new_mat).shape[0] = shape[0];
    (*p_new_mat).shape[1] = shape[1];
    (*p_new_mat).arena_shape[0] = shape[0];
    (*p_new_mat).arena_shape[1] = shape[1];
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + shape[0]; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * shape[1] + offset[1]];
    }
    return 0;
}

int create_double_matrix_from_array(int shape[2], double* array, int array_length, int offset[2], double_cmat* p_new_mat) {
    // create a matrix with shape [shape[0], shape[1]] at the slice [offset[0]:offset[0]+shape[0], offset[1]:offset[1]+shape[1]] of array
    if (shape[0] * shape[1] != array_length) {
        return -1;
    }
    (*p_new_mat).data = (double **)malloc(shape[0] * sizeof(double *));
    (*p_new_mat).arena = array;
    (*p_new_mat).shape[0] = shape[0];
    (*p_new_mat).shape[1] = shape[1];
    (*p_new_mat).arena_shape[0] = shape[0];
    (*p_new_mat).arena_shape[1] = shape[1];
    (*p_new_mat).offset[0] = offset[0];
    (*p_new_mat).offset[1] = offset[1];
    for (int i = offset[0]; i < offset[0] + shape[0]; i++) {
        (*p_new_mat).data[i] = &(*p_new_mat).arena[i * shape[1] + offset[1]];
    }
    return 0;
}

int_cmat slice_int_matrix(int_cmat mat, int slice0[2], int slice1[2]) {
    int_cmat empty_mat;
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
    int_cmat new_mat;
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

float_cmat slice_float_matrix(float_cmat mat, int slice0[2], int slice1[2]) {
    float_cmat empty_mat;
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
    float_cmat new_mat;
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

double_cmat slice_double_matrix(double_cmat mat, int slice0[2], int slice1[2]) {
    //printf("slice double\n");
    double_cmat empty_mat;
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
    double_cmat new_mat;
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

int create_slice_double_matrix_contiguous(double_cmat *dst, double_cmat mat, int slice0[2], int slice1[2]) {
    //printf("slice conting\n");
    // dst = mat[slice0, slice1]
    if (slice0[1] < 0) {
        slice0[1] += mat.shape[0];
    }
    if (slice1[1] < 0) {
        slice1[1] += mat.shape[1];
    }
    if (slice0[0] >= slice0[1] || slice1[0] >= slice1[1]) {
        return -1;
    }
    slice0[1] = MIN(slice0[1], mat.shape[0]);
    slice1[1] = MIN(slice1[1], mat.shape[1]);
    int shape[2] = {slice0[1] - slice0[0], slice1[1] - slice1[0]};
    create_double_matrix(shape, dst);
    int dsti = 0;
    for (int i = slice0[0]; i < slice0[1]; i++) {
        cblas_dcopy(shape[1], &mat.data[i][slice1[0]], 1, dst->data[dsti], 1);
        dsti += 1;
    }
    return 0;
}

int create_double_contiguous_from_slice(double_cmat *dest, double_cmat *src) {
    //printf("create contig from slice\n");
    // dest = src.contiguous().copy()
    int i, j;
    int rows = src->shape[0];
    int cols = src->shape[1];

    // Allocate memory for the new matrix
    dest->arena = (double*)malloc(rows * cols * sizeof(double));
    dest->data = (double**)malloc(rows * sizeof(double*));
    for (i = 0; i < rows; i++) {
        dest->data[i] = &dest->arena[i * cols];
    }
    dest->shape[0] = rows;
    dest->shape[1] = cols;
    dest->arena_shape[0] = rows;
    dest->arena_shape[1] = cols;
    dest->offset[0] = 0;
    dest->offset[1] = 0;

    size_t element_size = sizeof(double);
    // Copy the slice data to the new matrix
    for (i = 0; i < rows; ++i) {
        //memcpy(dest->data[i], src->data[i], cols * element_size);
        cblas_dcopy(cols, src->data[i], 1, dest->data[i], 1);
    }
    return 0;
}

int assign_int_slice(int_cmat m1, int_cmat m2, int slice0[2], int slice1[2]) {
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
        memcpy(&m1.data[slice0[0] + i][slice1[0]],  m2.data[i], sizeof(int) * m2.shape[1]);
        //for (int j = 0; j < m2.shape[1]; j++) {
        //    m1.data[slice0[0] + i][slice1[0] + j] = m2.data[i][j];
        //}
    }
    return 0;
}

int assign_float_slice(float_cmat m1, float_cmat m2, int slice0[2], int slice1[2]) {
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
        memcpy(&m1.data[slice0[0] + i][slice1[0]],  m2.data[i], sizeof(float) * m2.shape[1]);
        //for (int j = 0; j < m2.shape[1]; j++) {
        //    m1.data[slice0[0] + i][slice1[0] + j] = m2.data[i][j];
        //}
    }
    return 0;
}

int assign_double_slice(double_cmat m1, double_cmat m2, int slice0[2], int slice1[2]) {
    //printf("assign slice\n");
    // assign m2 to a slice of m1 defined by slice0(x) and slice1(y)
    // m1[slice0, slice1] = m2
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
        //memcpy(&m1.data[slice0[0] + i][slice1[0]],  m2.data[i], sizeof(double) * m2.shape[1]);
        cblas_dcopy(m2.shape[1], m2.data[i], 1, &m1.data[slice0[0] + i][slice1[0]], 1);
        //for (int j = 0; j < m2.shape[1]; j++) {
        //    m1.data[slice0[0] + i][slice1[0] + j] = m2.data[i][j];
        //}
    }
    return 0;
}

int assign_double_clone(double_cmat m1, double_cmat m2) {
    //printf("assign double clone\n");
    // m1 = m2.copy()
    if (!(m1.shape[0] == m2.shape[0] && m1.shape[1] == m2.shape[1])) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        //memcpy(m1.data[i],  m2.data[i], sizeof(double) * m2.shape[1]);
        cblas_dcopy(m2.shape[1], m2.data[i], 1, m1.data[i], 1);
    }
    return 0;
}

int matlincomb_double_contiguous(double_cmat res, int n_mats, double_cmat* mats, int8_t* coeffs) {
    //printf("lincomb\n");
    // res = coeffs[0] * mats[0] + ... + coeffs[n_mats-1] * mats[n_mats-1]
    // memset(&res.data[0][0], 0, sizeof(res.data[0][0])*res.shape[0]*res.shape[1]); // should not reset because it could appear in RHS
    if (n_mats <= 0) {
        return -1;
    }
    int n_elems = mats[0].shape[0] * mats[0].shape[1];
    for (int i = 0; i < n_mats; i++) {
        cblas_daxpy(n_elems, coeffs[i], &mats[i].data[0][0], 1, &res.data[0][0], 1);
    }
    return 0;
}

int matadd_int(int_cmat m3, int_cmat m1, int_cmat m2) {
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

int matadd_float(float_cmat m3, float_cmat m1, float_cmat m2) {
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

int matadd_double(double_cmat m3, double_cmat m1, double_cmat m2) {
    // m3 = m1 + m2
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    if (m1.data[0] == m3.data[0]) {
        // m3 = m3 + m2
        for (int i = 0; i < m2.shape[0]; i++) {
            cblas_daxpy(m3.shape[1], 1.0, m2.data[i], 1, m3.data[i], 1);
        }
    }
    else if (m2.data[0] == m3.data[0]) {
        // m3 = m1 + m3
        for (int i = 0; i < m2.shape[0]; i++) {
            cblas_daxpy(m3.shape[1], 1.0, m1.data[i], 1, m3.data[i], 1);
        }
    }
    else {
        for (int i = 0; i < m2.shape[0]; i++) {
            //for (int j = 0; j < m2.shape[1]; j++) {
            //    m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
            //}
            cblas_dcopy(m3.shape[1], m1.data[i], 1, m3.data[i], 1);
            cblas_daxpy(m3.shape[1], 1.0, m2.data[i], 1, m3.data[i], 1);
        }
    }
    return 0;
}

int matsub_int(int_cmat m3, int_cmat m1, int_cmat m2) {
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

int matsub_float(float_cmat m3, float_cmat m1, float_cmat m2) {
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

int matsub_double(double_cmat m3, double_cmat m1, double_cmat m2) {
    // m3 = m1 - m2
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    if (m1.shape[0] != m3.shape[0] || m1.shape[1] != m3.shape[1]) {
        return -1;
    }
    if (m1.data[0] == m3.data[0]) {
        // m3 = m3 - m2
        for (int i = 0; i < m2.shape[0]; i++) {
            cblas_daxpy(m3.shape[1], -1.0, m2.data[i], 1, m3.data[i], 1);
        }
    }
    else if (m2.data[0] == m3.data[0]) {
        // m3 = m1 - m3
        double *tmp2 = (double*) malloc(m3.shape[1] * sizeof(double));
        for (int i = 0; i < m2.shape[0]; i++) {
            cblas_dcopy(m3.shape[1], m2.data[i], 1, tmp2, 1);
            cblas_dcopy(m3.shape[1], m1.data[i], 1, m3.data[i], 1);
            cblas_daxpy(m3.shape[1], -1.0, tmp2, 1, m3.data[i], 1);
        }
        free(tmp2);
    }
    else {
        for (int i = 0; i < m2.shape[0]; i++) {
            //for (int j = 0; j < m2.shape[1]; j++) {
            //    m3.data[i][j] = m1.data[i][j] - m2.data[i][j];
            //}

            cblas_dcopy(m3.shape[1], m1.data[i], 1, m3.data[i], 1);
            cblas_daxpy(m3.shape[1], -1.0, m2.data[i], 1, m3.data[i], 1);
        }
    }
    return 0;
}

int matelm_int(int_cmat m3, int_cmat m1, int_cmat m2) {
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

int matelm_float(float_cmat m3, float_cmat m1, float_cmat m2) {
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

int matelm_double(double_cmat m3, double_cmat m1, double_cmat m2) {
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

int mateld_int(int_cmat m3, int_cmat m1, int_cmat m2) {
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

int mateld_float(float_cmat m3, float_cmat m1, float_cmat m2) {
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

int mateld_double(double_cmat m3, double_cmat m1, double_cmat m2) {
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

int matneg_double(double_cmat m2, double_cmat m1) {
    if (m1.shape[0] != m2.shape[0] || m1.shape[1] != m2.shape[1]) {
        return -1;
    }
    for (int i = 0; i < m2.shape[0]; i++) {
        for (int j = 0; j < m2.shape[1]; j++) {
            m2.data[i][j] = -m1.data[i][j];
        }
    }
    return 0;
}

int print_int_matrix(int_cmat mat) {
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

int print_float_matrix(float_cmat mat) {
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

int print_double_matrix(double_cmat mat) {
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

int free_int_matrix(int_cmat m) {
    free(m.data);
    if (m.arena_shape[0] == m.shape[0] && m.arena_shape[1] == m.shape[1]) {
        free(m.arena);
    }
    return 0;
}

int free_float_matrix(float_cmat m) {
    free(m.data);
    if (m.arena_shape[0] == m.shape[0] && m.arena_shape[1] == m.shape[1]) {
        free(m.arena);
    }
    return 0;
}

int free_double_matrix(double_cmat m) {
    //printf("free\n");
    free(m.data);
    if (m.arena_shape[0] == m.shape[0] && m.arena_shape[1] == m.shape[1]) {
        free(m.arena);
    }
    return 0;
}

#ifdef MAIN_CMAT
int main() {
    int rows = 3;
    int cols = 4;

    int_cmat array_2d;
    create_int_matrix(pairint {rows, cols}, &array_2d);
    array_2d.data[1][2] = 10;
    print_int_matrix(array_2d);
    free_int_matrix(array_2d);

    double_cmat array_double;
    create_double_matrix(pairint {rows, cols}, &array_double);
    array_double.data[1][2] = 1.487;
    print_double_matrix(array_double);

    double_cmat array_double3;
    double double_array3[6] = {1.1,2.2,3.3,4.4,5.5,6.6};
    create_double_matrix_from_array(pairint {2, 2}, double_array3, 4, pairint {0, 0}, &array_double3);
    print_double_matrix(array_double3);

    assign_double_slice(array_double, array_double3, pairint {1, 3}, pairint {0, 2});
    print_double_matrix(array_double);
    free_double_matrix(array_double);

    int_cmat array_int3;
    int int_array3[6] = {11,22,33,44,55,66};
    create_int_matrix_from_array(pairint {2, 3}, int_array3, 6, pairint {0, 0}, &array_int3);
    print_int_matrix(array_int3);

    double_cmat array_double2;
    double* double_array2 = (double*)malloc(6 * sizeof(double));
    for (int i=0; i < 6; i++) {
        double_array2[i] = double_array3[i];
    }
    create_double_matrix_from_array(pairint {2, 3}, double_array2, 6, pairint {0, 0}, &array_double2);
    print_double_matrix(array_double2);
    int slice_double_lr0[2] = {1, 3};
    int slice_double_lr1[2] = {1, -1};
    double_cmat slice_double2 = slice_double_matrix(array_double2, slice_double_lr0, slice_double_lr1);
    print_double_matrix(slice_double2);
    free_double_matrix(array_double2);

    int_cmat array_int2;
    int* int_array2 = (int*)malloc(6 * sizeof(int));
    for (int i=0; i < 6; i++) {
        int_array2[i] = int_array3[i];
    }
    create_int_matrix_from_array(pairint {2, 3}, int_array2, 6, pairint {0, 0}, &array_int2);
    print_int_matrix(array_int2);
    int_cmat slice_int2 = slice_int_matrix(array_int2, pairint {0, -1}, pairint {1, -1});
    print_int_matrix(slice_int2);
    free_int_matrix(array_int2);

    return 0;
}
#endif
