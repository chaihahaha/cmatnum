#include "fAx2801.h"

inline int fAx2801(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2801.data[i][j] = bmats.A_32_1.data[i][j] + bmats.A_32_11.data[i][j] + bmats.A_32_12.data[i][j] + bmats.A_32_13.data[i][j] + bmats.A_32_14.data[i][j] + bmats.A_32_15.data[i][j] + bmats.A_32_16.data[i][j] + bmats.A_32_2.data[i][j] + bmats.A_32_3.data[i][j] + bmats.A_32_4.data[i][j] + bmats.A_32_5.data[i][j] + bmats.A_32_6.data[i][j] + bmats.A_32_7.data[i][j] + bmats.A_32_8.data[i][j];
        }
    }
    return 0;
}
