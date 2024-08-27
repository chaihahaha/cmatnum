#include "fm_190.h"

inline int fm_190(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_21_12.data[i][j]-ABs.A_21_13.data[i][j]-ABs.A_21_14.data[i][j]-ABs.A_22_15.data[i][j]+11*ABs.A_22_16.data[i][j]-ABs.A_22_17.data[i][j]-ABs.A_22_18.data[i][j]-ABs.A_22_19.data[i][j]-ABs.A_22_20.data[i][j]-ABs.A_22_21.data[i][j]-ABs.A_22_22.data[i][j]-ABs.A_22_12.data[i][j]-ABs.A_22_13.data[i][j]-ABs.A_22_14.data[i][j]-ABs.A_12_13.data[i][j]-ABs.A_12_14.data[i][j]-ABs.A_5_12.data[i][j]-ABs.A_12_15.data[i][j]+11*ABs.A_12_16.data[i][j]-ABs.A_12_17.data[i][j]-ABs.A_12_18.data[i][j]-ABs.A_12_19.data[i][j]-ABs.A_12_20.data[i][j]-ABs.A_12_21.data[i][j]-ABs.A_12_22.data[i][j]-ABs.A_13_13.data[i][j]-ABs.A_13_14.data[i][j]-ABs.A_13_15.data[i][j]+11*ABs.A_13_16.data[i][j]-ABs.A_13_17.data[i][j]-ABs.A_13_18.data[i][j]-ABs.A_13_19.data[i][j]-ABs.A_13_20.data[i][j]-ABs.A_13_21.data[i][j]-ABs.A_13_22.data[i][j]-ABs.A_14_13.data[i][j]-ABs.A_14_14.data[i][j]-ABs.A_14_15.data[i][j]+11*ABs.A_14_16.data[i][j]-ABs.A_14_17.data[i][j]-ABs.A_14_18.data[i][j]-ABs.A_14_19.data[i][j]-ABs.A_14_20.data[i][j]-ABs.A_14_21.data[i][j]-ABs.A_14_22.data[i][j]-ABs.A_5_13.data[i][j]-ABs.A_5_14.data[i][j]+11*ABs.A_5_15.data[i][j]-ABs.A_5_16.data[i][j]-ABs.A_5_17.data[i][j]-ABs.A_5_18.data[i][j]-ABs.A_5_19.data[i][j]-ABs.A_5_20.data[i][j]-ABs.A_5_21.data[i][j]-ABs.A_5_22.data[i][j]-ABs.A_12_12.data[i][j]-ABs.A_13_12.data[i][j]-ABs.A_14_12.data[i][j]-ABs.A_15_10.data[i][j]-ABs.A_15_11.data[i][j]-ABs.A_15_12.data[i][j]-ABs.A_15_13.data[i][j]-ABs.A_15_14.data[i][j]-ABs.A_15_15.data[i][j]+11*ABs.A_15_16.data[i][j]-ABs.A_15_17.data[i][j]-ABs.A_15_18.data[i][j]-ABs.A_15_19.data[i][j]-ABs.A_16_12.data[i][j]-ABs.A_16_13.data[i][j]-ABs.A_16_14.data[i][j]-ABs.A_16_15.data[i][j]+11*ABs.A_16_16.data[i][j]-ABs.A_16_17.data[i][j]-ABs.A_16_18.data[i][j]-ABs.A_16_19.data[i][j]-ABs.A_15_4.data[i][j]-ABs.A_15_5.data[i][j]-ABs.A_15_6.data[i][j]-ABs.A_15_7.data[i][j]-ABs.A_15_8.data[i][j]-ABs.A_15_9.data[i][j]-ABs.A_15_1.data[i][j]-ABs.A_15_2.data[i][j]-ABs.A_15_3.data[i][j]-ABs.A_15_20.data[i][j]-ABs.A_15_21.data[i][j]-ABs.A_15_22.data[i][j]-ABs.A_16_20.data[i][j]+11*ABs.A_18_16.data[i][j]-ABs.A_17_19.data[i][j]-ABs.A_18_15.data[i][j]-ABs.A_18_12.data[i][j]-ABs.A_18_14.data[i][j]-ABs.A_18_13.data[i][j]-ABs.A_17_20.data[i][j]-ABs.A_16_21.data[i][j]-ABs.A_17_22.data[i][j]-ABs.A_16_22.data[i][j]-ABs.A_17_21.data[i][j]-ABs.A_17_18.data[i][j]-ABs.A_17_17.data[i][j]+11*ABs.A_17_16.data[i][j]-ABs.A_17_15.data[i][j]-ABs.A_17_14.data[i][j]-ABs.A_17_13.data[i][j]-ABs.A_18_17.data[i][j]-ABs.A_18_18.data[i][j]-ABs.A_18_19.data[i][j]-ABs.A_18_20.data[i][j]-ABs.A_18_21.data[i][j]-ABs.A_18_22.data[i][j]-ABs.A_17_12.data[i][j]-ABs.A_19_12.data[i][j]-ABs.A_19_13.data[i][j]-ABs.A_19_14.data[i][j]-ABs.A_19_15.data[i][j]+11*ABs.A_19_16.data[i][j]-ABs.A_19_17.data[i][j]-ABs.A_19_18.data[i][j]-ABs.A_19_19.data[i][j]-ABs.A_19_20.data[i][j]-ABs.A_19_21.data[i][j]-ABs.A_20_12.data[i][j]-ABs.A_20_13.data[i][j]-ABs.A_20_14.data[i][j]-ABs.A_20_15.data[i][j]+11*ABs.A_20_16.data[i][j]-ABs.A_20_17.data[i][j]-ABs.A_20_18.data[i][j]-ABs.A_20_19.data[i][j]-ABs.A_20_20.data[i][j]-ABs.A_20_21.data[i][j]-ABs.A_19_22.data[i][j]-ABs.A_20_22.data[i][j]-ABs.A_21_15.data[i][j]+11*ABs.A_21_16.data[i][j]-ABs.A_21_17.data[i][j]-ABs.A_21_18.data[i][j]-ABs.A_21_19.data[i][j]-ABs.A_21_20.data[i][j]-ABs.A_21_21.data[i][j]-ABs.A_21_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_16_4.data[i][j]-ABs.B_15_12.data[i][j]-ABs.B_15_13.data[i][j]-ABs.B_15_14.data[i][j]-ABs.B_15_15.data[i][j]-ABs.B_1_16.data[i][j]-ABs.B_2_16.data[i][j]-ABs.B_3_16.data[i][j]-ABs.B_4_16.data[i][j]-ABs.B_5_16.data[i][j]-ABs.B_6_16.data[i][j]-ABs.B_7_16.data[i][j]-ABs.B_8_16.data[i][j]-ABs.B_9_16.data[i][j]-ABs.B_10_16.data[i][j]-ABs.B_11_16.data[i][j]-ABs.B_15_16.data[i][j]-ABs.B_15_17.data[i][j]-ABs.B_15_18.data[i][j]-ABs.B_15_19.data[i][j]-ABs.B_15_20.data[i][j]-ABs.B_15_21.data[i][j]-ABs.B_15_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

