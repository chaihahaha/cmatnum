#include "fAx682.h"

inline int fAx682(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax682.data[i][j] = bmats.A_32_1.data[i][j] + bmats.A_32_10.data[i][j] + bmats.A_32_11.data[i][j] + bmats.A_32_12.data[i][j] + bmats.A_32_13.data[i][j] + bmats.A_32_14.data[i][j] + bmats.A_32_2.data[i][j] + bmats.A_32_3.data[i][j] + bmats.A_32_4.data[i][j] + bmats.A_32_5.data[i][j] + bmats.A_32_6.data[i][j] + bmats.A_32_7.data[i][j] + bmats.A_32_8.data[i][j] + bmats.A_32_9.data[i][j];
        }
    }
    return 0;
}