#include "fm_5138.h"

inline int fm_5138(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_12.data[i][j] - bmats.A_12_13.data[i][j] - bmats.A_12_14.data[i][j] - bmats.A_12_15.data[i][j] + 11*bmats.A_12_16.data[i][j] - bmats.A_12_17.data[i][j] - bmats.A_12_18.data[i][j] - bmats.A_12_19.data[i][j] - bmats.A_12_20.data[i][j] - bmats.A_12_21.data[i][j] - bmats.A_12_22.data[i][j] - bmats.A_16_12.data[i][j] - bmats.A_16_13.data[i][j] - bmats.A_16_14.data[i][j] - bmats.A_16_15.data[i][j] - bmats.A_16_16.data[i][j] - bmats.A_16_17.data[i][j] - bmats.A_16_18.data[i][j] - bmats.A_16_19.data[i][j] + 11*bmats.A_16_20.data[i][j] - bmats.A_16_21.data[i][j] - bmats.A_16_22.data[i][j] + 11*bmats.A_20_12.data[i][j] - bmats.A_20_13.data[i][j] - bmats.A_20_14.data[i][j] - bmats.A_20_15.data[i][j] - bmats.A_20_16.data[i][j] - bmats.A_20_17.data[i][j] - bmats.A_20_18.data[i][j] - bmats.A_20_19.data[i][j] - bmats.A_20_20.data[i][j] - bmats.A_20_21.data[i][j] - bmats.A_20_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_20_12.data[i][j]+bmats.B_12_16.data[i][j]+bmats.B_16_20.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
