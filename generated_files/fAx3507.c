#include "fAx3507.h"

inline int fAx3507(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3507.data[i][j] = bmats.A_25_10.data[i][j] + bmats.A_25_11.data[i][j] + bmats.A_25_12.data[i][j] + bmats.A_25_13.data[i][j] + bmats.A_25_14.data[i][j] + bmats.A_25_15.data[i][j] + bmats.A_25_16.data[i][j] + bmats.A_25_3.data[i][j] + bmats.A_25_4.data[i][j] + bmats.A_25_5.data[i][j] + bmats.A_25_6.data[i][j] + bmats.A_25_7.data[i][j] + bmats.A_25_8.data[i][j] + bmats.A_25_9.data[i][j];
        }
    }
    return 0;
}