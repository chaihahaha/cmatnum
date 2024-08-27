#include "fm_3467.h"

inline int fm_3467(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = +ABs.A_21_1.data[i][j]+ABs.A_21_2.data[i][j]+ABs.A_21_3.data[i][j]-11*ABs.A_21_4.data[i][j]+ABs.A_21_5.data[i][j]+ABs.A_21_6.data[i][j]+ABs.A_21_7.data[i][j]+ABs.A_21_8.data[i][j]+ABs.A_21_9.data[i][j]+ABs.A_21_10.data[i][j]+ABs.A_21_11.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_10_15.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

