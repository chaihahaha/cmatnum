#include "fm_2535.h"

int fm_2535(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_4_12.data[i][j]-ABs.A_4_13.data[i][j]-ABs.A_4_14.data[i][j]-ABs.A_4_15.data[i][j]-ABs.A_4_16.data[i][j]-ABs.A_4_17.data[i][j]+11*ABs.A_4_18.data[i][j]-ABs.A_4_19.data[i][j]-ABs.A_4_20.data[i][j]-ABs.A_4_21.data[i][j]-ABs.A_4_22.data[i][j]-ABs.A_18_10.data[i][j]+ABs.A_17_19.data[i][j]-ABs.A_18_9.data[i][j]-ABs.A_18_5.data[i][j]-ABs.A_18_11.data[i][j]+ABs.A_17_20.data[i][j]-ABs.A_18_1.data[i][j]-ABs.A_18_2.data[i][j]+ABs.A_17_22.data[i][j]-ABs.A_18_4.data[i][j]-ABs.A_18_3.data[i][j]+ABs.A_17_21.data[i][j]+11*ABs.A_18_6.data[i][j]+ABs.A_17_18.data[i][j]-ABs.A_18_7.data[i][j]+ABs.A_17_17.data[i][j]-ABs.A_18_8.data[i][j]+ABs.A_17_16.data[i][j]-11*ABs.A_17_15.data[i][j]+ABs.A_17_14.data[i][j]+ABs.A_17_13.data[i][j]+ABs.A_17_12.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_15_7.data[i][j]+ABs.B_6_15.data[i][j]+ABs.B_18_17.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
