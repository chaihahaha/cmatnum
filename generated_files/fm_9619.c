#include "fm_9619.h"

inline int fm_9619(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_11_15.data[i][j] - bmats.A_11_16.data[i][j] + 16*bmats.A_15_3.data[i][j] - bmats.A_15_4.data[i][j] + 16*bmats.A_3_11.data[i][j] - bmats.A_3_12.data[i][j] - bmats.Ax2208.data[i][j] - bmats.Ax562.data[i][j] - bmats.Ax944.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_15.data[i][j] + bmats.B_15_3.data[i][j] + bmats.B_3_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}