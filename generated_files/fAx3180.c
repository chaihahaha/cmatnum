#include "fAx3180.h"

inline int fAx3180(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3180.data[i][j] = -16*bmats.A_10_25.data[i][j] + bmats.A_10_26.data[i][j] - 16*bmats.A_11_25.data[i][j] + bmats.A_11_26.data[i][j] - 16*bmats.A_12_25.data[i][j] + bmats.A_12_26.data[i][j] - 16*bmats.A_13_25.data[i][j] + bmats.A_13_26.data[i][j] - 16*bmats.A_14_25.data[i][j] + bmats.A_14_26.data[i][j] - 16*bmats.A_15_25.data[i][j] + bmats.A_15_26.data[i][j] - 16*bmats.A_16_25.data[i][j] + bmats.A_16_26.data[i][j] - 16*bmats.A_1_25.data[i][j] + bmats.A_1_26.data[i][j] - 16*bmats.A_2_25.data[i][j] + bmats.A_2_26.data[i][j] - 16*bmats.A_3_25.data[i][j] + bmats.A_3_26.data[i][j] - 16*bmats.A_4_25.data[i][j] + bmats.A_4_26.data[i][j] - 16*bmats.A_5_25.data[i][j] + bmats.A_5_26.data[i][j] - 16*bmats.A_6_25.data[i][j] + bmats.A_6_26.data[i][j] - 16*bmats.A_7_25.data[i][j] + bmats.A_7_26.data[i][j] - 16*bmats.A_8_25.data[i][j] + bmats.A_8_26.data[i][j] - 16*bmats.A_9_25.data[i][j] + bmats.A_9_26.data[i][j] + bmats.Ax1489.data[i][j] + bmats.Ax2047.data[i][j] + bmats.Ax2387.data[i][j] + bmats.Ax2674.data[i][j] + bmats.Ax2839.data[i][j] + bmats.Ax2842.data[i][j] + bmats.Ax2845.data[i][j] + bmats.Ax2848.data[i][j] + bmats.Ax2851.data[i][j] + bmats.Ax2854.data[i][j] + bmats.Ax2857.data[i][j] + bmats.Ax2860.data[i][j] + bmats.Ax2863.data[i][j] + bmats.Ax2866.data[i][j] + bmats.Ax2869.data[i][j] + bmats.Ax2872.data[i][j];
        }
    }
    return 0;
}
