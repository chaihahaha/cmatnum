#include "fAx4126.h"

inline int fAx4126(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4126.data[i][j] = -16*bmats.A_10_21.data[i][j] + bmats.A_10_22.data[i][j] - 16*bmats.A_11_21.data[i][j] + bmats.A_11_22.data[i][j] - 16*bmats.A_12_21.data[i][j] + bmats.A_12_22.data[i][j] - 16*bmats.A_13_21.data[i][j] + bmats.A_13_22.data[i][j] - 16*bmats.A_14_21.data[i][j] + bmats.A_14_22.data[i][j] - 16*bmats.A_15_21.data[i][j] + bmats.A_15_22.data[i][j] - 16*bmats.A_16_21.data[i][j] + bmats.A_16_22.data[i][j] - 16*bmats.A_1_21.data[i][j] + bmats.A_1_22.data[i][j] - 16*bmats.A_2_21.data[i][j] + bmats.A_2_22.data[i][j] - 16*bmats.A_3_21.data[i][j] + bmats.A_3_22.data[i][j] - 16*bmats.A_4_21.data[i][j] + bmats.A_4_22.data[i][j] - 16*bmats.A_5_21.data[i][j] + bmats.A_5_22.data[i][j] - 16*bmats.A_6_21.data[i][j] + bmats.A_6_22.data[i][j] - 16*bmats.A_7_21.data[i][j] + bmats.A_7_22.data[i][j] - 16*bmats.A_8_21.data[i][j] + bmats.A_8_22.data[i][j] - 16*bmats.A_9_21.data[i][j] + bmats.A_9_22.data[i][j] + bmats.Ax1630.data[i][j] + bmats.Ax2080.data[i][j] + bmats.Ax2442.data[i][j] + bmats.Ax2783.data[i][j] + bmats.Ax3071.data[i][j] + bmats.Ax3296.data[i][j] + bmats.Ax3538.data[i][j] + bmats.Ax3825.data[i][j] + bmats.Ax3844.data[i][j] + bmats.Ax3847.data[i][j] + bmats.Ax3850.data[i][j] + bmats.Ax3853.data[i][j] + bmats.Ax3856.data[i][j] + bmats.Ax3859.data[i][j] + bmats.Ax3862.data[i][j] + bmats.Ax3865.data[i][j];
        }
    }
    return 0;
}
