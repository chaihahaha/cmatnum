#include "fAx3928.h"

inline int fAx3928(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3928.data[i][j] = bmats.A_10_5.data[i][j] - 16*bmats.A_10_6.data[i][j] + bmats.A_11_5.data[i][j] - 16*bmats.A_11_6.data[i][j] + bmats.A_12_5.data[i][j] - 16*bmats.A_12_6.data[i][j] + bmats.A_13_5.data[i][j] - 16*bmats.A_13_6.data[i][j] + bmats.A_16_5.data[i][j] - 16*bmats.A_16_6.data[i][j] + bmats.A_1_5.data[i][j] - 16*bmats.A_1_6.data[i][j] + bmats.A_2_5.data[i][j] - 16*bmats.A_2_6.data[i][j] + bmats.A_3_5.data[i][j] - 16*bmats.A_3_6.data[i][j] + bmats.A_4_5.data[i][j] - 16*bmats.A_4_6.data[i][j] + bmats.A_5_5.data[i][j] - 16*bmats.A_5_6.data[i][j] - 17*bmats.A_6_6.data[i][j] + bmats.A_7_5.data[i][j] - 16*bmats.A_7_6.data[i][j] + bmats.A_8_5.data[i][j] - 16*bmats.A_8_6.data[i][j] + bmats.A_9_5.data[i][j] - 16*bmats.A_9_6.data[i][j] + bmats.Ax2086.data[i][j] + bmats.Ax2445.data[i][j] + bmats.Ax2786.data[i][j] + bmats.Ax3074.data[i][j] + bmats.Ax3299.data[i][j] + bmats.Ax3541.data[i][j] + bmats.Ax3828.data[i][j] + bmats.Ax3911.data[i][j] + bmats.Ax3914.data[i][j] + bmats.Ax3917.data[i][j] + bmats.Ax3920.data[i][j] + bmats.Ax3923.data[i][j] + bmats.Ax3926.data[i][j];
        }
    }
    return 0;
}
