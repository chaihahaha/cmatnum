#include "fm_1785.h"

inline int fm_1785(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_1.data[i][j] - bmats.A_12_10.data[i][j] - bmats.A_12_11.data[i][j] + 11*bmats.A_12_2.data[i][j] - bmats.A_12_3.data[i][j] - bmats.A_12_4.data[i][j] - bmats.A_12_5.data[i][j] - bmats.A_12_6.data[i][j] - bmats.A_12_7.data[i][j] - bmats.A_12_8.data[i][j] - bmats.A_12_9.data[i][j] - bmats.A_2_12.data[i][j] - bmats.A_2_13.data[i][j] - bmats.A_2_14.data[i][j] - bmats.A_2_15.data[i][j] - bmats.A_2_16.data[i][j] - bmats.A_2_17.data[i][j] - bmats.A_2_18.data[i][j] - bmats.A_2_19.data[i][j] + 11*bmats.A_2_20.data[i][j] - bmats.A_2_21.data[i][j] - bmats.A_2_22.data[i][j] - 11*bmats.A_9_1.data[i][j] + bmats.A_9_10.data[i][j] + bmats.A_9_11.data[i][j] + bmats.A_9_2.data[i][j] + bmats.A_9_3.data[i][j] + bmats.A_9_4.data[i][j] + bmats.A_9_5.data[i][j] + bmats.A_9_6.data[i][j] + bmats.A_9_7.data[i][j] + bmats.A_9_8.data[i][j] + bmats.A_9_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_20_1.data[i][j]+bmats.B_2_9.data[i][j]+bmats.B_1_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_9.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
