#include "fAx1383.h"

inline int fAx1383(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1383.data[i][j] = bmats.A_10_13.data[i][j] - 11*bmats.A_10_14.data[i][j] + bmats.A_11_13.data[i][j] - 11*bmats.A_11_14.data[i][j] + bmats.A_1_13.data[i][j] - 11*bmats.A_1_14.data[i][j] + bmats.A_2_13.data[i][j] - 11*bmats.A_2_14.data[i][j] + bmats.A_3_13.data[i][j] - 11*bmats.A_3_14.data[i][j] + bmats.A_4_13.data[i][j] - 11*bmats.A_4_14.data[i][j] + bmats.A_5_13.data[i][j] - 11*bmats.A_5_14.data[i][j] + bmats.A_6_13.data[i][j] - 11*bmats.A_6_14.data[i][j] + bmats.A_7_13.data[i][j] - 11*bmats.A_7_14.data[i][j] + bmats.A_8_13.data[i][j] - 11*bmats.A_8_14.data[i][j] + bmats.A_9_13.data[i][j] - 11*bmats.A_9_14.data[i][j] + bmats.Ax1109.data[i][j] + bmats.Ax1360.data[i][j] + bmats.Ax1363.data[i][j] + bmats.Ax1366.data[i][j] + bmats.Ax1369.data[i][j] + bmats.Ax1372.data[i][j] + bmats.Ax1375.data[i][j] + bmats.Ax1378.data[i][j] + bmats.Ax1381.data[i][j] + bmats.Ax223.data[i][j] + bmats.Ax714.data[i][j];
        }
    }
    return 0;
}
