#include "fm_5002.h"

inline int fm_5002(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_22_15.data[i][j]-ABs.A_22_16.data[i][j]-ABs.A_22_17.data[i][j]-ABs.A_22_18.data[i][j]+11*ABs.A_22_19.data[i][j]-ABs.A_22_20.data[i][j]-ABs.A_22_21.data[i][j]-ABs.A_22_22.data[i][j]-ABs.A_22_12.data[i][j]-ABs.A_22_13.data[i][j]-ABs.A_22_14.data[i][j]-ABs.A_14_13.data[i][j]-ABs.A_14_14.data[i][j]-ABs.A_14_15.data[i][j]-ABs.A_14_16.data[i][j]-ABs.A_14_17.data[i][j]-ABs.A_14_18.data[i][j]-ABs.A_14_19.data[i][j]-ABs.A_14_20.data[i][j]-ABs.A_14_21.data[i][j]+11*ABs.A_14_22.data[i][j]-ABs.A_14_12.data[i][j]-ABs.A_19_12.data[i][j]-ABs.A_19_13.data[i][j]+11*ABs.A_19_14.data[i][j]-ABs.A_19_15.data[i][j]-ABs.A_19_16.data[i][j]-ABs.A_19_17.data[i][j]-ABs.A_19_18.data[i][j]-ABs.A_19_19.data[i][j]-ABs.A_19_20.data[i][j]-ABs.A_19_21.data[i][j]-ABs.A_19_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_19_14.data[i][j]+ABs.B_22_19.data[i][j]+ABs.B_14_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

