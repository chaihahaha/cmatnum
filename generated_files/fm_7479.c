#include "fm_7479.h"

inline int fm_7479(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_15_27.data[i][j] - bmats.A_15_28.data[i][j] + bmats.A_17_30.data[i][j] - 16*bmats.A_17_31.data[i][j] + 16*bmats.A_27_1.data[i][j] - bmats.A_27_2.data[i][j] - bmats.Ax2279.data[i][j] - bmats.Ax2882.data[i][j] - bmats.Ax4905.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_31.data[i][j] + bmats.B_27_17.data[i][j] + bmats.B_31_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}