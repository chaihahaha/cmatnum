#include "fAx3151.h"

inline int fAx3151(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3151.data[i][j] = -11*bmats.A_12_8.data[i][j] + bmats.A_12_9.data[i][j] - 11*bmats.A_13_8.data[i][j] + bmats.A_13_9.data[i][j] - 11*bmats.A_14_8.data[i][j] + bmats.A_14_9.data[i][j] - 11*bmats.A_15_8.data[i][j] + bmats.A_15_9.data[i][j] - 11*bmats.A_16_8.data[i][j] + bmats.A_16_9.data[i][j] - 11*bmats.A_17_8.data[i][j] + bmats.A_17_9.data[i][j] - 11*bmats.A_18_8.data[i][j] + bmats.A_18_9.data[i][j] - 11*bmats.A_19_8.data[i][j] + bmats.A_19_9.data[i][j] - 11*bmats.A_20_8.data[i][j] + bmats.A_20_9.data[i][j] - 11*bmats.A_21_8.data[i][j] + bmats.A_21_9.data[i][j] - 11*bmats.A_22_8.data[i][j] + bmats.A_22_9.data[i][j] + bmats.Ax1020.data[i][j] + bmats.Ax1276.data[i][j] + bmats.Ax1465.data[i][j] + bmats.Ax1670.data[i][j] + bmats.Ax1848.data[i][j] + bmats.Ax1874.data[i][j] + bmats.Ax2063.data[i][j] + bmats.Ax2116.data[i][j] + bmats.Ax2181.data[i][j] + bmats.Ax2242.data[i][j] + bmats.Ax327.data[i][j];
        }
    }
    return 0;
}
