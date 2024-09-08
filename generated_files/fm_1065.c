#include "fm_1065.h"

inline int fm_1065(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_6.data[i][j] - 11*bmats.A_10_7.data[i][j] - bmats.A_18_4.data[i][j] + 11*bmats.A_18_5.data[i][j] + 11*bmats.A_5_21.data[i][j] - bmats.A_5_22.data[i][j] - bmats.Ax2230.data[i][j] - bmats.Ax786.data[i][j] - bmats.Ax923.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_21_7.data[i][j] + bmats.B_5_10.data[i][j] + bmats.B_7_16.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_10.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
