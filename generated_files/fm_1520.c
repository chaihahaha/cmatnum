#include "fm_1520.h"

int fm_1520(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +ABs.A_1_11.data[i][j]+ABs.A_1_1.data[i][j]+ABs.A_1_2.data[i][j]+ABs.A_1_3.data[i][j]-11*ABs.A_1_4.data[i][j]+ABs.A_1_5.data[i][j]+ABs.A_1_6.data[i][j]+ABs.A_1_7.data[i][j]+ABs.A_1_8.data[i][j]+ABs.A_1_9.data[i][j]+ABs.A_1_10.data[i][j]-ABs.A_10_13.data[i][j]-ABs.A_10_14.data[i][j]-ABs.A_10_15.data[i][j]-ABs.A_10_16.data[i][j]-ABs.A_10_17.data[i][j]-ABs.A_10_18.data[i][j]-ABs.A_10_19.data[i][j]-ABs.A_10_20.data[i][j]-ABs.A_10_21.data[i][j]-ABs.A_10_22.data[i][j]+11*ABs.A_10_12.data[i][j]+11*ABs.A_15_10.data[i][j]-ABs.A_15_11.data[i][j]-ABs.A_15_4.data[i][j]-ABs.A_15_5.data[i][j]-ABs.A_15_6.data[i][j]-ABs.A_15_7.data[i][j]-ABs.A_15_8.data[i][j]-ABs.A_15_9.data[i][j]-ABs.A_15_1.data[i][j]-ABs.A_15_2.data[i][j]-ABs.A_15_3.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_10_1.data[i][j]+ABs.B_12_4.data[i][j]+ABs.B_4_21.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
