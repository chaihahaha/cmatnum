#include "fm_1858.h"

int fm_1858(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +ABs.A_2_11.data[i][j]-11*ABs.A_2_1.data[i][j]+ABs.A_2_2.data[i][j]+ABs.A_2_3.data[i][j]+ABs.A_2_4.data[i][j]+ABs.A_2_5.data[i][j]+ABs.A_2_6.data[i][j]+ABs.A_2_7.data[i][j]+ABs.A_2_8.data[i][j]+ABs.A_2_9.data[i][j]+ABs.A_2_10.data[i][j]-ABs.A_6_12.data[i][j]+11*ABs.A_6_13.data[i][j]-ABs.A_6_14.data[i][j]-ABs.A_6_15.data[i][j]-ABs.A_6_16.data[i][j]-ABs.A_6_17.data[i][j]-ABs.A_6_18.data[i][j]-ABs.A_6_19.data[i][j]-ABs.A_6_20.data[i][j]-ABs.A_6_21.data[i][j]-ABs.A_6_22.data[i][j]-ABs.A_12_11.data[i][j]-ABs.A_12_1.data[i][j]-ABs.A_12_2.data[i][j]-ABs.A_12_3.data[i][j]-ABs.A_12_4.data[i][j]-ABs.A_12_5.data[i][j]+11*ABs.A_12_6.data[i][j]-ABs.A_12_7.data[i][j]-ABs.A_12_8.data[i][j]-ABs.A_12_9.data[i][j]-ABs.A_12_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_13_1.data[i][j]+ABs.B_6_2.data[i][j]+ABs.B_1_17.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
