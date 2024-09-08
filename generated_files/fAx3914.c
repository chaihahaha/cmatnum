#include "fAx3914.h"

inline int fAx3914(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3914.data[i][j] = bmats.A_5_1.data[i][j] + bmats.A_5_10.data[i][j] + bmats.A_5_11.data[i][j] + bmats.A_5_12.data[i][j] + bmats.A_5_13.data[i][j] + bmats.A_5_14.data[i][j] + bmats.A_5_15.data[i][j] + bmats.A_5_16.data[i][j] + bmats.A_5_2.data[i][j] + bmats.A_5_3.data[i][j] + bmats.A_5_4.data[i][j] + bmats.A_5_7.data[i][j] + bmats.A_5_8.data[i][j] + bmats.A_5_9.data[i][j];
        }
    }
    return 0;
}
