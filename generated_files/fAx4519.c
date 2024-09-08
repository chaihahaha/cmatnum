#include "fAx4519.h"

inline int fAx4519(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4519.data[i][j] = -16*bmats.A_10_19.data[i][j] + bmats.A_10_20.data[i][j] - 16*bmats.A_11_19.data[i][j] + bmats.A_11_20.data[i][j] - 16*bmats.A_12_19.data[i][j] + bmats.A_12_20.data[i][j] - 16*bmats.A_13_19.data[i][j] + bmats.A_13_20.data[i][j] - 16*bmats.A_14_19.data[i][j] + bmats.A_14_20.data[i][j] - 16*bmats.A_15_19.data[i][j] + bmats.A_15_20.data[i][j] - 16*bmats.A_16_19.data[i][j] + bmats.A_16_20.data[i][j] - 16*bmats.A_1_19.data[i][j] + bmats.A_1_20.data[i][j] - 16*bmats.A_2_19.data[i][j] + bmats.A_2_20.data[i][j] - 16*bmats.A_3_19.data[i][j] + bmats.A_3_20.data[i][j] - 16*bmats.A_4_19.data[i][j] + bmats.A_4_20.data[i][j] - 16*bmats.A_5_19.data[i][j] + bmats.A_5_20.data[i][j] - 16*bmats.A_6_19.data[i][j] + bmats.A_6_20.data[i][j] - 16*bmats.A_7_19.data[i][j] + bmats.A_7_20.data[i][j] - 16*bmats.A_8_19.data[i][j] + bmats.A_8_20.data[i][j] - 16*bmats.A_9_19.data[i][j] + bmats.A_9_20.data[i][j] + bmats.Ax1784.data[i][j] + bmats.Ax2146.data[i][j] + bmats.Ax2486.data[i][j] + bmats.Ax2768.data[i][j] + bmats.Ax3125.data[i][j] + bmats.Ax3354.data[i][j] + bmats.Ax3598.data[i][j] + bmats.Ax3810.data[i][j] + bmats.Ax4099.data[i][j] + bmats.Ax4239.data[i][j] + bmats.Ax4313.data[i][j] + bmats.Ax4318.data[i][j] + bmats.Ax4321.data[i][j] + bmats.Ax4324.data[i][j] + bmats.Ax4327.data[i][j] + bmats.Ax918.data[i][j];
        }
    }
    return 0;
}
