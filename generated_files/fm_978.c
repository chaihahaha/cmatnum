#include "fm_978.h"

inline int fm_978(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_23_16.data[i][j] - 16*bmats.A_9_7.data[i][j] + bmats.A_9_8.data[i][j] + bmats.Ax1409.data[i][j] + bmats.Ax3180.data[i][j] + bmats.Ax3252.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_9.data[i][j] - bmats.B_11_9.data[i][j] - bmats.B_12_9.data[i][j] - bmats.B_13_9.data[i][j] - bmats.B_14_9.data[i][j] - bmats.B_15_9.data[i][j] - bmats.B_16_9.data[i][j] - bmats.B_1_9.data[i][j] + bmats.B_25_7.data[i][j] - bmats.B_2_9.data[i][j] - bmats.B_3_9.data[i][j] - bmats.B_4_9.data[i][j] - bmats.B_5_9.data[i][j] - bmats.B_6_9.data[i][j] - bmats.B_7_17.data[i][j] - bmats.B_7_18.data[i][j] - bmats.B_7_19.data[i][j] - bmats.B_7_20.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_7_22.data[i][j] - bmats.B_7_23.data[i][j] - bmats.B_7_24.data[i][j] - bmats.B_7_25.data[i][j] - bmats.B_7_26.data[i][j] - bmats.B_7_27.data[i][j] - bmats.B_7_28.data[i][j] - bmats.B_7_29.data[i][j] - bmats.B_7_30.data[i][j] - bmats.B_7_31.data[i][j] - bmats.B_7_32.data[i][j] - bmats.B_7_9.data[i][j] - bmats.B_8_9.data[i][j] - bmats.B_9_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
