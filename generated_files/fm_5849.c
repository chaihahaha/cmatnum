#include "fm_5849.h"

inline int fm_5849(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_18_3.data[i][j] - bmats.A_18_4.data[i][j] + bmats.A_2_1.data[i][j] - 16*bmats.A_2_2.data[i][j] - bmats.A_3_17.data[i][j] + 16*bmats.A_3_18.data[i][j] - bmats.Ax4300.data[i][j] - bmats.Ax4589.data[i][j] - bmats.Ax5893.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_2.data[i][j] + bmats.B_2_19.data[i][j] + bmats.B_3_2.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_19.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}