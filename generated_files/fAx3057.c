#include "fAx3057.h"

inline int fAx3057(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3057.data[i][j] = bmats.A_10_1.data[i][j] + bmats.A_10_10.data[i][j] + bmats.A_10_11.data[i][j] + bmats.A_10_12.data[i][j] + bmats.A_10_13.data[i][j] + bmats.A_10_14.data[i][j] + bmats.A_10_15.data[i][j] + bmats.A_10_16.data[i][j] + bmats.A_10_2.data[i][j] + bmats.A_10_5.data[i][j] + bmats.A_10_6.data[i][j] + bmats.A_10_7.data[i][j] + bmats.A_10_8.data[i][j] + bmats.A_10_9.data[i][j];
        }
    }
    return 0;
}
