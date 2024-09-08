#include "fAx1934.h"

inline int fAx1934(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1934.data[i][j] = -16*bmats.A_17_29.data[i][j] + bmats.A_17_30.data[i][j] - 16*bmats.A_18_29.data[i][j] + bmats.A_18_30.data[i][j] - 16*bmats.A_19_29.data[i][j] + bmats.A_19_30.data[i][j] - 16*bmats.A_20_29.data[i][j] + bmats.A_20_30.data[i][j] - 16*bmats.A_21_29.data[i][j] + bmats.A_21_30.data[i][j] - 16*bmats.A_22_29.data[i][j] + bmats.A_22_30.data[i][j] - 16*bmats.A_23_29.data[i][j] + bmats.A_23_30.data[i][j] - 16*bmats.A_24_29.data[i][j] + bmats.A_24_30.data[i][j] - 16*bmats.A_25_29.data[i][j] + bmats.A_25_30.data[i][j] - 16*bmats.A_26_29.data[i][j] + bmats.A_26_30.data[i][j] - 16*bmats.A_27_29.data[i][j] + bmats.A_27_30.data[i][j] - 16*bmats.A_28_29.data[i][j] + bmats.A_28_30.data[i][j] - 17*bmats.A_29_29.data[i][j] - 16*bmats.A_30_29.data[i][j] + bmats.A_30_30.data[i][j] + bmats.Ax1076.data[i][j] + bmats.Ax1085.data[i][j] + bmats.Ax1088.data[i][j] + bmats.Ax1094.data[i][j] + bmats.Ax1097.data[i][j] + bmats.Ax1100.data[i][j] + bmats.Ax1103.data[i][j] + bmats.Ax1106.data[i][j] + bmats.Ax1109.data[i][j] + bmats.Ax1112.data[i][j] + bmats.Ax1115.data[i][j] + bmats.Ax1118.data[i][j] + bmats.Ax1130.data[i][j];
        }
    }
    return 0;
}
