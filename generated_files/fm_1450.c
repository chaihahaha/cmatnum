#include "fm_1450.h"

inline int fm_1450(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_1.data[i][j] - bmats.A_15_10.data[i][j] - bmats.A_15_11.data[i][j] - bmats.A_15_2.data[i][j] - bmats.A_15_3.data[i][j] - bmats.A_15_4.data[i][j] - bmats.A_15_5.data[i][j] - bmats.A_15_6.data[i][j] - bmats.A_15_7.data[i][j] - bmats.A_15_8.data[i][j] + 11*bmats.A_15_9.data[i][j] + bmats.A_8_1.data[i][j] + bmats.A_8_10.data[i][j] + bmats.A_8_11.data[i][j] + bmats.A_8_2.data[i][j] + bmats.A_8_3.data[i][j] - 11*bmats.A_8_4.data[i][j] + bmats.A_8_5.data[i][j] + bmats.A_8_6.data[i][j] + bmats.A_8_7.data[i][j] + bmats.A_8_8.data[i][j] + bmats.A_8_9.data[i][j] - bmats.A_9_12.data[i][j] - bmats.A_9_13.data[i][j] - bmats.A_9_14.data[i][j] - bmats.A_9_15.data[i][j] - bmats.A_9_16.data[i][j] - bmats.A_9_17.data[i][j] - bmats.A_9_18.data[i][j] + 11*bmats.A_9_19.data[i][j] - bmats.A_9_20.data[i][j] - bmats.A_9_21.data[i][j] - bmats.A_9_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_19_4.data[i][j]+bmats.B_9_8.data[i][j]+bmats.B_4_20.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_8.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
