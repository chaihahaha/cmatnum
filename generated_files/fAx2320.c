#include "fAx2320.h"

inline int fAx2320(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2320.data[i][j] = bmats.A_10_27.data[i][j] - 16*bmats.A_10_28.data[i][j] + bmats.A_11_27.data[i][j] - 16*bmats.A_11_28.data[i][j] + bmats.A_12_27.data[i][j] - 16*bmats.A_12_28.data[i][j] + bmats.A_13_27.data[i][j] - 16*bmats.A_13_28.data[i][j] + bmats.A_14_27.data[i][j] - 16*bmats.A_14_28.data[i][j] + bmats.A_15_27.data[i][j] - 16*bmats.A_15_28.data[i][j] + bmats.A_16_27.data[i][j] - 16*bmats.A_16_28.data[i][j] + bmats.A_1_27.data[i][j] - 16*bmats.A_1_28.data[i][j] + bmats.A_2_27.data[i][j] - 16*bmats.A_2_28.data[i][j] + bmats.A_3_27.data[i][j] - 16*bmats.A_3_28.data[i][j] + bmats.A_4_27.data[i][j] - 16*bmats.A_4_28.data[i][j] + bmats.A_5_27.data[i][j] - 16*bmats.A_5_28.data[i][j] + bmats.A_6_27.data[i][j] - 16*bmats.A_6_28.data[i][j] + bmats.A_7_27.data[i][j] - 16*bmats.A_7_28.data[i][j] + bmats.A_8_27.data[i][j] - 16*bmats.A_8_28.data[i][j] + bmats.A_9_27.data[i][j] - 16*bmats.A_9_28.data[i][j] + bmats.Ax1229.data[i][j] + bmats.Ax1963.data[i][j] + bmats.Ax2279.data[i][j] + bmats.Ax2282.data[i][j] + bmats.Ax2285.data[i][j] + bmats.Ax2288.data[i][j] + bmats.Ax2291.data[i][j] + bmats.Ax2294.data[i][j] + bmats.Ax2297.data[i][j] + bmats.Ax2300.data[i][j] + bmats.Ax2303.data[i][j] + bmats.Ax2306.data[i][j] + bmats.Ax2309.data[i][j] + bmats.Ax2312.data[i][j] + bmats.Ax2315.data[i][j] + bmats.Ax2318.data[i][j];
        }
    }
    return 0;
}
