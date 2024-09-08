#include "fm_283.h"

inline int fm_283(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -17*bmats.A_27_30.data[i][j] + bmats.A_28_29.data[i][j] - 16*bmats.A_28_30.data[i][j] + 17*bmats.A_30_27.data[i][j] + bmats.Ax1088.data[i][j] + bmats.Ax1222.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_30.data[i][j] - bmats.B_18_30.data[i][j] - bmats.B_19_30.data[i][j] - bmats.B_20_30.data[i][j] - bmats.B_21_30.data[i][j] - bmats.B_22_30.data[i][j] - bmats.B_23_30.data[i][j] - bmats.B_24_30.data[i][j] - bmats.B_25_30.data[i][j] - bmats.B_26_30.data[i][j] - bmats.B_27_17.data[i][j] - bmats.B_27_18.data[i][j] - bmats.B_27_19.data[i][j] - bmats.B_27_20.data[i][j] - bmats.B_27_21.data[i][j] - bmats.B_27_22.data[i][j] - bmats.B_27_23.data[i][j] - bmats.B_27_24.data[i][j] - bmats.B_27_25.data[i][j] - bmats.B_27_26.data[i][j] - bmats.B_27_27.data[i][j] - bmats.B_27_28.data[i][j] - bmats.B_27_29.data[i][j] - 2*bmats.B_27_30.data[i][j] - bmats.B_27_31.data[i][j] - bmats.B_27_32.data[i][j] - bmats.B_28_30.data[i][j] - bmats.B_29_30.data[i][j] + bmats.B_30_27.data[i][j] - bmats.B_30_30.data[i][j] - bmats.B_31_30.data[i][j] - bmats.B_32_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
