#include "fm_1595.h"

inline int fm_1595(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_4.data[i][j] + 11*bmats.A_14_5.data[i][j] + 11*bmats.A_5_17.data[i][j] - bmats.A_5_18.data[i][j] + bmats.A_6_2.data[i][j] - 11*bmats.A_6_3.data[i][j] - bmats.Ax150.data[i][j] - bmats.Ax2437.data[i][j] - bmats.Ax938.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_17_3.data[i][j] + bmats.B_3_16.data[i][j] + bmats.B_5_6.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_6.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
