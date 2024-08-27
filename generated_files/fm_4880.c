#include "fm_4880.h"

inline int fm_4880(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = +11*ABs.A_22_15.data[i][j]-ABs.A_22_16.data[i][j]-ABs.A_22_17.data[i][j]-ABs.A_22_18.data[i][j]-ABs.A_22_19.data[i][j]-ABs.A_22_20.data[i][j]-ABs.A_22_21.data[i][j]-ABs.A_22_22.data[i][j]-ABs.A_22_12.data[i][j]-ABs.A_22_13.data[i][j]-ABs.A_22_14.data[i][j]-ABs.A_15_12.data[i][j]-ABs.A_15_13.data[i][j]-ABs.A_15_14.data[i][j]-ABs.A_15_15.data[i][j]-ABs.A_15_16.data[i][j]+11*ABs.A_15_17.data[i][j]-ABs.A_15_18.data[i][j]-ABs.A_15_19.data[i][j]-ABs.A_15_20.data[i][j]-ABs.A_15_21.data[i][j]-ABs.A_15_22.data[i][j]-ABs.A_17_19.data[i][j]-ABs.A_17_20.data[i][j]+11*ABs.A_17_22.data[i][j]-ABs.A_17_21.data[i][j]-ABs.A_17_18.data[i][j]-ABs.A_17_17.data[i][j]-ABs.A_17_16.data[i][j]-ABs.A_17_15.data[i][j]-ABs.A_17_14.data[i][j]-ABs.A_17_13.data[i][j]-ABs.A_17_12.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_22_15.data[i][j]+ABs.B_15_17.data[i][j]+ABs.B_17_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

