#include "fm_8235.h"

inline int fm_8235(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_24_17.data[i][j] - 16*bmats.A_24_18.data[i][j] + bmats.A_24_24.data[i][j] + bmats.A_24_26.data[i][j] + bmats.A_24_27.data[i][j] + bmats.A_24_28.data[i][j] - bmats.A_2_29.data[i][j] + 16*bmats.A_2_30.data[i][j] - bmats.A_30_7.data[i][j] + 16*bmats.A_30_8.data[i][j] - bmats.Ax1422.data[i][j] - bmats.Ax429.data[i][j] - bmats.Ax6941.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_14.data[i][j] + bmats.B_30_24.data[i][j] + bmats.B_8_18.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}