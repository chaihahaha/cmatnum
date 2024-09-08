#include "fAx5101.h"

inline int fAx5101(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax5101.data[i][j] = -bmats.A_3_1.data[i][j] - bmats.A_3_10.data[i][j] - bmats.A_3_11.data[i][j] - bmats.A_3_12.data[i][j] - bmats.A_3_15.data[i][j] - bmats.A_3_16.data[i][j] - bmats.A_3_2.data[i][j] - bmats.A_3_3.data[i][j] - bmats.A_3_4.data[i][j] - bmats.A_3_5.data[i][j] - bmats.A_3_6.data[i][j] - bmats.A_3_7.data[i][j] - bmats.A_3_8.data[i][j] - bmats.A_3_9.data[i][j];
        }
    }
    return 0;
}
