#include "fAx2598.h"

inline int fAx2598(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2598.data[i][j] = -16*bmats.A_17_11.data[i][j] + bmats.A_17_12.data[i][j] - 16*bmats.A_18_11.data[i][j] + bmats.A_18_12.data[i][j] - 16*bmats.A_19_11.data[i][j] + bmats.A_19_12.data[i][j] - 16*bmats.A_20_11.data[i][j] + bmats.A_20_12.data[i][j] - 16*bmats.A_21_11.data[i][j] + bmats.A_21_12.data[i][j] - 16*bmats.A_22_11.data[i][j] + bmats.A_22_12.data[i][j] - 16*bmats.A_23_11.data[i][j] + bmats.A_23_12.data[i][j] - 16*bmats.A_24_11.data[i][j] + bmats.A_24_12.data[i][j] - 16*bmats.A_25_11.data[i][j] + bmats.A_25_12.data[i][j] - 16*bmats.A_26_11.data[i][j] + bmats.A_26_12.data[i][j] - 16*bmats.A_27_11.data[i][j] + bmats.A_27_12.data[i][j] - 16*bmats.A_28_11.data[i][j] + bmats.A_28_12.data[i][j] - 16*bmats.A_29_11.data[i][j] + bmats.A_29_12.data[i][j] - 16*bmats.A_30_11.data[i][j] + bmats.A_30_12.data[i][j] - 16*bmats.A_31_11.data[i][j] + bmats.A_31_12.data[i][j] - 16*bmats.A_32_11.data[i][j] + bmats.A_32_12.data[i][j] + bmats.Ax1224.data[i][j] + bmats.Ax1981.data[i][j] + bmats.Ax2236.data[i][j] + bmats.Ax2239.data[i][j] + bmats.Ax2242.data[i][j] + bmats.Ax2245.data[i][j] + bmats.Ax2248.data[i][j] + bmats.Ax2251.data[i][j] + bmats.Ax2254.data[i][j] + bmats.Ax2257.data[i][j] + bmats.Ax2260.data[i][j] + bmats.Ax2263.data[i][j] + bmats.Ax2266.data[i][j] + bmats.Ax2269.data[i][j] + bmats.Ax2272.data[i][j] + bmats.Ax2275.data[i][j];
        }
    }
    return 0;
}
