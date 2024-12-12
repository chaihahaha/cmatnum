#include "stdafx.h"
#include "fm_481.h"

inline int fm_481(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1659, bmats.Axx1937, bmats.Axx241, bmats.Axx265, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_19_29, bmats.Bx2360, bmats.Bx2493, bmats.Bx3939, bmats.Bx3940, bmats.Bx3941, bmats.Bx3942, bmats.Bx3943, bmats.Bx3944, bmats.Bx3945, bmats.Bx3946, bmats.Bx3947, bmats.Bx3948, bmats.Bx3949, bmats.Bx3950, bmats.Bx3951, bmats.Bx3952, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
