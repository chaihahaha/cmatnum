#include "fAx3528.h"

inline int fAx3528(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3528.data[i][j] = bmats.A_12_7.data[i][j] - 16*bmats.A_12_8.data[i][j] + bmats.A_13_7.data[i][j] - 16*bmats.A_13_8.data[i][j] + bmats.A_14_7.data[i][j] - 16*bmats.A_14_8.data[i][j] + bmats.A_15_7.data[i][j] - 16*bmats.A_15_8.data[i][j] + bmats.A_16_7.data[i][j] - 16*bmats.A_16_8.data[i][j] + bmats.A_1_7.data[i][j] - 16*bmats.A_1_8.data[i][j] + bmats.A_2_7.data[i][j] - 16*bmats.A_2_8.data[i][j] + bmats.A_3_7.data[i][j] - 16*bmats.A_3_8.data[i][j] + bmats.A_4_7.data[i][j] - 16*bmats.A_4_8.data[i][j] + bmats.A_5_7.data[i][j] - 16*bmats.A_5_8.data[i][j] + bmats.A_6_7.data[i][j] - 16*bmats.A_6_8.data[i][j] + bmats.A_7_7.data[i][j] - 16*bmats.A_7_8.data[i][j] - 17*bmats.A_8_8.data[i][j] + bmats.A_9_7.data[i][j] - 16*bmats.A_9_8.data[i][j] + bmats.Ax1391.data[i][j] + bmats.Ax2034.data[i][j] + bmats.Ax2460.data[i][j] + bmats.Ax3252.data[i][j] + bmats.Ax3455.data[i][j] + bmats.Ax3458.data[i][j] + bmats.Ax3461.data[i][j] + bmats.Ax3464.data[i][j] + bmats.Ax3467.data[i][j] + bmats.Ax3470.data[i][j] + bmats.Ax3473.data[i][j] + bmats.Ax3476.data[i][j] + bmats.Ax3489.data[i][j];
        }
    }
    return 0;
}
