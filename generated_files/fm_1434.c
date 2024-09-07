#include "fm_1434.h"

inline int fm_1434(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_1.data[i][j] + bmats.A_10_10.data[i][j] + bmats.A_10_11.data[i][j] + bmats.A_10_2.data[i][j] + bmats.A_10_3.data[i][j] - 11*bmats.A_10_4.data[i][j] + bmats.A_10_5.data[i][j] + bmats.A_10_6.data[i][j] + bmats.A_10_7.data[i][j] + bmats.A_10_8.data[i][j] + bmats.A_10_9.data[i][j] - bmats.A_15_1.data[i][j] - bmats.A_15_10.data[i][j] - bmats.A_15_11.data[i][j] - bmats.A_15_2.data[i][j] - bmats.A_15_3.data[i][j] - bmats.A_15_4.data[i][j] - bmats.A_15_5.data[i][j] - bmats.A_15_6.data[i][j] + 11*bmats.A_15_7.data[i][j] - bmats.A_15_8.data[i][j] - bmats.A_15_9.data[i][j] - bmats.A_7_12.data[i][j] - bmats.A_7_13.data[i][j] - bmats.A_7_14.data[i][j] - bmats.A_7_15.data[i][j] - bmats.A_7_16.data[i][j] - bmats.A_7_17.data[i][j] - bmats.A_7_18.data[i][j] - bmats.A_7_19.data[i][j] - bmats.A_7_20.data[i][j] + 11*bmats.A_7_21.data[i][j] - bmats.A_7_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_21_4.data[i][j]+bmats.B_7_10.data[i][j]+bmats.B_4_18.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_10.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
