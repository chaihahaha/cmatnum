#include "fm_1698.h"

inline int fm_1698(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_10_13.data[i][j]-ABs.A_10_14.data[i][j]-ABs.A_10_15.data[i][j]-ABs.A_10_16.data[i][j]+11*ABs.A_10_17.data[i][j]-ABs.A_10_18.data[i][j]-ABs.A_10_19.data[i][j]-ABs.A_10_20.data[i][j]-ABs.A_10_21.data[i][j]-ABs.A_10_22.data[i][j]+ABs.A_6_11.data[i][j]+ABs.A_6_1.data[i][j]-11*ABs.A_6_2.data[i][j]+ABs.A_6_3.data[i][j]+ABs.A_6_4.data[i][j]+ABs.A_6_5.data[i][j]+ABs.A_6_6.data[i][j]+ABs.A_6_7.data[i][j]+ABs.A_6_8.data[i][j]+ABs.A_6_9.data[i][j]+ABs.A_6_10.data[i][j]-ABs.A_10_12.data[i][j]-ABs.A_13_11.data[i][j]-ABs.A_13_1.data[i][j]-ABs.A_13_2.data[i][j]-ABs.A_13_3.data[i][j]-ABs.A_13_4.data[i][j]-ABs.A_13_5.data[i][j]-ABs.A_13_6.data[i][j]-ABs.A_13_7.data[i][j]-ABs.A_13_8.data[i][j]-ABs.A_13_9.data[i][j]+11*ABs.A_13_10.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_17_2.data[i][j]+ABs.B_10_6.data[i][j]+ABs.B_2_21.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

