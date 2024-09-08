#include "fm_1073.h"

inline int fm_1073(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_24_27.data[i][j] + bmats.A_26_23.data[i][j] - 16*bmats.A_26_24.data[i][j] - 17*bmats.A_27_24.data[i][j] + bmats.Ax3529.data[i][j] + bmats.Ax50.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_24.data[i][j] - bmats.B_18_24.data[i][j] - bmats.B_19_24.data[i][j] - bmats.B_20_24.data[i][j] - bmats.B_21_24.data[i][j] - bmats.B_22_24.data[i][j] - bmats.B_23_24.data[i][j] - bmats.B_24_24.data[i][j] + bmats.B_24_27.data[i][j] - bmats.B_25_24.data[i][j] - bmats.B_26_24.data[i][j] - bmats.B_27_17.data[i][j] - bmats.B_27_18.data[i][j] - bmats.B_27_19.data[i][j] - bmats.B_27_20.data[i][j] - bmats.B_27_21.data[i][j] - bmats.B_27_22.data[i][j] - bmats.B_27_23.data[i][j] - 2*bmats.B_27_24.data[i][j] - bmats.B_27_25.data[i][j] - bmats.B_27_26.data[i][j] - bmats.B_27_27.data[i][j] - bmats.B_27_28.data[i][j] - bmats.B_27_29.data[i][j] - bmats.B_27_30.data[i][j] - bmats.B_27_31.data[i][j] - bmats.B_27_32.data[i][j] - bmats.B_28_24.data[i][j] - bmats.B_29_24.data[i][j] - bmats.B_30_24.data[i][j] - bmats.B_31_24.data[i][j] - bmats.B_32_24.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
