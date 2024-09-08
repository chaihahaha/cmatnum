#include "fm_7270.h"

inline int fm_7270(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_11_19.data[i][j] - bmats.A_11_20.data[i][j] + bmats.A_18_24.data[i][j] + bmats.A_18_25.data[i][j] - 16*bmats.A_18_27.data[i][j] - bmats.A_19_1.data[i][j] + 16*bmats.A_19_2.data[i][j] - bmats.Ax2768.data[i][j] - bmats.Ax4586.data[i][j] - bmats.Ax6350.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_19_18.data[i][j] + bmats.B_27_3.data[i][j] + bmats.B_2_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
