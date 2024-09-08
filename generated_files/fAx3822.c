#include "fAx3822.h"

inline int fAx3822(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3822.data[i][j] = bmats.A_23_1.data[i][j] + bmats.A_23_10.data[i][j] + bmats.A_23_11.data[i][j] + bmats.A_23_12.data[i][j] + bmats.A_23_13.data[i][j] + bmats.A_23_14.data[i][j] + bmats.A_23_15.data[i][j] + bmats.A_23_16.data[i][j] + bmats.A_23_2.data[i][j] + bmats.A_23_3.data[i][j] + bmats.A_23_4.data[i][j] + bmats.A_23_7.data[i][j] + bmats.A_23_8.data[i][j] + bmats.A_23_9.data[i][j];
        }
    }
    return 0;
}
