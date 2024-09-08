#include "fm_503.h"

inline int fm_503(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_10.data[i][j] - bmats.A_19_11.data[i][j] + 11*bmats.A_1_19.data[i][j] - bmats.A_1_20.data[i][j] - bmats.Ax1812.data[i][j] - bmats.Ax1815.data[i][j] - bmats.Ax1851.data[i][j] - bmats.Ax663.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_12.data[i][j] - bmats.B_11_12.data[i][j] + bmats.B_12_8.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_19_15.data[i][j] - bmats.B_19_16.data[i][j] - bmats.B_19_17.data[i][j] - bmats.B_19_18.data[i][j] - bmats.B_19_19.data[i][j] - bmats.B_19_20.data[i][j] - bmats.B_19_21.data[i][j] - bmats.B_19_22.data[i][j] - bmats.B_1_12.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_3_12.data[i][j] - bmats.B_4_12.data[i][j] - bmats.B_5_12.data[i][j] - bmats.B_6_12.data[i][j] - bmats.B_7_12.data[i][j] - bmats.B_8_12.data[i][j] - bmats.B_9_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
