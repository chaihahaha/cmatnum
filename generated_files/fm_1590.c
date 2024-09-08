#include "fm_1590.h"

inline int fm_1590(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_15.data[i][j] + 11*bmats.A_11_16.data[i][j] - bmats.A_14_10.data[i][j] + 11*bmats.A_14_11.data[i][j] + bmats.A_5_2.data[i][j] - 11*bmats.A_5_3.data[i][j] + bmats.A_5_5.data[i][j] - bmats.Ax2447.data[i][j] - bmats.Ax279.data[i][j] - bmats.Ax953.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_11_5.data[i][j] + bmats.B_16_3.data[i][j] + bmats.B_3_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_5.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
