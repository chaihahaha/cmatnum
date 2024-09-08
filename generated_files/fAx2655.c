#include "fAx2655.h"

inline int fAx2655(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2655.data[i][j] = -16*bmats.A_10_11.data[i][j] + bmats.A_10_12.data[i][j] - 17*bmats.A_11_11.data[i][j] - 16*bmats.A_12_11.data[i][j] + bmats.A_12_12.data[i][j] - 16*bmats.A_13_11.data[i][j] + bmats.A_13_12.data[i][j] - 16*bmats.A_16_11.data[i][j] + bmats.A_16_12.data[i][j] - 16*bmats.A_1_11.data[i][j] + bmats.A_1_12.data[i][j] - 16*bmats.A_2_11.data[i][j] + bmats.A_2_12.data[i][j] - 16*bmats.A_3_11.data[i][j] + bmats.A_3_12.data[i][j] - 16*bmats.A_4_11.data[i][j] + bmats.A_4_12.data[i][j] - 16*bmats.A_5_11.data[i][j] + bmats.A_5_12.data[i][j] - 16*bmats.A_6_11.data[i][j] + bmats.A_6_12.data[i][j] - 16*bmats.A_7_11.data[i][j] + bmats.A_7_12.data[i][j] - 16*bmats.A_8_11.data[i][j] + bmats.A_8_12.data[i][j] - 16*bmats.A_9_11.data[i][j] + bmats.A_9_12.data[i][j] + bmats.Ax1969.data[i][j] + bmats.Ax2175.data[i][j] + bmats.Ax2178.data[i][j] + bmats.Ax2184.data[i][j] + bmats.Ax2187.data[i][j] + bmats.Ax2193.data[i][j] + bmats.Ax2196.data[i][j] + bmats.Ax2199.data[i][j] + bmats.Ax2202.data[i][j] + bmats.Ax2205.data[i][j] + bmats.Ax2208.data[i][j] + bmats.Ax2211.data[i][j] + bmats.Ax2214.data[i][j];
        }
    }
    return 0;
}
