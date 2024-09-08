#include "fAx1740.h"

inline int fAx1740(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1740.data[i][j] = bmats.A_10_13.data[i][j] - 16*bmats.A_10_14.data[i][j] + bmats.A_11_13.data[i][j] - 16*bmats.A_11_14.data[i][j] + bmats.A_12_13.data[i][j] - 16*bmats.A_12_14.data[i][j] + bmats.A_13_13.data[i][j] - 16*bmats.A_13_14.data[i][j] - 17*bmats.A_14_14.data[i][j] + bmats.A_15_13.data[i][j] - 16*bmats.A_15_14.data[i][j] + bmats.A_16_13.data[i][j] - 16*bmats.A_16_14.data[i][j] + bmats.A_1_13.data[i][j] - 16*bmats.A_1_14.data[i][j] + bmats.A_3_13.data[i][j] - 16*bmats.A_3_14.data[i][j] + bmats.A_4_13.data[i][j] - 16*bmats.A_4_14.data[i][j] + bmats.A_5_13.data[i][j] - 16*bmats.A_5_14.data[i][j] + bmats.A_6_13.data[i][j] - 16*bmats.A_6_14.data[i][j] + bmats.A_8_13.data[i][j] - 16*bmats.A_8_14.data[i][j] + bmats.A_9_13.data[i][j] - 16*bmats.A_9_14.data[i][j] + bmats.Ax1012.data[i][j] + bmats.Ax1015.data[i][j] + bmats.Ax1018.data[i][j] + bmats.Ax1021.data[i][j] + bmats.Ax1024.data[i][j] + bmats.Ax1027.data[i][j] + bmats.Ax1033.data[i][j] + bmats.Ax1036.data[i][j] + bmats.Ax1039.data[i][j] + bmats.Ax1042.data[i][j] + bmats.Ax1045.data[i][j] + bmats.Ax1048.data[i][j] + bmats.Ax1051.data[i][j];
        }
    }
    return 0;
}
