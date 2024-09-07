#include "fm_1768.h"

inline int fm_1768(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_10_1.data[i][j] + bmats.A_10_10.data[i][j] + bmats.A_10_11.data[i][j] + bmats.A_10_2.data[i][j] + bmats.A_10_3.data[i][j] + bmats.A_10_4.data[i][j] + bmats.A_10_5.data[i][j] + bmats.A_10_6.data[i][j] + bmats.A_10_7.data[i][j] + bmats.A_10_8.data[i][j] + bmats.A_10_9.data[i][j] - bmats.A_11_12.data[i][j] - bmats.A_11_13.data[i][j] - bmats.A_11_14.data[i][j] - bmats.A_11_15.data[i][j] - bmats.A_11_16.data[i][j] - bmats.A_11_17.data[i][j] - bmats.A_11_18.data[i][j] - bmats.A_11_19.data[i][j] - bmats.A_11_20.data[i][j] + 11*bmats.A_11_21.data[i][j] - bmats.A_11_22.data[i][j] - bmats.A_12_1.data[i][j] - bmats.A_12_10.data[i][j] + 11*bmats.A_12_11.data[i][j] - bmats.A_12_2.data[i][j] - bmats.A_12_3.data[i][j] - bmats.A_12_4.data[i][j] - bmats.A_12_5.data[i][j] - bmats.A_12_6.data[i][j] - bmats.A_12_7.data[i][j] - bmats.A_12_8.data[i][j] - bmats.A_12_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_21_1.data[i][j]+bmats.B_11_10.data[i][j]+bmats.B_1_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_10.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
