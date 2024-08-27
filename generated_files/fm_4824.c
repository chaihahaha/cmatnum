#include "fm_4824.h"

inline int fm_4824(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_1_11.data[i][j]-ABs.A_1_1.data[i][j]-ABs.A_1_2.data[i][j]-ABs.A_1_3.data[i][j]-ABs.A_1_4.data[i][j]+11*ABs.A_1_5.data[i][j]-ABs.A_1_6.data[i][j]-ABs.A_1_7.data[i][j]-ABs.A_1_8.data[i][j]-ABs.A_1_9.data[i][j]-ABs.A_1_10.data[i][j]-ABs.A_2_11.data[i][j]+11*ABs.A_2_1.data[i][j]-ABs.A_2_2.data[i][j]-ABs.A_2_3.data[i][j]-ABs.A_2_4.data[i][j]-ABs.A_2_5.data[i][j]-ABs.A_2_6.data[i][j]-ABs.A_2_7.data[i][j]-ABs.A_2_8.data[i][j]-ABs.A_2_9.data[i][j]-ABs.A_2_10.data[i][j]-ABs.A_5_11.data[i][j]-ABs.A_5_1.data[i][j]+11*ABs.A_5_2.data[i][j]-ABs.A_5_3.data[i][j]-ABs.A_5_4.data[i][j]-ABs.A_5_5.data[i][j]-ABs.A_5_6.data[i][j]-ABs.A_5_7.data[i][j]-ABs.A_5_8.data[i][j]-ABs.A_5_9.data[i][j]-ABs.A_5_10.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_2_1.data[i][j]+ABs.B_5_2.data[i][j]+ABs.B_1_5.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

