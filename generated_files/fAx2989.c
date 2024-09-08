#include "fAx2989.h"

inline int fAx2989(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2989.data[i][j] = bmats.A_10_1.data[i][j] + bmats.A_10_10.data[i][j] + bmats.A_10_11.data[i][j] + bmats.A_10_12.data[i][j] + bmats.A_10_13.data[i][j] + bmats.A_10_14.data[i][j] + bmats.A_10_15.data[i][j] + bmats.A_10_16.data[i][j] + bmats.A_10_2.data[i][j] + bmats.A_10_3.data[i][j] + bmats.A_10_4.data[i][j] + bmats.A_10_5.data[i][j] + bmats.A_10_6.data[i][j] + bmats.A_10_9.data[i][j];
        }
    }
    return 0;
}
