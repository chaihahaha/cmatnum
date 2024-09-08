#include "fAx3713.h"

inline int fAx3713(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3713.data[i][j] = -16*bmats.A_10_23.data[i][j] + bmats.A_10_24.data[i][j] - 16*bmats.A_11_23.data[i][j] + bmats.A_11_24.data[i][j] - 16*bmats.A_12_23.data[i][j] + bmats.A_12_24.data[i][j] - 16*bmats.A_13_23.data[i][j] + bmats.A_13_24.data[i][j] - 16*bmats.A_14_23.data[i][j] + bmats.A_14_24.data[i][j] - 16*bmats.A_15_23.data[i][j] + bmats.A_15_24.data[i][j] - 16*bmats.A_16_23.data[i][j] + bmats.A_16_24.data[i][j] - 16*bmats.A_1_23.data[i][j] + bmats.A_1_24.data[i][j] - 16*bmats.A_2_23.data[i][j] + bmats.A_2_24.data[i][j] - 16*bmats.A_3_23.data[i][j] + bmats.A_3_24.data[i][j] - 16*bmats.A_4_23.data[i][j] + bmats.A_4_24.data[i][j] - 16*bmats.A_5_23.data[i][j] + bmats.A_5_24.data[i][j] - 16*bmats.A_6_23.data[i][j] + bmats.A_6_24.data[i][j] - 16*bmats.A_7_23.data[i][j] + bmats.A_7_24.data[i][j] - 16*bmats.A_8_23.data[i][j] + bmats.A_8_24.data[i][j] - 16*bmats.A_9_23.data[i][j] + bmats.A_9_24.data[i][j] + bmats.Ax1427.data[i][j] + bmats.Ax2028.data[i][j] + bmats.Ax2457.data[i][j] + bmats.Ax2729.data[i][j] + bmats.Ax3005.data[i][j] + bmats.Ax3325.data[i][j] + bmats.Ax3421.data[i][j] + bmats.Ax3424.data[i][j] + bmats.Ax3427.data[i][j] + bmats.Ax3430.data[i][j] + bmats.Ax3433.data[i][j] + bmats.Ax3436.data[i][j] + bmats.Ax3439.data[i][j] + bmats.Ax3442.data[i][j] + bmats.Ax3445.data[i][j] + bmats.Ax3448.data[i][j];
        }
    }
    return 0;
}
