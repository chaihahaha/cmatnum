#include "fm_2448.h"

int fm_2448(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_11_13.data[i][j]-ABs.A_11_14.data[i][j]+11*ABs.A_11_15.data[i][j]-ABs.A_11_16.data[i][j]-ABs.A_11_17.data[i][j]-ABs.A_11_18.data[i][j]-ABs.A_11_19.data[i][j]-ABs.A_11_20.data[i][j]-ABs.A_11_21.data[i][j]-ABs.A_11_22.data[i][j]-ABs.A_11_12.data[i][j]-ABs.A_15_10.data[i][j]-ABs.A_15_11.data[i][j]-ABs.A_15_4.data[i][j]-ABs.A_15_5.data[i][j]-ABs.A_15_6.data[i][j]+11*ABs.A_15_7.data[i][j]-ABs.A_15_8.data[i][j]-ABs.A_15_9.data[i][j]-ABs.A_15_1.data[i][j]-ABs.A_15_2.data[i][j]-ABs.A_15_3.data[i][j]+ABs.A_18_16.data[i][j]+ABs.A_18_15.data[i][j]+ABs.A_18_12.data[i][j]+ABs.A_18_14.data[i][j]+ABs.A_18_13.data[i][j]+ABs.A_18_17.data[i][j]+ABs.A_18_18.data[i][j]+ABs.A_18_19.data[i][j]+ABs.A_18_20.data[i][j]+ABs.A_18_21.data[i][j]-11*ABs.A_18_22.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_22_4.data[i][j]+ABs.B_15_18.data[i][j]+ABs.B_7_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
