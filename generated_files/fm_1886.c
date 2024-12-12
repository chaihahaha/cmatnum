#include "stdafx.h"
#include "fm_1886.h"

inline int fm_1886(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1887, bmats.Axx2717, bmats.Axx835, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx10338, bmats.Bx11717, bmats.Bx12144, bmats.Bx12539, bmats.Bx12812, bmats.Bx12813, bmats.Bx12814, bmats.Bx12815, bmats.Bx3104, bmats.Bx4612, bmats.Bx6899, bmats.Bx817, bmats.Bx8202, bmats.Bx8663, bmats.Bx9752, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
