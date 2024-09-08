#include "fm_1311.h"

inline int fm_1311(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_22_28.data[i][j] - 17*bmats.A_28_22.data[i][j] + bmats.A_29_21.data[i][j] - 16*bmats.A_29_22.data[i][j] + bmats.Ax2083.data[i][j] + bmats.Ax4010.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_22.data[i][j] - bmats.B_18_22.data[i][j] - bmats.B_19_22.data[i][j] - bmats.B_20_22.data[i][j] - bmats.B_21_22.data[i][j] - bmats.B_22_22.data[i][j] + bmats.B_22_28.data[i][j] - bmats.B_23_22.data[i][j] - bmats.B_24_22.data[i][j] - bmats.B_25_22.data[i][j] - bmats.B_26_22.data[i][j] - bmats.B_27_22.data[i][j] - bmats.B_28_17.data[i][j] - bmats.B_28_18.data[i][j] - bmats.B_28_19.data[i][j] - bmats.B_28_20.data[i][j] - bmats.B_28_21.data[i][j] - 2*bmats.B_28_22.data[i][j] - bmats.B_28_23.data[i][j] - bmats.B_28_24.data[i][j] - bmats.B_28_25.data[i][j] - bmats.B_28_26.data[i][j] - bmats.B_28_27.data[i][j] - bmats.B_28_28.data[i][j] - bmats.B_28_29.data[i][j] - bmats.B_28_30.data[i][j] - bmats.B_28_31.data[i][j] - bmats.B_28_32.data[i][j] - bmats.B_29_22.data[i][j] - bmats.B_30_22.data[i][j] - bmats.B_31_22.data[i][j] - bmats.B_32_22.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
