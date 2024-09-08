#include "fm_4330.h"

inline int fm_4330(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_14_12.data[i][j] - 11*bmats.A_14_13.data[i][j] - bmats.A_14_2.data[i][j] + bmats.A_14_20.data[i][j] + 11*bmats.A_14_3.data[i][j] - bmats.A_2_13.data[i][j] + 11*bmats.A_2_14.data[i][j] - bmats.Ax1350.data[i][j] - bmats.Ax1375.data[i][j] - bmats.Ax3312.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_13_3.data[i][j] + bmats.B_14_14.data[i][j] + bmats.B_3_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
