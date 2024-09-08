#include "fAx2974.h"

inline int fAx2974(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2974.data[i][j] = -17*bmats.A_10_10.data[i][j] - 16*bmats.A_12_10.data[i][j] + bmats.A_12_9.data[i][j] - 16*bmats.A_13_10.data[i][j] + bmats.A_13_9.data[i][j] - 16*bmats.A_14_10.data[i][j] + bmats.A_14_9.data[i][j] - 16*bmats.A_15_10.data[i][j] + bmats.A_15_9.data[i][j] - 16*bmats.A_1_10.data[i][j] + bmats.A_1_9.data[i][j] - 16*bmats.A_2_10.data[i][j] + bmats.A_2_9.data[i][j] - 16*bmats.A_3_10.data[i][j] + bmats.A_3_9.data[i][j] - 16*bmats.A_4_10.data[i][j] + bmats.A_4_9.data[i][j] - 16*bmats.A_5_10.data[i][j] + bmats.A_5_9.data[i][j] - 16*bmats.A_6_10.data[i][j] + bmats.A_6_9.data[i][j] - 16*bmats.A_7_10.data[i][j] + bmats.A_7_9.data[i][j] - 16*bmats.A_8_10.data[i][j] + bmats.A_8_9.data[i][j] - 16*bmats.A_9_10.data[i][j] + bmats.A_9_9.data[i][j] + bmats.Ax1189.data[i][j] + bmats.Ax2053.data[i][j] + bmats.Ax2390.data[i][j] + bmats.Ax2913.data[i][j] + bmats.Ax2920.data[i][j] + bmats.Ax2923.data[i][j] + bmats.Ax2926.data[i][j] + bmats.Ax2929.data[i][j] + bmats.Ax2932.data[i][j] + bmats.Ax2935.data[i][j] + bmats.Ax2938.data[i][j] + bmats.Ax2941.data[i][j] + bmats.Ax2944.data[i][j];
        }
    }
    return 0;
}
