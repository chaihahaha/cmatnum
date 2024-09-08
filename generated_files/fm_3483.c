#include "fm_3483.h"

inline int fm_3483(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_21.data[i][j] + 16*bmats.A_14_22.data[i][j] - bmats.A_27_13.data[i][j] + 16*bmats.A_27_14.data[i][j] - 16*bmats.A_6_11.data[i][j] + bmats.A_6_12.data[i][j] - bmats.Ax1630.data[i][j] - bmats.Ax488.data[i][j] - bmats.Ax5214.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_30.data[i][j] + bmats.B_14_6.data[i][j] + bmats.B_22_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_30.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
