#include "fm_3294.h"

inline int fm_3294(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_17.data[i][j] - bmats.A_14_18.data[i][j] + bmats.A_1_11.data[i][j] - 16*bmats.A_1_12.data[i][j] - bmats.A_28_13.data[i][j] + 16*bmats.A_28_14.data[i][j] - bmats.Ax1766.data[i][j] - bmats.Ax491.data[i][j] - bmats.Ax5233.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_30.data[i][j] + bmats.B_14_1.data[i][j] + bmats.B_17_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_30.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}