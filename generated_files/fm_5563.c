#include "fm_5563.h"

inline int fm_5563(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_2_11.data[i][j]-ABs.A_2_1.data[i][j]-ABs.A_2_2.data[i][j]+11*ABs.A_2_3.data[i][j]-ABs.A_2_4.data[i][j]-ABs.A_2_5.data[i][j]-ABs.A_2_6.data[i][j]-ABs.A_2_7.data[i][j]-ABs.A_2_8.data[i][j]-ABs.A_2_9.data[i][j]-ABs.A_2_10.data[i][j]-ABs.A_3_11.data[i][j]-ABs.A_3_1.data[i][j]-ABs.A_3_2.data[i][j]-ABs.A_3_3.data[i][j]+11*ABs.A_3_4.data[i][j]-ABs.A_3_5.data[i][j]-ABs.A_3_6.data[i][j]-ABs.A_3_7.data[i][j]-ABs.A_3_8.data[i][j]-ABs.A_3_9.data[i][j]-ABs.A_3_10.data[i][j]-ABs.A_4_11.data[i][j]-ABs.A_4_1.data[i][j]+11*ABs.A_4_2.data[i][j]-ABs.A_4_3.data[i][j]-ABs.A_4_4.data[i][j]-ABs.A_4_5.data[i][j]-ABs.A_4_6.data[i][j]-ABs.A_4_7.data[i][j]-ABs.A_4_8.data[i][j]-ABs.A_4_9.data[i][j]-ABs.A_4_10.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_4_2.data[i][j]+ABs.B_2_3.data[i][j]+ABs.B_3_4.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

