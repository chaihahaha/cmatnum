#include "fm_1969.h"

inline int fm_1969(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_17_26.data[i][j] - 17*bmats.A_26_17.data[i][j] - 16*bmats.A_27_17.data[i][j] + bmats.A_27_18.data[i][j] + bmats.Ax4825.data[i][j] + bmats.Ax64.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_17.data[i][j] + bmats.B_17_26.data[i][j] - bmats.B_18_17.data[i][j] - bmats.B_19_17.data[i][j] - bmats.B_20_17.data[i][j] - bmats.B_21_17.data[i][j] - bmats.B_22_17.data[i][j] - bmats.B_23_17.data[i][j] - bmats.B_24_17.data[i][j] - bmats.B_25_17.data[i][j] - 2*bmats.B_26_17.data[i][j] - bmats.B_26_18.data[i][j] - bmats.B_26_19.data[i][j] - bmats.B_26_20.data[i][j] - bmats.B_26_21.data[i][j] - bmats.B_26_22.data[i][j] - bmats.B_26_23.data[i][j] - bmats.B_26_24.data[i][j] - bmats.B_26_25.data[i][j] - bmats.B_26_26.data[i][j] - bmats.B_26_27.data[i][j] - bmats.B_26_28.data[i][j] - bmats.B_26_29.data[i][j] - bmats.B_26_30.data[i][j] - bmats.B_26_31.data[i][j] - bmats.B_26_32.data[i][j] - bmats.B_27_17.data[i][j] - bmats.B_28_17.data[i][j] - bmats.B_29_17.data[i][j] - bmats.B_30_17.data[i][j] - bmats.B_31_17.data[i][j] - bmats.B_32_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}