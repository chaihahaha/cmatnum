#include "fAx3157.h"

inline int fAx3157(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3157.data[i][j] = bmats.A_17_10.data[i][j] - 16*bmats.A_17_9.data[i][j] + bmats.A_18_10.data[i][j] - 16*bmats.A_18_9.data[i][j] + bmats.A_19_10.data[i][j] - 16*bmats.A_19_9.data[i][j] + bmats.A_20_10.data[i][j] - 16*bmats.A_20_9.data[i][j] + bmats.A_21_10.data[i][j] - 16*bmats.A_21_9.data[i][j] + bmats.A_22_10.data[i][j] - 16*bmats.A_22_9.data[i][j] + bmats.A_23_10.data[i][j] - 16*bmats.A_23_9.data[i][j] + bmats.A_24_10.data[i][j] - 16*bmats.A_24_9.data[i][j] + bmats.A_25_10.data[i][j] - 16*bmats.A_25_9.data[i][j] + bmats.A_26_10.data[i][j] - 16*bmats.A_26_9.data[i][j] + bmats.A_27_10.data[i][j] - 16*bmats.A_27_9.data[i][j] + bmats.A_28_10.data[i][j] - 16*bmats.A_28_9.data[i][j] + bmats.A_29_10.data[i][j] - 16*bmats.A_29_9.data[i][j] + bmats.A_30_10.data[i][j] - 16*bmats.A_30_9.data[i][j] + bmats.A_31_10.data[i][j] - 16*bmats.A_31_9.data[i][j] + bmats.A_32_10.data[i][j] - 16*bmats.A_32_9.data[i][j] + bmats.Ax1484.data[i][j] + bmats.Ax2044.data[i][j] + bmats.Ax2384.data[i][j] + bmats.Ax2671.data[i][j] + bmats.Ax2801.data[i][j] + bmats.Ax2804.data[i][j] + bmats.Ax2807.data[i][j] + bmats.Ax2810.data[i][j] + bmats.Ax2813.data[i][j] + bmats.Ax2816.data[i][j] + bmats.Ax2819.data[i][j] + bmats.Ax2822.data[i][j] + bmats.Ax2825.data[i][j] + bmats.Ax2828.data[i][j] + bmats.Ax2831.data[i][j] + bmats.Ax2834.data[i][j];
        }
    }
    return 0;
}
