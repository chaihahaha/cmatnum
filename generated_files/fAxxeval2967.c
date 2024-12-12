#include "stdafx.h"
#include "fAxxeval2967.h"

inline int fAxxeval2967(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx853.data[0][0], 0, sizeof(bmats.Axx853.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx476, bmats.Axx831, bmats.Axx871, bmats.Axx872, bmats.Axx875, bmats.Axx876, bmats.Axx877, bmats.Axx878, bmats.Axx879, bmats.Axx880, bmats.Axx881, bmats.Axx882, bmats.Axx883, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx853, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
