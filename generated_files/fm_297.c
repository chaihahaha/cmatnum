#include "fm_297.h"

inline int fm_297(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_28_31.data[i][j] - bmats.A_28_32.data[i][j] - 16*bmats.A_30_12.data[i][j] + bmats.A_30_7.data[i][j] - bmats.Ax1336.data[i][j] - bmats.Ax612.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_12_17.data[i][j] - bmats.B_12_18.data[i][j] - bmats.B_12_19.data[i][j] - bmats.B_12_20.data[i][j] - bmats.B_12_21.data[i][j] - bmats.B_12_22.data[i][j] - bmats.B_12_23.data[i][j] - bmats.B_12_24.data[i][j] - bmats.B_12_25.data[i][j] - bmats.B_12_26.data[i][j] - bmats.B_12_27.data[i][j] - bmats.B_12_28.data[i][j] - bmats.B_12_29.data[i][j] - bmats.B_12_30.data[i][j] - bmats.B_12_31.data[i][j] - bmats.B_12_32.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_22_14.data[i][j] - bmats.B_23_14.data[i][j] - bmats.B_24_14.data[i][j] - bmats.B_25_14.data[i][j] - bmats.B_26_14.data[i][j] - bmats.B_27_14.data[i][j] - bmats.B_28_14.data[i][j] - bmats.B_29_14.data[i][j] - bmats.B_30_14.data[i][j] + bmats.B_30_28.data[i][j] - bmats.B_31_14.data[i][j] - bmats.B_32_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
