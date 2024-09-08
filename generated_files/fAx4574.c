#include "fAx4574.h"

inline int fAx4574(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4574.data[i][j] = -16*bmats.A_11_3.data[i][j] + bmats.A_11_4.data[i][j] - 16*bmats.A_12_3.data[i][j] + bmats.A_12_4.data[i][j] - 16*bmats.A_13_3.data[i][j] + bmats.A_13_4.data[i][j] - 16*bmats.A_14_3.data[i][j] + bmats.A_14_4.data[i][j] - 16*bmats.A_15_3.data[i][j] + bmats.A_15_4.data[i][j] - 16*bmats.A_16_3.data[i][j] + bmats.A_16_4.data[i][j] - 16*bmats.A_1_3.data[i][j] + bmats.A_1_4.data[i][j] - 16*bmats.A_2_3.data[i][j] + bmats.A_2_4.data[i][j] - 17*bmats.A_3_3.data[i][j] - 16*bmats.A_4_3.data[i][j] + bmats.A_4_4.data[i][j] - 16*bmats.A_6_3.data[i][j] + bmats.A_6_4.data[i][j] - 16*bmats.A_7_3.data[i][j] + bmats.A_7_4.data[i][j] - 16*bmats.A_8_3.data[i][j] + bmats.A_8_4.data[i][j] - 16*bmats.A_9_3.data[i][j] + bmats.A_9_4.data[i][j] + bmats.Ax1590.data[i][j] + bmats.Ax2152.data[i][j] + bmats.Ax2489.data[i][j] + bmats.Ax2771.data[i][j] + bmats.Ax3357.data[i][j] + bmats.Ax3601.data[i][j] + bmats.Ax3813.data[i][j] + bmats.Ax4102.data[i][j] + bmats.Ax4336.data[i][j] + bmats.Ax4342.data[i][j] + bmats.Ax4363.data[i][j] + bmats.Ax4366.data[i][j] + bmats.Ax944.data[i][j];
        }
    }
    return 0;
}
