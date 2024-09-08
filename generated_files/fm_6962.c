#include "fm_6962.h"

inline int fm_6962(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_19.data[i][j] + 16*bmats.A_15_20.data[i][j] - bmats.A_20_5.data[i][j] + 16*bmats.A_20_6.data[i][j] + bmats.A_22_17.data[i][j] + bmats.A_22_22.data[i][j] - 16*bmats.A_22_31.data[i][j] + bmats.A_22_32.data[i][j] - bmats.Ax3985.data[i][j] - bmats.Ax6433.data[i][j] - bmats.Ax918.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_20_22.data[i][j] + bmats.B_31_4.data[i][j] + bmats.B_6_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
