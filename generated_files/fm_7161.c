#include "fm_7161.h"

inline int fm_7161(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_18_18.data[i][j] + bmats.A_18_19.data[i][j] - 16*bmats.A_18_20.data[i][j] + bmats.A_18_21.data[i][j] + bmats.A_18_24.data[i][j] + bmats.A_18_25.data[i][j] + bmats.A_18_26.data[i][j] + bmats.A_18_32.data[i][j] - bmats.A_26_1.data[i][j] + 16*bmats.A_26_2.data[i][j] - bmats.A_4_25.data[i][j] + 16*bmats.A_4_26.data[i][j] - bmats.Ax2866.data[i][j] - bmats.Ax3108.data[i][j] - bmats.Ax6381.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_20_10.data[i][j] + bmats.B_26_18.data[i][j] + bmats.B_2_20.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
