#include "fm_8372.h"

inline int fm_8372(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_19.data[i][j] + 16*bmats.A_15_20.data[i][j] - bmats.A_20_7.data[i][j] + 16*bmats.A_20_8.data[i][j] + bmats.A_24_26.data[i][j] + bmats.A_24_27.data[i][j] + bmats.A_24_30.data[i][j] - 16*bmats.A_24_31.data[i][j] - bmats.Ax3405.data[i][j] - bmats.Ax6921.data[i][j] - bmats.Ax918.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_20_24.data[i][j] + bmats.B_31_4.data[i][j] + bmats.B_8_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}