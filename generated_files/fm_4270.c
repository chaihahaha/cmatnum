#include "fm_4270.h"

inline int fm_4270(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_14_12.data[i][j] + bmats.A_14_13.data[i][j] + bmats.A_14_14.data[i][j] + bmats.A_14_15.data[i][j] - 11*bmats.A_14_16.data[i][j] + bmats.A_14_17.data[i][j] + bmats.A_14_18.data[i][j] + bmats.A_14_19.data[i][j] + bmats.A_14_20.data[i][j] + bmats.A_14_21.data[i][j] + bmats.A_14_22.data[i][j] - bmats.A_21_2.data[i][j] + 11*bmats.A_21_3.data[i][j] + 11*bmats.A_5_21.data[i][j] - bmats.A_5_22.data[i][j] - bmats.Ax1344.data[i][j] - bmats.Ax786.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_16_10.data[i][j] + bmats.B_21_14.data[i][j] + bmats.B_3_16.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
