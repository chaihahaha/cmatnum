#include "fAx846.h"

inline int fAx846(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax846.data[i][j] = -bmats.A_31_10.data[i][j] - bmats.A_31_11.data[i][j] - bmats.A_31_12.data[i][j] - bmats.A_31_13.data[i][j] - bmats.A_31_14.data[i][j] - bmats.A_31_15.data[i][j] - bmats.A_31_16.data[i][j] - bmats.A_31_3.data[i][j] - bmats.A_31_4.data[i][j] - bmats.A_31_5.data[i][j] - bmats.A_31_6.data[i][j] - bmats.A_31_7.data[i][j] - bmats.A_31_8.data[i][j] - bmats.A_31_9.data[i][j] + bmats.Ax791.data[i][j];
        }
    }
    return 0;
}