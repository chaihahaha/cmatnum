#include "fAx1755.h"

inline int fAx1755(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1755.data[i][j] = -11*bmats.A_22_1.data[i][j] + bmats.A_22_10.data[i][j] + bmats.A_22_11.data[i][j] + bmats.A_22_2.data[i][j] + bmats.A_22_3.data[i][j] + bmats.A_22_4.data[i][j] + bmats.A_22_5.data[i][j] + bmats.A_22_6.data[i][j] + bmats.A_22_7.data[i][j] + bmats.A_22_8.data[i][j] + bmats.A_22_9.data[i][j];
        }
    }
    return 0;
}
