#include "fAx4644.h"

inline int fAx4644(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4644.data[i][j] = bmats.A_16_10.data[i][j] + bmats.A_16_11.data[i][j] + bmats.A_16_12.data[i][j] + bmats.A_16_13.data[i][j] + bmats.A_16_14.data[i][j] + bmats.A_16_15.data[i][j] + bmats.A_16_16.data[i][j] + bmats.A_16_3.data[i][j] + bmats.A_16_4.data[i][j] + bmats.A_16_5.data[i][j] + bmats.A_16_6.data[i][j] + bmats.A_16_7.data[i][j] + bmats.A_16_8.data[i][j] + bmats.A_16_9.data[i][j];
        }
    }
    return 0;
}
