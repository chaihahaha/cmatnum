#include "fm_6700.h"

inline int fm_6700(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_25.data[i][j] - bmats.A_14_26.data[i][j] + bmats.A_19_17.data[i][j] + bmats.A_19_18.data[i][j] + bmats.A_19_19.data[i][j] + bmats.A_19_29.data[i][j] - 16*bmats.A_19_30.data[i][j] + 16*bmats.A_25_3.data[i][j] - bmats.A_25_4.data[i][j] - bmats.Ax1489.data[i][j] - bmats.Ax3351.data[i][j] - bmats.Ax6261.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_25_19.data[i][j] + bmats.B_30_9.data[i][j] + bmats.B_3_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}