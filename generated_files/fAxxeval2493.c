#include "stdafx.h"
#include "fAxxeval2493.h"

inline int fAxxeval2493(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx735.data[0][0], 0, sizeof(bmats.Axx735.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1949, bmats.Axx549, bmats.Axx550, bmats.Axx663, bmats.Axx664, bmats.Axx669, bmats.Axx670, bmats.Axx673, bmats.Axx674, bmats.Axx676, bmats.Axx677, bmats.Axx683, bmats.Axx704, bmats.Axx705, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx735, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}