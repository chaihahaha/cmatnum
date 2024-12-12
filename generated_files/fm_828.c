#include "stdafx.h"
#include "fm_828.h"

inline int fm_828(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2716, bmats.Axx319, bmats.Axx3240, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_9_26, bmats.Bx6541, bmats.Bx7181, bmats.Bx7605, bmats.Bx7606, bmats.Bx7607, bmats.Bx7608, bmats.Bx7609, bmats.Bx7610, bmats.Bx7611, bmats.Bx7612, bmats.Bx7613, bmats.Bx7614, bmats.Bx7615, bmats.Bx7616, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
