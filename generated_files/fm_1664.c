#include "fm_1664.h"

inline int fm_1664(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_1.data[i][j] + bmats.A_10_10.data[i][j] + bmats.A_10_11.data[i][j] - 11*bmats.A_10_2.data[i][j] + bmats.A_10_3.data[i][j] + bmats.A_10_4.data[i][j] + bmats.A_10_5.data[i][j] + bmats.A_10_6.data[i][j] + bmats.A_10_7.data[i][j] + bmats.A_10_8.data[i][j] + bmats.A_10_9.data[i][j] - bmats.A_13_1.data[i][j] - bmats.A_13_10.data[i][j] - bmats.A_13_11.data[i][j] - bmats.A_13_2.data[i][j] - bmats.A_13_3.data[i][j] - bmats.A_13_4.data[i][j] + 11*bmats.A_13_5.data[i][j] - bmats.A_13_6.data[i][j] - bmats.A_13_7.data[i][j] - bmats.A_13_8.data[i][j] - bmats.A_13_9.data[i][j] - bmats.A_5_12.data[i][j] - bmats.A_5_13.data[i][j] - bmats.A_5_14.data[i][j] - bmats.A_5_15.data[i][j] - bmats.A_5_16.data[i][j] - bmats.A_5_17.data[i][j] - bmats.A_5_18.data[i][j] - bmats.A_5_19.data[i][j] - bmats.A_5_20.data[i][j] + 11*bmats.A_5_21.data[i][j] - bmats.A_5_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_21_2.data[i][j]+bmats.B_5_10.data[i][j]+bmats.B_2_16.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_10.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
