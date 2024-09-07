#include "fm_73.h"

inline int fm_73(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_12_12.data[i][j] + bmats.A_12_13.data[i][j] + bmats.A_12_14.data[i][j] + bmats.A_12_15.data[i][j] + bmats.A_12_16.data[i][j] - 11*bmats.A_12_17.data[i][j] + bmats.A_12_18.data[i][j] + bmats.A_12_19.data[i][j] + bmats.A_12_20.data[i][j] + bmats.A_12_21.data[i][j] + bmats.A_12_22.data[i][j] + bmats.A_13_12.data[i][j] + bmats.A_13_13.data[i][j] + bmats.A_13_14.data[i][j] + bmats.A_13_15.data[i][j] + bmats.A_13_16.data[i][j] - 11*bmats.A_13_17.data[i][j] + bmats.A_13_18.data[i][j] + bmats.A_13_19.data[i][j] + bmats.A_13_20.data[i][j] + bmats.A_13_21.data[i][j] + bmats.A_13_22.data[i][j] + bmats.A_14_12.data[i][j] + bmats.A_14_13.data[i][j] + bmats.A_14_14.data[i][j] + bmats.A_14_15.data[i][j] + bmats.A_14_16.data[i][j] - 11*bmats.A_14_17.data[i][j] + bmats.A_14_18.data[i][j] + bmats.A_14_19.data[i][j] + bmats.A_14_20.data[i][j] + bmats.A_14_21.data[i][j] + bmats.A_14_22.data[i][j] + bmats.A_15_12.data[i][j] + bmats.A_15_13.data[i][j] + bmats.A_15_14.data[i][j] + bmats.A_15_15.data[i][j] + bmats.A_15_16.data[i][j] - 11*bmats.A_15_17.data[i][j] + bmats.A_15_18.data[i][j] + bmats.A_15_19.data[i][j] + bmats.A_15_20.data[i][j] + bmats.A_15_21.data[i][j] + bmats.A_15_22.data[i][j] + bmats.A_16_12.data[i][j] + bmats.A_16_13.data[i][j] + bmats.A_16_14.data[i][j] + bmats.A_16_15.data[i][j] + bmats.A_16_16.data[i][j] - 11*bmats.A_16_17.data[i][j] + bmats.A_16_18.data[i][j] + bmats.A_16_19.data[i][j] + bmats.A_16_20.data[i][j] + bmats.A_16_21.data[i][j] + bmats.A_16_22.data[i][j] - 12*bmats.A_17_17.data[i][j] + 12*bmats.A_17_20.data[i][j] + bmats.A_18_12.data[i][j] + bmats.A_18_13.data[i][j] + bmats.A_18_14.data[i][j] + bmats.A_18_15.data[i][j] + bmats.A_18_16.data[i][j] - 11*bmats.A_18_17.data[i][j] + bmats.A_18_18.data[i][j] + bmats.A_18_19.data[i][j] + bmats.A_18_20.data[i][j] + bmats.A_18_21.data[i][j] + bmats.A_18_22.data[i][j] + bmats.A_19_12.data[i][j] + bmats.A_19_13.data[i][j] + bmats.A_19_14.data[i][j] + bmats.A_19_15.data[i][j] + bmats.A_19_16.data[i][j] - 11*bmats.A_19_17.data[i][j] + bmats.A_19_18.data[i][j] + bmats.A_19_19.data[i][j] + bmats.A_19_20.data[i][j] + bmats.A_19_21.data[i][j] + bmats.A_19_22.data[i][j] - 12*bmats.A_20_17.data[i][j] + bmats.A_21_12.data[i][j] + bmats.A_21_13.data[i][j] + bmats.A_21_14.data[i][j] + bmats.A_21_15.data[i][j] + bmats.A_21_16.data[i][j] - 11*bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] + bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] + bmats.A_21_21.data[i][j] + bmats.A_21_22.data[i][j] + bmats.A_22_12.data[i][j] + bmats.A_22_13.data[i][j] + bmats.A_22_14.data[i][j] + bmats.A_22_15.data[i][j] + bmats.A_22_16.data[i][j] - 11*bmats.A_22_17.data[i][j] + bmats.A_22_18.data[i][j] + bmats.A_22_19.data[i][j] + bmats.A_22_20.data[i][j] + bmats.A_22_21.data[i][j] + bmats.A_22_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_20_12.data[i][j]-bmats.B_20_13.data[i][j]-bmats.B_20_14.data[i][j]-bmats.B_20_15.data[i][j]-bmats.B_20_16.data[i][j]-bmats.B_12_17.data[i][j]-bmats.B_13_17.data[i][j]-bmats.B_14_17.data[i][j]-bmats.B_15_17.data[i][j]-bmats.B_16_17.data[i][j]-bmats.B_17_17.data[i][j]-bmats.B_18_17.data[i][j]-bmats.B_19_17.data[i][j]-2*bmats.B_20_17.data[i][j]-bmats.B_21_17.data[i][j]-bmats.B_22_17.data[i][j]-bmats.B_20_18.data[i][j]-bmats.B_20_19.data[i][j]+bmats.B_17_20.data[i][j]-bmats.B_20_20.data[i][j]-bmats.B_20_21.data[i][j]-bmats.B_20_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
