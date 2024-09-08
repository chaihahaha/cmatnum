#include "fAx4508.h"

inline int fAx4508(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4508.data[i][j] = -16*bmats.A_17_3.data[i][j] + bmats.A_17_4.data[i][j] - 16*bmats.A_18_3.data[i][j] + bmats.A_18_4.data[i][j] - 16*bmats.A_19_3.data[i][j] + bmats.A_19_4.data[i][j] - 16*bmats.A_20_3.data[i][j] + bmats.A_20_4.data[i][j] - 16*bmats.A_21_3.data[i][j] + bmats.A_21_4.data[i][j] - 16*bmats.A_22_3.data[i][j] + bmats.A_22_4.data[i][j] - 16*bmats.A_23_3.data[i][j] + bmats.A_23_4.data[i][j] - 16*bmats.A_24_3.data[i][j] + bmats.A_24_4.data[i][j] - 16*bmats.A_25_3.data[i][j] + bmats.A_25_4.data[i][j] - 16*bmats.A_26_3.data[i][j] + bmats.A_26_4.data[i][j] - 16*bmats.A_27_3.data[i][j] + bmats.A_27_4.data[i][j] - 16*bmats.A_28_3.data[i][j] + bmats.A_28_4.data[i][j] - 16*bmats.A_29_3.data[i][j] + bmats.A_29_4.data[i][j] - 16*bmats.A_30_3.data[i][j] + bmats.A_30_4.data[i][j] - 16*bmats.A_31_3.data[i][j] + bmats.A_31_4.data[i][j] - 16*bmats.A_32_3.data[i][j] + bmats.A_32_4.data[i][j] + bmats.Ax1781.data[i][j] + bmats.Ax2143.data[i][j] + bmats.Ax2483.data[i][j] + bmats.Ax2765.data[i][j] + bmats.Ax3122.data[i][j] + bmats.Ax3351.data[i][j] + bmats.Ax3595.data[i][j] + bmats.Ax3807.data[i][j] + bmats.Ax4096.data[i][j] + bmats.Ax4236.data[i][j] + bmats.Ax4297.data[i][j] + bmats.Ax4300.data[i][j] + bmats.Ax4303.data[i][j] + bmats.Ax4306.data[i][j] + bmats.Ax4309.data[i][j] + bmats.Ax913.data[i][j];
        }
    }
    return 0;
}
