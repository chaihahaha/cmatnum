#include "fAx4715.h"

inline int fAx4715(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4715.data[i][j] = bmats.A_11_1.data[i][j] - 16*bmats.A_11_2.data[i][j] + bmats.A_12_1.data[i][j] - 16*bmats.A_12_2.data[i][j] + bmats.A_13_1.data[i][j] - 16*bmats.A_13_2.data[i][j] + bmats.A_14_1.data[i][j] - 16*bmats.A_14_2.data[i][j] + bmats.A_15_1.data[i][j] - 16*bmats.A_15_2.data[i][j] + bmats.A_16_1.data[i][j] - 16*bmats.A_16_2.data[i][j] + bmats.A_1_1.data[i][j] - 16*bmats.A_1_2.data[i][j] - 17*bmats.A_2_2.data[i][j] + bmats.A_3_1.data[i][j] - 16*bmats.A_3_2.data[i][j] + bmats.A_4_1.data[i][j] - 16*bmats.A_4_2.data[i][j] + bmats.A_6_1.data[i][j] - 16*bmats.A_6_2.data[i][j] + bmats.A_7_1.data[i][j] - 16*bmats.A_7_2.data[i][j] + bmats.A_8_1.data[i][j] - 16*bmats.A_8_2.data[i][j] + bmats.A_9_1.data[i][j] - 16*bmats.A_9_2.data[i][j] + bmats.Ax1754.data[i][j] + bmats.Ax2134.data[i][j] + bmats.Ax2641.data[i][j] + bmats.Ax2888.data[i][j] + bmats.Ax3341.data[i][j] + bmats.Ax3726.data[i][j] + bmats.Ax3881.data[i][j] + bmats.Ax4087.data[i][j] + bmats.Ax4533.data[i][j] + bmats.Ax4592.data[i][j] + bmats.Ax4644.data[i][j] + bmats.Ax4647.data[i][j] + bmats.Ax742.data[i][j];
        }
    }
    return 0;
}
