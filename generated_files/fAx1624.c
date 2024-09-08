#include "fAx1624.h"

inline int fAx1624(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1624.data[i][j] = -11*bmats.A_12_13.data[i][j] + bmats.A_12_14.data[i][j] - 12*bmats.A_13_13.data[i][j] - 11*bmats.A_14_13.data[i][j] + bmats.A_14_14.data[i][j] - 11*bmats.A_15_13.data[i][j] + bmats.A_15_14.data[i][j] - 11*bmats.A_16_13.data[i][j] + bmats.A_16_14.data[i][j] - 11*bmats.A_17_13.data[i][j] + bmats.A_17_14.data[i][j] - 11*bmats.A_18_13.data[i][j] + bmats.A_18_14.data[i][j] - 11*bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] - 11*bmats.A_21_13.data[i][j] + bmats.A_21_14.data[i][j] + bmats.Ax1112.data[i][j] + bmats.Ax1408.data[i][j] + bmats.Ax1448.data[i][j] + bmats.Ax1461.data[i][j] + bmats.Ax1479.data[i][j] + bmats.Ax1482.data[i][j] + bmats.Ax229.data[i][j] + bmats.Ax717.data[i][j];
        }
    }
    return 0;
}
