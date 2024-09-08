#include "fAx1106.h"

inline int fAx1106(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1106.data[i][j] = bmats.A_16_1.data[i][j] + bmats.A_16_10.data[i][j] + bmats.A_16_11.data[i][j] + bmats.A_16_4.data[i][j] + bmats.A_16_5.data[i][j] + bmats.A_16_6.data[i][j] + bmats.A_16_7.data[i][j] + bmats.A_16_8.data[i][j] + bmats.A_16_9.data[i][j];
        }
    }
    return 0;
}
