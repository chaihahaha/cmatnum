#include "fm_4570.h"

inline int fm_4570(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_2_12.data[i][j]-ABs.A_2_13.data[i][j]+11*ABs.A_2_14.data[i][j]-ABs.A_2_15.data[i][j]-ABs.A_2_16.data[i][j]-ABs.A_2_17.data[i][j]-ABs.A_2_18.data[i][j]-ABs.A_2_19.data[i][j]-ABs.A_2_20.data[i][j]-ABs.A_2_21.data[i][j]-ABs.A_2_22.data[i][j]-ABs.A_14_11.data[i][j]-ABs.A_14_1.data[i][j]-ABs.A_14_2.data[i][j]-ABs.A_14_3.data[i][j]+11*ABs.A_14_4.data[i][j]-ABs.A_14_5.data[i][j]-ABs.A_14_6.data[i][j]-ABs.A_14_7.data[i][j]-ABs.A_14_8.data[i][j]-ABs.A_14_9.data[i][j]-ABs.A_14_10.data[i][j]+ABs.A_15_12.data[i][j]-11*ABs.A_15_13.data[i][j]+ABs.A_15_14.data[i][j]+ABs.A_15_15.data[i][j]+ABs.A_15_16.data[i][j]+ABs.A_15_17.data[i][j]+ABs.A_15_18.data[i][j]+ABs.A_15_19.data[i][j]+ABs.A_15_20.data[i][j]+ABs.A_15_21.data[i][j]+ABs.A_15_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_13_3.data[i][j]+ABs.B_4_13.data[i][j]+ABs.B_14_15.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

