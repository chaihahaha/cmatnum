#include "fm_2894.h"

inline int fm_2894(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_18_12.data[i][j]-ABs.A_18_13.data[i][j]-ABs.A_18_14.data[i][j]-ABs.A_18_15.data[i][j]-ABs.A_18_16.data[i][j]-ABs.A_18_17.data[i][j]-ABs.A_18_18.data[i][j]-ABs.A_18_19.data[i][j]-ABs.A_18_20.data[i][j]-ABs.A_18_21.data[i][j]+11*ABs.A_18_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_7_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

