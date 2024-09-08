#include "fm_802.h"

inline int fm_802(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_10.data[i][j] - bmats.A_10_9.data[i][j] - bmats.A_12_31.data[i][j] - bmats.A_12_32.data[i][j] + 16*bmats.A_1_10.data[i][j] - bmats.A_1_9.data[i][j] - bmats.A_26_11.data[i][j] + 16*bmats.A_26_12.data[i][j] - bmats.Ax2245.data[i][j] - bmats.Ax2941.data[i][j] - bmats.Ax2956.data[i][j] - bmats.Ax2958.data[i][j] - bmats.Ax757.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_28.data[i][j] - bmats.B_12_12.data[i][j] - bmats.B_12_14.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_12_7.data[i][j] - bmats.B_12_9.data[i][j] - bmats.Bx6289.data[i][j] - bmats.Bx7193.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
