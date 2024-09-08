#include "fBx2491.h"

inline int fBx2491(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2491.data[i][j] = bmats.B_30_10.data[i][j] + bmats.B_30_11.data[i][j] + bmats.B_30_12.data[i][j] + bmats.B_30_13.data[i][j] + bmats.B_30_14.data[i][j] + bmats.B_30_15.data[i][j] + bmats.B_30_16.data[i][j] + bmats.B_30_2.data[i][j] + bmats.B_30_3.data[i][j] + bmats.B_30_4.data[i][j] + bmats.B_30_5.data[i][j] + bmats.B_30_6.data[i][j] + bmats.B_30_7.data[i][j] + bmats.B_30_8.data[i][j] + bmats.B_30_9.data[i][j];
        }
    }
    return 0;
}
