#include "fm_3089.h"

inline int fm_3089(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_16_11.data[i][j] - 16*bmats.A_16_12.data[i][j] + bmats.A_16_16.data[i][j] + 16*bmats.A_28_7.data[i][j] - bmats.A_28_8.data[i][j] - bmats.A_7_31.data[i][j] + 16*bmats.A_7_32.data[i][j] - bmats.Ax2454.data[i][j] - bmats.Ax5158.data[i][j] - bmats.Ax763.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_23.data[i][j] + bmats.B_32_12.data[i][j] + bmats.B_7_16.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_23.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
