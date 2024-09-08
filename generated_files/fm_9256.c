#include "fm_9256.h"

inline int fm_9256(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_25_11.data[i][j] - bmats.A_25_12.data[i][j] + bmats.A_27_17.data[i][j] + bmats.A_27_18.data[i][j] + bmats.A_27_22.data[i][j] - 16*bmats.A_27_23.data[i][j] + bmats.A_27_27.data[i][j] + 16*bmats.A_7_25.data[i][j] - bmats.A_7_26.data[i][j] - bmats.Ax2242.data[i][j] - bmats.Ax2860.data[i][j] - bmats.Ax6819.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_23.data[i][j] + bmats.B_23_9.data[i][j] + bmats.B_25_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
