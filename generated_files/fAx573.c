#include "fAx573.h"

inline int fAx573(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax573.data[i][j] = bmats.A_7_1.data[i][j] + bmats.A_7_10.data[i][j] + bmats.A_7_11.data[i][j] + bmats.A_7_12.data[i][j] + bmats.A_7_13.data[i][j] + bmats.A_7_14.data[i][j] + bmats.A_7_2.data[i][j] + bmats.A_7_3.data[i][j] + bmats.A_7_4.data[i][j] + bmats.A_7_5.data[i][j] + bmats.A_7_6.data[i][j] + bmats.A_7_7.data[i][j] + bmats.A_7_8.data[i][j] + bmats.A_7_9.data[i][j];
        }
    }
    return 0;
}