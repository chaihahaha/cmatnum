#include "fm_7358.h"

inline int fm_7358(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_21_17.data[i][j] - 16*bmats.A_21_18.data[i][j] + bmats.A_21_24.data[i][j] + 16*bmats.A_25_5.data[i][j] - bmats.A_25_6.data[i][j] + 16*bmats.A_2_25.data[i][j] - bmats.A_2_26.data[i][j] - bmats.Ax2872.data[i][j] - bmats.Ax3309.data[i][j] - bmats.Ax6050.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_9.data[i][j] + bmats.B_25_21.data[i][j] + bmats.B_5_18.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}