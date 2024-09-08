#include "fAx1463.h"

inline int fAx1463(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1463.data[i][j] = bmats.A_12_13.data[i][j] - 11*bmats.A_12_14.data[i][j] + bmats.A_13_13.data[i][j] - 11*bmats.A_13_14.data[i][j] - 12*bmats.A_14_14.data[i][j] + bmats.A_15_13.data[i][j] - 11*bmats.A_15_14.data[i][j] + bmats.A_16_13.data[i][j] - 11*bmats.A_16_14.data[i][j] + bmats.A_17_13.data[i][j] - 11*bmats.A_17_14.data[i][j] + bmats.A_18_13.data[i][j] - 11*bmats.A_18_14.data[i][j] + bmats.A_19_13.data[i][j] - 11*bmats.A_19_14.data[i][j] + bmats.A_22_13.data[i][j] - 11*bmats.A_22_14.data[i][j] + bmats.Ax1112.data[i][j] + bmats.Ax1408.data[i][j] + bmats.Ax1452.data[i][j] + bmats.Ax1455.data[i][j] + bmats.Ax1458.data[i][j] + bmats.Ax1461.data[i][j] + bmats.Ax229.data[i][j] + bmats.Ax717.data[i][j];
        }
    }
    return 0;
}
