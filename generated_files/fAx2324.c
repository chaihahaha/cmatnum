#include "fAx2324.h"

inline int fAx2324(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2324.data[i][j] = bmats.A_10_11.data[i][j] - 16*bmats.A_10_12.data[i][j] + bmats.A_11_11.data[i][j] - 16*bmats.A_11_12.data[i][j] - 17*bmats.A_12_12.data[i][j] + bmats.A_14_11.data[i][j] - 16*bmats.A_14_12.data[i][j] + bmats.A_15_11.data[i][j] - 16*bmats.A_15_12.data[i][j] + bmats.A_1_11.data[i][j] - 16*bmats.A_1_12.data[i][j] + bmats.A_2_11.data[i][j] - 16*bmats.A_2_12.data[i][j] + bmats.A_3_11.data[i][j] - 16*bmats.A_3_12.data[i][j] + bmats.A_4_11.data[i][j] - 16*bmats.A_4_12.data[i][j] + bmats.A_5_11.data[i][j] - 16*bmats.A_5_12.data[i][j] + bmats.A_6_11.data[i][j] - 16*bmats.A_6_12.data[i][j] + bmats.A_7_11.data[i][j] - 16*bmats.A_7_12.data[i][j] + bmats.A_8_11.data[i][j] - 16*bmats.A_8_12.data[i][j] + bmats.A_9_11.data[i][j] - 16*bmats.A_9_12.data[i][j] + bmats.Ax1255.data[i][j] + bmats.Ax2178.data[i][j] + bmats.Ax2181.data[i][j] + bmats.Ax2187.data[i][j] + bmats.Ax2190.data[i][j] + bmats.Ax2193.data[i][j] + bmats.Ax2196.data[i][j] + bmats.Ax2199.data[i][j] + bmats.Ax2202.data[i][j] + bmats.Ax2205.data[i][j] + bmats.Ax2208.data[i][j] + bmats.Ax2211.data[i][j] + bmats.Ax2214.data[i][j];
        }
    }
    return 0;
}