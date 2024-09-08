#include "fAx4236.h"

inline int fAx4236(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4236.data[i][j] = bmats.A_21_1.data[i][j] + bmats.A_21_10.data[i][j] + bmats.A_21_11.data[i][j] + bmats.A_21_12.data[i][j] + bmats.A_21_13.data[i][j] + bmats.A_21_14.data[i][j] + bmats.A_21_15.data[i][j] + bmats.A_21_16.data[i][j] + bmats.A_21_2.data[i][j] + bmats.A_21_5.data[i][j] + bmats.A_21_6.data[i][j] + bmats.A_21_7.data[i][j] + bmats.A_21_8.data[i][j] + bmats.A_21_9.data[i][j];
        }
    }
    return 0;
}
