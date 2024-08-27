#include "fm_2655.h"

inline int fm_2655(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_4_12.data[i][j]-ABs.A_4_13.data[i][j]-ABs.A_4_14.data[i][j]-ABs.A_4_15.data[i][j]-ABs.A_4_16.data[i][j]-ABs.A_4_17.data[i][j]-ABs.A_4_18.data[i][j]-ABs.A_4_19.data[i][j]+11*ABs.A_4_20.data[i][j]-ABs.A_4_21.data[i][j]-ABs.A_4_22.data[i][j]+ABs.A_16_12.data[i][j]+ABs.A_16_13.data[i][j]+ABs.A_16_14.data[i][j]-11*ABs.A_16_15.data[i][j]+ABs.A_16_16.data[i][j]+ABs.A_16_17.data[i][j]+ABs.A_16_18.data[i][j]+ABs.A_16_19.data[i][j]+ABs.A_16_20.data[i][j]+ABs.A_16_21.data[i][j]+ABs.A_16_22.data[i][j]-ABs.A_20_10.data[i][j]-ABs.A_20_11.data[i][j]-ABs.A_20_7.data[i][j]-ABs.A_20_8.data[i][j]-ABs.A_20_9.data[i][j]-ABs.A_20_1.data[i][j]-ABs.A_20_2.data[i][j]-ABs.A_20_3.data[i][j]-ABs.A_20_4.data[i][j]+11*ABs.A_20_5.data[i][j]-ABs.A_20_6.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_15_9.data[i][j]+ABs.B_5_15.data[i][j]+ABs.B_20_16.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

