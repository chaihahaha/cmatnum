#include "fm_4560.h"

inline int fm_4560(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_15_12.data[i][j] + bmats.A_15_13.data[i][j] + bmats.A_15_14.data[i][j] + bmats.A_15_15.data[i][j] - 11*bmats.A_15_16.data[i][j] + bmats.A_15_17.data[i][j] + bmats.A_15_18.data[i][j] + bmats.A_15_19.data[i][j] + bmats.A_15_20.data[i][j] + bmats.A_15_21.data[i][j] + bmats.A_15_22.data[i][j] + 11*bmats.A_16_4.data[i][j] - bmats.A_16_5.data[i][j] - bmats.A_5_15.data[i][j] + 11*bmats.A_5_16.data[i][j] - bmats.Ax944.data[i][j] - bmats.Ax977.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_16_15.data[i][j] + bmats.B_16_5.data[i][j] + bmats.B_4_16.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
