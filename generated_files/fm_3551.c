#include "fm_3551.h"

inline int fm_3551(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_16_17.data[i][j] - bmats.A_16_18.data[i][j] - 16*bmats.A_1_11.data[i][j] + bmats.A_1_12.data[i][j] - bmats.A_27_15.data[i][j] + 16*bmats.A_27_16.data[i][j] - bmats.Ax4680.data[i][j] - bmats.Ax5233.data[i][j] - bmats.Ax685.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_32.data[i][j] + bmats.B_16_1.data[i][j] + bmats.B_17_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}