#include "fm_1741.h"

inline int fm_1741(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_18_19.data[i][j] - bmats.A_18_20.data[i][j] + 16*bmats.A_19_19.data[i][j] - bmats.A_19_20.data[i][j] - bmats.A_20_15.data[i][j] - bmats.A_20_16.data[i][j] - bmats.A_3_19.data[i][j] + 16*bmats.A_3_20.data[i][j] - bmats.Ax4321.data[i][j] - bmats.Ax4351.data[i][j] - bmats.Ax4354.data[i][j] - bmats.Ax4495.data[i][j] - bmats.Ax709.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_16_19.data[i][j] + bmats.B_19_4.data[i][j] - bmats.B_1_19.data[i][j] - bmats.B_20_17.data[i][j] - bmats.B_20_18.data[i][j] - bmats.B_20_19.data[i][j] - bmats.B_20_20.data[i][j] - bmats.B_20_21.data[i][j] - bmats.B_20_22.data[i][j] - bmats.B_20_23.data[i][j] - bmats.B_20_24.data[i][j] - bmats.B_20_25.data[i][j] - bmats.B_20_26.data[i][j] - bmats.B_20_27.data[i][j] - bmats.B_20_28.data[i][j] - bmats.B_20_29.data[i][j] - bmats.B_20_30.data[i][j] - bmats.B_20_31.data[i][j] - bmats.B_20_32.data[i][j] - bmats.B_2_19.data[i][j] - bmats.B_3_19.data[i][j] - bmats.Bx12271.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}