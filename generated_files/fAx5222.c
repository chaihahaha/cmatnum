#include "fAx5222.h"

inline int fAx5222(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax5222.data[i][j] = -bmats.A_4_1.data[i][j] - bmats.A_4_10.data[i][j] - bmats.A_4_13.data[i][j] - bmats.A_4_14.data[i][j] - bmats.A_4_15.data[i][j] - bmats.A_4_16.data[i][j] - bmats.A_4_2.data[i][j] - bmats.A_4_3.data[i][j] - bmats.A_4_4.data[i][j] - bmats.A_4_5.data[i][j] - bmats.A_4_6.data[i][j] - bmats.A_4_7.data[i][j] - bmats.A_4_8.data[i][j] - bmats.A_4_9.data[i][j];
        }
    }
    return 0;
}