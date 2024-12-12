#include "stdafx.h"
#include "fm_987.h"

inline int fm_987(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1995, bmats.Axx2545, bmats.Axx519, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.Bx8436, bmats.Bx8939, bmats.Bx8963, bmats.Bx8964, bmats.Bx8965, bmats.Bx8966, bmats.Bx8967, bmats.Bx8968, bmats.Bx8969, bmats.Bx8970, bmats.Bx8971, bmats.Bx8972, bmats.Bx8973, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
