#include "fm_12092.h"

inline int fm_12092(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_31_15.data[i][j] - bmats.A_31_16.data[i][j] - 16*bmats.A_31_19.data[i][j] + bmats.A_31_31.data[i][j] + 16*bmats.A_3_31.data[i][j] - bmats.A_3_32.data[i][j] - bmats.Ax679.data[i][j] - bmats.Ax775.data[i][j] - bmats.Ax7880.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_19.data[i][j] + bmats.B_19_15.data[i][j] + bmats.B_31_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
