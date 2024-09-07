#include "fm_4911.h"

inline int fm_4911(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_12_12.data[i][j] + bmats.A_12_13.data[i][j] + bmats.A_12_14.data[i][j] + bmats.A_12_15.data[i][j] + bmats.A_12_16.data[i][j] + bmats.A_12_17.data[i][j] + bmats.A_12_18.data[i][j] - 11*bmats.A_12_19.data[i][j] + bmats.A_12_20.data[i][j] + bmats.A_12_21.data[i][j] + bmats.A_12_22.data[i][j] + 11*bmats.A_16_1.data[i][j] - bmats.A_16_10.data[i][j] - bmats.A_16_11.data[i][j] - bmats.A_16_2.data[i][j] - bmats.A_16_3.data[i][j] - bmats.A_16_4.data[i][j] - bmats.A_16_5.data[i][j] - bmats.A_16_6.data[i][j] - bmats.A_16_7.data[i][j] - bmats.A_16_8.data[i][j] - bmats.A_16_9.data[i][j] - bmats.A_8_12.data[i][j] - bmats.A_8_13.data[i][j] - bmats.A_8_14.data[i][j] - bmats.A_8_15.data[i][j] + 11*bmats.A_8_16.data[i][j] - bmats.A_8_17.data[i][j] - bmats.A_8_18.data[i][j] - bmats.A_8_19.data[i][j] - bmats.A_8_20.data[i][j] - bmats.A_8_21.data[i][j] - bmats.A_8_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_19_5.data[i][j]+bmats.B_16_12.data[i][j]+bmats.B_1_19.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
