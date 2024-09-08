#include "fm_2571.h"

inline int fm_2571(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_13.data[i][j] + 11*bmats.A_11_14.data[i][j] + 11*bmats.A_14_6.data[i][j] - bmats.A_14_7.data[i][j] + bmats.A_17_13.data[i][j] + bmats.A_17_14.data[i][j] - 11*bmats.A_17_22.data[i][j] - bmats.Ax1360.data[i][j] - bmats.Ax2915.data[i][j] - bmats.Ax95.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_14_17.data[i][j] + bmats.B_22_3.data[i][j] + bmats.B_6_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
