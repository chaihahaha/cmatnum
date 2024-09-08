#include "fm_8745.h"

inline int fm_8745(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_22_17.data[i][j] + bmats.A_22_22.data[i][j] - 16*bmats.A_22_23.data[i][j] + bmats.A_22_24.data[i][j] - bmats.A_32_5.data[i][j] + 16*bmats.A_32_6.data[i][j] - bmats.A_7_31.data[i][j] + 16*bmats.A_7_32.data[i][j] - bmats.Ax3964.data[i][j] - bmats.Ax6417.data[i][j] - bmats.Ax763.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_23_16.data[i][j] + bmats.B_32_22.data[i][j] + bmats.B_6_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
