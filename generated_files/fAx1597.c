#include "fAx1597.h"

inline int fAx1597(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1597.data[i][j] = -11*bmats.A_12_2.data[i][j] + bmats.A_12_3.data[i][j] - 11*bmats.A_13_2.data[i][j] + bmats.A_13_3.data[i][j] - 11*bmats.A_14_2.data[i][j] + bmats.A_14_3.data[i][j] - 11*bmats.A_15_2.data[i][j] + bmats.A_15_3.data[i][j] - 11*bmats.A_16_2.data[i][j] + bmats.A_16_3.data[i][j] - 11*bmats.A_17_2.data[i][j] + bmats.A_17_3.data[i][j] - 11*bmats.A_18_2.data[i][j] + bmats.A_18_3.data[i][j] - 11*bmats.A_19_2.data[i][j] + bmats.A_19_3.data[i][j] - 11*bmats.A_20_2.data[i][j] + bmats.A_20_3.data[i][j] - 11*bmats.A_21_2.data[i][j] + bmats.A_21_3.data[i][j] - 11*bmats.A_22_2.data[i][j] + bmats.A_22_3.data[i][j] + bmats.Ax1106.data[i][j] + bmats.Ax1335.data[i][j] + bmats.Ax1338.data[i][j] + bmats.Ax1341.data[i][j] + bmats.Ax1344.data[i][j] + bmats.Ax1347.data[i][j] + bmats.Ax1350.data[i][j] + bmats.Ax1352.data[i][j] + bmats.Ax1355.data[i][j] + bmats.Ax217.data[i][j] + bmats.Ax711.data[i][j];
        }
    }
    return 0;
}
