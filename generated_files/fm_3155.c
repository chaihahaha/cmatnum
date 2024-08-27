#include "fm_3155.h"

inline int fm_3155(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = +ABs.A_9_12.data[i][j]+ABs.A_9_13.data[i][j]+ABs.A_9_14.data[i][j]+ABs.A_9_15.data[i][j]+ABs.A_9_16.data[i][j]+ABs.A_9_17.data[i][j]+ABs.A_9_18.data[i][j]-11*ABs.A_9_19.data[i][j]+ABs.A_9_20.data[i][j]+ABs.A_9_21.data[i][j]+ABs.A_9_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_20_8.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

