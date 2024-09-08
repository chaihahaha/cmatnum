#include "fm_7561.h"

inline int fm_7561(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_17_17.data[i][j] + bmats.A_17_18.data[i][j] - 16*bmats.A_17_19.data[i][j] + bmats.A_17_30.data[i][j] + bmats.A_17_31.data[i][j] + bmats.A_17_32.data[i][j] + 16*bmats.A_22_1.data[i][j] - bmats.A_22_2.data[i][j] - bmats.A_3_21.data[i][j] + 16*bmats.A_3_22.data[i][j] - bmats.Ax3862.data[i][j] - bmats.Ax4081.data[i][j] - bmats.Ax6602.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_19_6.data[i][j] + bmats.B_1_19.data[i][j] + bmats.B_22_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
