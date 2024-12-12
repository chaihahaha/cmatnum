#include "stdafx.h"
#include "fm_263.h"

inline int fm_263(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx3203, bmats.Axx633, bmats.Axx972, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_14_14, bmats.B_14_30, bmats.Bx730, bmats.Bx762, bmats.Bx763, bmats.Bx764, bmats.Bx765, bmats.Bx766, bmats.Bx767, bmats.Bx768, bmats.Bx769, bmats.Bx770, bmats.Bx771, bmats.Bx772, bmats.Bx773, bmats.Bx774, bmats.Bx775, bmats.Bx776, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
