#include "fm_3804.h"

inline int fm_3804(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_17.data[i][j] - bmats.A_14_18.data[i][j] - 16*bmats.A_1_10.data[i][j] + bmats.A_1_9.data[i][j] - bmats.A_26_13.data[i][j] + 16*bmats.A_26_14.data[i][j] - bmats.Ax1766.data[i][j] - bmats.Ax509.data[i][j] - bmats.Ax5362.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_30.data[i][j] + bmats.B_14_1.data[i][j] + bmats.B_17_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_30.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
