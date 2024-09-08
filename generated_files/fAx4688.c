#include "fAx4688.h"

inline int fAx4688(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4688.data[i][j] = bmats.A_10_17.data[i][j] - 16*bmats.A_10_18.data[i][j] + bmats.A_11_17.data[i][j] - 16*bmats.A_11_18.data[i][j] + bmats.A_12_17.data[i][j] - 16*bmats.A_12_18.data[i][j] + bmats.A_13_17.data[i][j] - 16*bmats.A_13_18.data[i][j] + bmats.A_14_17.data[i][j] - 16*bmats.A_14_18.data[i][j] + bmats.A_15_17.data[i][j] - 16*bmats.A_15_18.data[i][j] + bmats.A_16_17.data[i][j] - 16*bmats.A_16_18.data[i][j] + bmats.A_1_17.data[i][j] - 16*bmats.A_1_18.data[i][j] + bmats.A_2_17.data[i][j] - 16*bmats.A_2_18.data[i][j] + bmats.A_3_17.data[i][j] - 16*bmats.A_3_18.data[i][j] + bmats.A_4_17.data[i][j] - 16*bmats.A_4_18.data[i][j] + bmats.A_5_17.data[i][j] - 16*bmats.A_5_18.data[i][j] + bmats.A_6_17.data[i][j] - 16*bmats.A_6_18.data[i][j] + bmats.A_7_17.data[i][j] - 16*bmats.A_7_18.data[i][j] + bmats.A_8_17.data[i][j] - 16*bmats.A_8_18.data[i][j] + bmats.A_9_17.data[i][j] - 16*bmats.A_9_18.data[i][j] + bmats.Ax1766.data[i][j] + bmats.Ax2128.data[i][j] + bmats.Ax2636.data[i][j] + bmats.Ax2885.data[i][j] + bmats.Ax3111.data[i][j] + bmats.Ax3338.data[i][j] + bmats.Ax3723.data[i][j] + bmats.Ax3878.data[i][j] + bmats.Ax4084.data[i][j] + bmats.Ax4395.data[i][j] + bmats.Ax4530.data[i][j] + bmats.Ax4589.data[i][j] + bmats.Ax4680.data[i][j] + bmats.Ax4683.data[i][j] + bmats.Ax4686.data[i][j] + bmats.Ax658.data[i][j];
        }
    }
    return 0;
}
