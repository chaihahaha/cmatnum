#include "fm_5452.h"

inline int fm_5452(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_10_2.data[i][j] - bmats.A_10_3.data[i][j] - bmats.A_2_2.data[i][j] + 11*bmats.A_2_3.data[i][j] + 11*bmats.A_3_10.data[i][j] - bmats.A_3_11.data[i][j] - bmats.Ax1429.data[i][j] - bmats.Ax1439.data[i][j] - bmats.Ax312.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_2.data[i][j] + bmats.B_2_3.data[i][j] + bmats.B_3_10.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
