#include "fAx3215.h"

inline int fAx3215(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3215.data[i][j] = -bmats.A_21_1.data[i][j] - bmats.A_21_10.data[i][j] - bmats.A_21_11.data[i][j] - bmats.A_21_2.data[i][j] - bmats.A_21_3.data[i][j] - bmats.A_21_4.data[i][j] - bmats.A_21_5.data[i][j] - bmats.A_21_6.data[i][j] - bmats.A_21_7.data[i][j] + bmats.Ax3086.data[i][j];
        }
    }
    return 0;
}
