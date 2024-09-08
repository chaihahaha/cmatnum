#include "fAx1899.h"

inline int fAx1899(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1899.data[i][j] = -16*bmats.A_10_29.data[i][j] + bmats.A_10_30.data[i][j] - 16*bmats.A_11_29.data[i][j] + bmats.A_11_30.data[i][j] - 16*bmats.A_12_29.data[i][j] + bmats.A_12_30.data[i][j] - 16*bmats.A_13_29.data[i][j] + bmats.A_13_30.data[i][j] - 16*bmats.A_14_29.data[i][j] + bmats.A_14_30.data[i][j] - 16*bmats.A_15_29.data[i][j] + bmats.A_15_30.data[i][j] - 16*bmats.A_16_29.data[i][j] + bmats.A_16_30.data[i][j] - 16*bmats.A_1_29.data[i][j] + bmats.A_1_30.data[i][j] - 16*bmats.A_2_29.data[i][j] + bmats.A_2_30.data[i][j] - 16*bmats.A_3_29.data[i][j] + bmats.A_3_30.data[i][j] - 16*bmats.A_4_29.data[i][j] + bmats.A_4_30.data[i][j] - 16*bmats.A_5_29.data[i][j] + bmats.A_5_30.data[i][j] - 16*bmats.A_6_29.data[i][j] + bmats.A_6_30.data[i][j] - 16*bmats.A_7_29.data[i][j] + bmats.A_7_30.data[i][j] - 16*bmats.A_8_29.data[i][j] + bmats.A_8_30.data[i][j] - 16*bmats.A_9_29.data[i][j] + bmats.A_9_30.data[i][j] + bmats.Ax396.data[i][j] + bmats.Ax399.data[i][j] + bmats.Ax402.data[i][j] + bmats.Ax405.data[i][j] + bmats.Ax408.data[i][j] + bmats.Ax411.data[i][j] + bmats.Ax414.data[i][j] + bmats.Ax417.data[i][j] + bmats.Ax420.data[i][j] + bmats.Ax423.data[i][j] + bmats.Ax426.data[i][j] + bmats.Ax429.data[i][j] + bmats.Ax432.data[i][j] + bmats.Ax435.data[i][j] + bmats.Ax438.data[i][j] + bmats.Ax441.data[i][j];
        }
    }
    return 0;
}
