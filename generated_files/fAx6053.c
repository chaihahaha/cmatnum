#include "fAx6053.h"

inline int fAx6053(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6053.data[i][j] = -bmats.A_21_20.data[i][j] - bmats.A_21_21.data[i][j] - bmats.A_21_22.data[i][j] - bmats.A_21_23.data[i][j] - bmats.A_21_24.data[i][j] - bmats.A_21_26.data[i][j] - bmats.A_21_27.data[i][j] - bmats.A_21_28.data[i][j] - bmats.A_21_29.data[i][j] - bmats.A_21_30.data[i][j] - bmats.A_21_31.data[i][j] - bmats.A_21_32.data[i][j];
        }
    }
    return 0;
}