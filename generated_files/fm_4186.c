#include "fm_4186.h"

inline int fm_4186(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_12_12.data[i][j] + bmats.A_12_7.data[i][j] - 16*bmats.A_12_8.data[i][j] - bmats.A_24_1.data[i][j] + 16*bmats.A_24_2.data[i][j] - bmats.A_2_27.data[i][j] + 16*bmats.A_2_28.data[i][j] - bmats.Ax2312.data[i][j] - bmats.Ax3720.data[i][j] - bmats.Ax5439.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_28_8.data[i][j] + bmats.B_2_12.data[i][j] + bmats.B_8_18.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_18.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
