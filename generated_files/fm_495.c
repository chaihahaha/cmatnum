#include "fm_495.h"

inline int fm_495(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_20_31.data[i][j] - bmats.A_20_32.data[i][j] + bmats.A_29_3.data[i][j] - 16*bmats.A_29_4.data[i][j] - bmats.Ax2155.data[i][j] - bmats.Ax633.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_13.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_20_13.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_23_13.data[i][j] - bmats.B_24_13.data[i][j] - bmats.B_25_13.data[i][j] - bmats.B_26_13.data[i][j] - bmats.B_27_13.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_29_13.data[i][j] + bmats.B_29_20.data[i][j] - bmats.B_30_13.data[i][j] - bmats.B_31_13.data[i][j] - bmats.B_32_13.data[i][j] - bmats.B_4_17.data[i][j] - bmats.B_4_18.data[i][j] - bmats.B_4_19.data[i][j] - bmats.B_4_20.data[i][j] - bmats.B_4_21.data[i][j] - bmats.B_4_22.data[i][j] - bmats.B_4_23.data[i][j] - bmats.B_4_24.data[i][j] - bmats.B_4_25.data[i][j] - bmats.B_4_26.data[i][j] - bmats.B_4_27.data[i][j] - bmats.B_4_28.data[i][j] - bmats.B_4_29.data[i][j] - bmats.B_4_30.data[i][j] - bmats.B_4_31.data[i][j] - bmats.B_4_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
