#include "fAx2275.h"

inline int fAx2275(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2275.data[i][j] = bmats.A_20_1.data[i][j] + bmats.A_20_10.data[i][j] + bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] + bmats.A_20_15.data[i][j] + bmats.A_20_16.data[i][j] + bmats.A_20_2.data[i][j] + bmats.A_20_3.data[i][j] + bmats.A_20_4.data[i][j] + bmats.A_20_5.data[i][j] + bmats.A_20_6.data[i][j] + bmats.A_20_7.data[i][j] + bmats.A_20_8.data[i][j] + bmats.A_20_9.data[i][j];
        }
    }
    return 0;
}
