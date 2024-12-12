#include "stdafx.h"
#include "fm_840.h"

inline int fm_840(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx135, bmats.Axx1889, bmats.Axx2819, bmats.Axx80, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx7726, bmats.Bx7727, bmats.Bx7728, bmats.Bx7729, bmats.Bx7730, bmats.Bx7731, bmats.Bx7732, bmats.Bx7733, bmats.Bx7734, bmats.Bx7735, bmats.Bx7736, bmats.Bx7737, bmats.Bx7738, bmats.Bx7739, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
