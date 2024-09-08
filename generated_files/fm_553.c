#include "fm_553.h"

inline int fm_553(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_25_31.data[i][j] - bmats.A_25_32.data[i][j] + bmats.A_28_10.data[i][j] - 16*bmats.A_28_9.data[i][j] - bmats.Ax2393.data[i][j] - bmats.Ax624.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_12.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_23_12.data[i][j] - bmats.B_24_12.data[i][j] - bmats.B_25_12.data[i][j] - bmats.B_26_12.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_28_12.data[i][j] + bmats.B_28_25.data[i][j] - bmats.B_29_12.data[i][j] - bmats.B_30_12.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_32_12.data[i][j] - bmats.B_9_17.data[i][j] - bmats.B_9_18.data[i][j] - bmats.B_9_19.data[i][j] - bmats.B_9_20.data[i][j] - bmats.B_9_21.data[i][j] - bmats.B_9_22.data[i][j] - bmats.B_9_23.data[i][j] - bmats.B_9_24.data[i][j] - bmats.B_9_25.data[i][j] - bmats.B_9_26.data[i][j] - bmats.B_9_27.data[i][j] - bmats.B_9_28.data[i][j] - bmats.B_9_29.data[i][j] - bmats.B_9_30.data[i][j] - bmats.B_9_31.data[i][j] - bmats.B_9_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
