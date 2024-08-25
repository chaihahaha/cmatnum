#include "fm_2030.h"

int fm_2030(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +11*ABs.A_21_10.data[i][j]-ABs.A_21_11.data[i][j]+ABs.A_21_12.data[i][j]+ABs.A_21_13.data[i][j]+ABs.A_21_14.data[i][j]-ABs.A_4_12.data[i][j]-ABs.A_4_13.data[i][j]-ABs.A_4_14.data[i][j]-ABs.A_4_15.data[i][j]-ABs.A_4_16.data[i][j]-ABs.A_4_17.data[i][j]-ABs.A_4_18.data[i][j]-ABs.A_4_19.data[i][j]-ABs.A_4_20.data[i][j]+11*ABs.A_4_21.data[i][j]-ABs.A_4_22.data[i][j]-11*ABs.A_21_15.data[i][j]-ABs.A_21_1.data[i][j]+ABs.A_21_16.data[i][j]-ABs.A_21_2.data[i][j]+ABs.A_21_17.data[i][j]-ABs.A_21_3.data[i][j]+ABs.A_21_18.data[i][j]-ABs.A_21_4.data[i][j]+ABs.A_21_19.data[i][j]-ABs.A_21_5.data[i][j]+ABs.A_21_20.data[i][j]-ABs.A_21_6.data[i][j]+ABs.A_21_21.data[i][j]-ABs.A_21_7.data[i][j]+ABs.A_21_22.data[i][j]-ABs.A_21_8.data[i][j]-ABs.A_21_9.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_15_10.data[i][j]+ABs.B_10_15.data[i][j]+ABs.B_21_21.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
