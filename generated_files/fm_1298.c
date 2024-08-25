#include "fm_1298.h"

int fm_1298(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_6_12.data[i][j]-ABs.A_6_13.data[i][j]-ABs.A_6_14.data[i][j]-ABs.A_6_15.data[i][j]-ABs.A_6_16.data[i][j]-ABs.A_6_17.data[i][j]-ABs.A_6_18.data[i][j]-ABs.A_6_19.data[i][j]-ABs.A_6_20.data[i][j]+11*ABs.A_6_21.data[i][j]-ABs.A_6_22.data[i][j]+ABs.A_10_11.data[i][j]+ABs.A_10_1.data[i][j]+ABs.A_10_2.data[i][j]+ABs.A_10_3.data[i][j]+ABs.A_10_4.data[i][j]-11*ABs.A_10_5.data[i][j]+ABs.A_10_6.data[i][j]+ABs.A_10_7.data[i][j]+ABs.A_10_8.data[i][j]+ABs.A_10_9.data[i][j]+ABs.A_10_10.data[i][j]-ABs.A_16_10.data[i][j]-ABs.A_16_11.data[i][j]-ABs.A_16_4.data[i][j]-ABs.A_16_5.data[i][j]+11*ABs.A_16_6.data[i][j]-ABs.A_16_7.data[i][j]-ABs.A_16_8.data[i][j]-ABs.A_16_9.data[i][j]-ABs.A_16_1.data[i][j]-ABs.A_16_2.data[i][j]-ABs.A_16_3.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_21_5.data[i][j]+ABs.B_6_10.data[i][j]+ABs.B_5_17.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
