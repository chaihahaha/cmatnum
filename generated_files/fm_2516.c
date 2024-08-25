#include "fm_2516.h"

int fm_2516(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_10_13.data[i][j]-ABs.A_10_14.data[i][j]-ABs.A_10_15.data[i][j]-ABs.A_10_16.data[i][j]-ABs.A_10_17.data[i][j]-ABs.A_10_18.data[i][j]+11*ABs.A_10_19.data[i][j]-ABs.A_10_20.data[i][j]-ABs.A_10_21.data[i][j]-ABs.A_10_22.data[i][j]-ABs.A_10_12.data[i][j]+ABs.A_17_19.data[i][j]+ABs.A_17_20.data[i][j]+ABs.A_17_22.data[i][j]-11*ABs.A_17_21.data[i][j]+ABs.A_17_18.data[i][j]+ABs.A_17_17.data[i][j]+ABs.A_17_16.data[i][j]+ABs.A_17_15.data[i][j]+ABs.A_17_14.data[i][j]+ABs.A_17_13.data[i][j]+ABs.A_17_12.data[i][j]-ABs.A_19_10.data[i][j]-ABs.A_19_11.data[i][j]-ABs.A_19_7.data[i][j]-ABs.A_19_8.data[i][j]-ABs.A_19_9.data[i][j]-ABs.A_19_1.data[i][j]-ABs.A_19_2.data[i][j]-ABs.A_19_3.data[i][j]-ABs.A_19_4.data[i][j]-ABs.A_19_5.data[i][j]+11*ABs.A_19_6.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_21_8.data[i][j]+ABs.B_19_17.data[i][j]+ABs.B_6_21.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
