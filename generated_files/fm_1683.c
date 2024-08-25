#include "fm_1683.h"

int fm_1683(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_10_13.data[i][j]-ABs.A_10_14.data[i][j]-ABs.A_10_15.data[i][j]-ABs.A_10_16.data[i][j]-ABs.A_10_17.data[i][j]-ABs.A_10_18.data[i][j]+11*ABs.A_10_19.data[i][j]-ABs.A_10_20.data[i][j]-ABs.A_10_21.data[i][j]-ABs.A_10_22.data[i][j]+ABs.A_8_11.data[i][j]+ABs.A_8_1.data[i][j]-11*ABs.A_8_2.data[i][j]+ABs.A_8_3.data[i][j]+ABs.A_8_4.data[i][j]+ABs.A_8_5.data[i][j]+ABs.A_8_6.data[i][j]+ABs.A_8_7.data[i][j]+ABs.A_8_8.data[i][j]+ABs.A_8_9.data[i][j]+ABs.A_8_10.data[i][j]-ABs.A_10_12.data[i][j]-ABs.A_13_11.data[i][j]-ABs.A_13_1.data[i][j]-ABs.A_13_2.data[i][j]-ABs.A_13_3.data[i][j]-ABs.A_13_4.data[i][j]-ABs.A_13_5.data[i][j]-ABs.A_13_6.data[i][j]-ABs.A_13_7.data[i][j]-ABs.A_13_8.data[i][j]-ABs.A_13_9.data[i][j]+11*ABs.A_13_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_19_2.data[i][j]+ABs.B_10_8.data[i][j]+ABs.B_2_21.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
