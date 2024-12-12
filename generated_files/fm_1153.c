#include "stdafx.h"
#include "fm_1153.h"

inline int fm_1153(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1797, bmats.Axx2720, bmats.Axx2721, bmats.Axx2723, bmats.Axx2726, bmats.Axx2728, bmats.Axx2729, bmats.Axx2732, bmats.Axx2733, bmats.Axx2736, bmats.Axx2737, bmats.Axx2740, bmats.Axx2741, bmats.Axx2744, bmats.Axx2746, bmats.Axx2752, bmats.Axx2861, bmats.Axx968, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.Bx10153, bmats.Bx10200, bmats.Bx10211, bmats.Bx10212, bmats.Bx10213, bmats.Bx10214, bmats.Bx10215, bmats.Bx10216, bmats.Bx10217, bmats.Bx10218, bmats.Bx10219, bmats.Bx9830, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
