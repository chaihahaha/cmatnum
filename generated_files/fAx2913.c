#include "fAx2913.h"

inline int fAx2913(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2913.data[i][j] = bmats.A_15_1.data[i][j] + bmats.A_15_11.data[i][j] + bmats.A_15_12.data[i][j] + bmats.A_15_13.data[i][j] + bmats.A_15_14.data[i][j] + bmats.A_15_15.data[i][j] + bmats.A_15_16.data[i][j] + bmats.A_15_2.data[i][j] + bmats.A_15_3.data[i][j] + bmats.A_15_4.data[i][j] + bmats.A_15_5.data[i][j] + bmats.A_15_6.data[i][j] + bmats.A_15_7.data[i][j] + bmats.A_15_8.data[i][j];
        }
    }
    return 0;
}
