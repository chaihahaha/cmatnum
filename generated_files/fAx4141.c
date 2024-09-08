#include "fAx4141.h"

inline int fAx4141(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4141.data[i][j] = -16*bmats.A_17_5.data[i][j] + bmats.A_17_6.data[i][j] - 16*bmats.A_18_5.data[i][j] + bmats.A_18_6.data[i][j] - 16*bmats.A_19_5.data[i][j] + bmats.A_19_6.data[i][j] - 16*bmats.A_20_5.data[i][j] + bmats.A_20_6.data[i][j] - 16*bmats.A_21_5.data[i][j] + bmats.A_21_6.data[i][j] - 16*bmats.A_22_5.data[i][j] + bmats.A_22_6.data[i][j] - 16*bmats.A_23_5.data[i][j] + bmats.A_23_6.data[i][j] - 16*bmats.A_24_5.data[i][j] + bmats.A_24_6.data[i][j] - 16*bmats.A_25_5.data[i][j] + bmats.A_25_6.data[i][j] - 16*bmats.A_26_5.data[i][j] + bmats.A_26_6.data[i][j] - 16*bmats.A_27_5.data[i][j] + bmats.A_27_6.data[i][j] - 16*bmats.A_28_5.data[i][j] + bmats.A_28_6.data[i][j] - 16*bmats.A_29_5.data[i][j] + bmats.A_29_6.data[i][j] - 16*bmats.A_30_5.data[i][j] + bmats.A_30_6.data[i][j] - 16*bmats.A_31_5.data[i][j] + bmats.A_31_6.data[i][j] - 16*bmats.A_32_5.data[i][j] + bmats.A_32_6.data[i][j] + bmats.Ax1625.data[i][j] + bmats.Ax2077.data[i][j] + bmats.Ax2439.data[i][j] + bmats.Ax2780.data[i][j] + bmats.Ax3068.data[i][j] + bmats.Ax3309.data[i][j] + bmats.Ax3535.data[i][j] + bmats.Ax3822.data[i][j] + bmats.Ax3964.data[i][j] + bmats.Ax3967.data[i][j] + bmats.Ax3970.data[i][j] + bmats.Ax3973.data[i][j] + bmats.Ax3976.data[i][j] + bmats.Ax3979.data[i][j] + bmats.Ax3982.data[i][j] + bmats.Ax3985.data[i][j];
        }
    }
    return 0;
}
