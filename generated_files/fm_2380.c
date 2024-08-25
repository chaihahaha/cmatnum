#include "fm_2380.h"

int fm_2380(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +11*ABs.A_1_12.data[i][j]-ABs.A_1_13.data[i][j]-ABs.A_1_14.data[i][j]-ABs.A_1_15.data[i][j]-ABs.A_1_16.data[i][j]-ABs.A_1_17.data[i][j]-ABs.A_1_18.data[i][j]-ABs.A_1_19.data[i][j]-ABs.A_1_20.data[i][j]-ABs.A_1_21.data[i][j]-ABs.A_1_22.data[i][j]-ABs.A_12_11.data[i][j]-ABs.A_12_1.data[i][j]-ABs.A_12_2.data[i][j]-ABs.A_12_3.data[i][j]-ABs.A_12_4.data[i][j]-ABs.A_12_5.data[i][j]-ABs.A_12_6.data[i][j]-ABs.A_12_7.data[i][j]+11*ABs.A_12_8.data[i][j]-ABs.A_12_9.data[i][j]-ABs.A_12_10.data[i][j]-11*ABs.A_19_12.data[i][j]+ABs.A_19_13.data[i][j]+ABs.A_19_14.data[i][j]+ABs.A_19_15.data[i][j]+ABs.A_19_16.data[i][j]+ABs.A_19_17.data[i][j]+ABs.A_19_18.data[i][j]+ABs.A_19_19.data[i][j]+ABs.A_19_20.data[i][j]+ABs.A_19_21.data[i][j]+ABs.A_19_22.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_12_1.data[i][j]+ABs.B_8_12.data[i][j]+ABs.B_12_19.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
