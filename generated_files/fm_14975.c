#include "fm_14975.h"

inline int fm_14975(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_19.data[i][j] + 16*bmats.A_19_20.data[i][j] - bmats.A_20_23.data[i][j] + 16*bmats.A_20_24.data[i][j] + 16*bmats.A_24_19.data[i][j] - bmats.A_24_20.data[i][j] - bmats.Ax105.data[i][j] - bmats.Ax347.data[i][j] - bmats.Ax4354.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_19_20.data[i][j] + bmats.B_20_24.data[i][j] + bmats.B_24_19.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}