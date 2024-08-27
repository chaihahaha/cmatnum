#include "fm_1530.h"

inline int fm_1530(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_6_12.data[i][j]-ABs.A_6_13.data[i][j]-ABs.A_6_14.data[i][j]-ABs.A_6_15.data[i][j]-ABs.A_6_16.data[i][j]-ABs.A_6_17.data[i][j]-ABs.A_6_18.data[i][j]-ABs.A_6_19.data[i][j]-ABs.A_6_20.data[i][j]+11*ABs.A_6_21.data[i][j]-ABs.A_6_22.data[i][j]+ABs.A_10_11.data[i][j]+ABs.A_10_1.data[i][j]+ABs.A_10_2.data[i][j]-11*ABs.A_10_3.data[i][j]+ABs.A_10_4.data[i][j]+ABs.A_10_5.data[i][j]+ABs.A_10_6.data[i][j]+ABs.A_10_7.data[i][j]+ABs.A_10_8.data[i][j]+ABs.A_10_9.data[i][j]+ABs.A_10_10.data[i][j]-ABs.A_14_11.data[i][j]-ABs.A_14_1.data[i][j]-ABs.A_14_2.data[i][j]-ABs.A_14_3.data[i][j]-ABs.A_14_4.data[i][j]-ABs.A_14_5.data[i][j]+11*ABs.A_14_6.data[i][j]-ABs.A_14_7.data[i][j]-ABs.A_14_8.data[i][j]-ABs.A_14_9.data[i][j]-ABs.A_14_10.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_21_3.data[i][j]+ABs.B_6_10.data[i][j]+ABs.B_3_17.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

