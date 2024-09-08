#include "fm_464.h"

inline int fm_464(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -17*bmats.A_23_29.data[i][j] - 16*bmats.A_24_29.data[i][j] + bmats.A_24_30.data[i][j] + 17*bmats.A_29_23.data[i][j] + bmats.Ax1097.data[i][j] + bmats.Ax2107.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_29.data[i][j] - bmats.B_18_29.data[i][j] - bmats.B_19_29.data[i][j] - bmats.B_20_29.data[i][j] - bmats.B_21_29.data[i][j] - bmats.B_22_29.data[i][j] - bmats.B_23_17.data[i][j] - bmats.B_23_18.data[i][j] - bmats.B_23_19.data[i][j] - bmats.B_23_20.data[i][j] - bmats.B_23_21.data[i][j] - bmats.B_23_22.data[i][j] - bmats.B_23_23.data[i][j] - bmats.B_23_24.data[i][j] - bmats.B_23_25.data[i][j] - bmats.B_23_26.data[i][j] - bmats.B_23_27.data[i][j] - bmats.B_23_28.data[i][j] - 2*bmats.B_23_29.data[i][j] - bmats.B_23_30.data[i][j] - bmats.B_23_31.data[i][j] - bmats.B_23_32.data[i][j] - bmats.B_24_29.data[i][j] - bmats.B_25_29.data[i][j] - bmats.B_26_29.data[i][j] - bmats.B_27_29.data[i][j] - bmats.B_28_29.data[i][j] + bmats.B_29_23.data[i][j] - bmats.B_29_29.data[i][j] - bmats.B_30_29.data[i][j] - bmats.B_31_29.data[i][j] - bmats.B_32_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
