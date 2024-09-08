#include "fm_1840.h"

inline int fm_1840(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_17.data[i][j] + 16*bmats.A_17_18.data[i][j] - bmats.A_18_17.data[i][j] + 16*bmats.A_18_18.data[i][j] - bmats.A_24_15.data[i][j] - bmats.A_24_16.data[i][j] - bmats.A_2_23.data[i][j] + 16*bmats.A_2_24.data[i][j] - bmats.Ax158.data[i][j] - bmats.Ax3448.data[i][j] - bmats.Ax4655.data[i][j] - bmats.Ax4666.data[i][j] - bmats.Ax697.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_16_18.data[i][j] + bmats.B_18_8.data[i][j] - bmats.B_1_18.data[i][j] - bmats.B_24_17.data[i][j] - bmats.B_24_18.data[i][j] - bmats.B_24_19.data[i][j] - bmats.B_24_20.data[i][j] - bmats.B_24_21.data[i][j] - bmats.B_24_22.data[i][j] - bmats.B_24_23.data[i][j] - bmats.B_24_24.data[i][j] - bmats.B_24_25.data[i][j] - bmats.B_24_26.data[i][j] - bmats.B_24_27.data[i][j] - bmats.B_24_28.data[i][j] - bmats.B_24_29.data[i][j] - bmats.B_24_30.data[i][j] - bmats.B_24_31.data[i][j] - bmats.B_24_32.data[i][j] - bmats.B_2_18.data[i][j] - bmats.Bx12672.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_18.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
