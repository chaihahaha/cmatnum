#include "fAx1563.h"

inline int fAx1563(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1563.data[i][j] = bmats.A_10_2.data[i][j] - 11*bmats.A_10_3.data[i][j] + bmats.A_11_2.data[i][j] - 11*bmats.A_11_3.data[i][j] + bmats.A_1_2.data[i][j] - 11*bmats.A_1_3.data[i][j] + bmats.A_2_2.data[i][j] - 11*bmats.A_2_3.data[i][j] - 12*bmats.A_3_3.data[i][j] + bmats.A_6_2.data[i][j] - 11*bmats.A_6_3.data[i][j] + bmats.A_7_2.data[i][j] - 11*bmats.A_7_3.data[i][j] + bmats.A_8_2.data[i][j] - 11*bmats.A_8_3.data[i][j] + bmats.A_9_2.data[i][j] - 11*bmats.A_9_3.data[i][j] + bmats.Ax1429.data[i][j] + bmats.Ax1433.data[i][j] + bmats.Ax1436.data[i][j] + bmats.Ax1439.data[i][j] + bmats.Ax1442.data[i][j] + bmats.Ax1471.data[i][j] + bmats.Ax245.data[i][j] + bmats.Ax720.data[i][j];
        }
    }
    return 0;
}
