#include "fm_3399.h"

inline int fm_3399(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_12_11.data[i][j] + bmats.A_12_12.data[i][j] - bmats.A_16_27.data[i][j] + 16*bmats.A_16_28.data[i][j] - bmats.A_27_15.data[i][j] + 16*bmats.A_27_16.data[i][j] - bmats.Ax2282.data[i][j] - bmats.Ax5177.data[i][j] - bmats.Ax685.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_32.data[i][j] + bmats.B_16_12.data[i][j] + bmats.B_28_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}