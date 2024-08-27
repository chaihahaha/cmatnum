#include "fm_2816.h"

inline int fm_2816(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_11_1.data[i][j]-ABs.A_11_2.data[i][j]-ABs.A_11_3.data[i][j]-ABs.A_11_4.data[i][j]-ABs.A_11_5.data[i][j]-ABs.A_11_6.data[i][j]-ABs.A_11_7.data[i][j]-ABs.A_11_8.data[i][j]-ABs.A_11_9.data[i][j]-ABs.A_11_10.data[i][j]-ABs.A_11_11.data[i][j]-ABs.A_11_12.data[i][j]-ABs.A_11_13.data[i][j]-ABs.A_11_14.data[i][j]-ABs.A_11_15.data[i][j]-ABs.A_11_16.data[i][j]-ABs.A_11_17.data[i][j]-ABs.A_11_18.data[i][j]-ABs.A_11_19.data[i][j]-ABs.A_11_20.data[i][j]-ABs.A_11_21.data[i][j]-ABs.A_11_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = -ABs.B_11_1.data[i][j]-ABs.B_11_2.data[i][j]-ABs.B_11_3.data[i][j]-ABs.B_11_4.data[i][j]-ABs.B_11_5.data[i][j]-ABs.B_11_6.data[i][j]-ABs.B_11_7.data[i][j]-ABs.B_11_8.data[i][j]-ABs.B_11_9.data[i][j]-ABs.B_11_10.data[i][j]-ABs.B_11_11.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

