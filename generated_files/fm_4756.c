#include "fm_4756.h"

inline int fm_4756(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_21.data[i][j] + 16*bmats.A_12_22.data[i][j] - bmats.A_22_11.data[i][j] + 16*bmats.A_22_12.data[i][j] + bmats.A_6_5.data[i][j] - 16*bmats.A_6_6.data[i][j] - bmats.Ax2257.data[i][j] - bmats.Ax2442.data[i][j] - bmats.Ax5601.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_6.data[i][j] + bmats.B_22_6.data[i][j] + bmats.B_6_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_28.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}