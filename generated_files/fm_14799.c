#include "fm_14799.h"

inline int fm_14799(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -17*bmats.A_25_31.data[i][j] - 16*bmats.A_26_31.data[i][j] + bmats.A_26_32.data[i][j] + 17*bmats.A_31_25.data[i][j] + bmats.Ax627.data[i][j] + bmats.Ax8485.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_31.data[i][j] - bmats.B_18_31.data[i][j] - bmats.B_19_31.data[i][j] - bmats.B_20_31.data[i][j] - bmats.B_21_31.data[i][j] - bmats.B_22_31.data[i][j] - bmats.B_23_31.data[i][j] - bmats.B_24_31.data[i][j] - bmats.B_25_17.data[i][j] - bmats.B_25_18.data[i][j] - bmats.B_25_19.data[i][j] - bmats.B_25_20.data[i][j] - bmats.B_25_21.data[i][j] - bmats.B_25_22.data[i][j] - bmats.B_25_23.data[i][j] - bmats.B_25_24.data[i][j] - bmats.B_25_25.data[i][j] - bmats.B_25_26.data[i][j] - bmats.B_25_27.data[i][j] - bmats.B_25_28.data[i][j] - bmats.B_25_29.data[i][j] - bmats.B_25_30.data[i][j] - 2*bmats.B_25_31.data[i][j] - bmats.B_25_32.data[i][j] - bmats.B_26_31.data[i][j] - bmats.B_27_31.data[i][j] - bmats.B_28_31.data[i][j] - bmats.B_29_31.data[i][j] - bmats.B_30_31.data[i][j] + bmats.B_31_25.data[i][j] - bmats.B_31_31.data[i][j] - bmats.B_32_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
