#include "fBx11916.h"

inline int fBx11916(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11916.data[i][j] = bmats.B_10_20.data[i][j] + bmats.B_11_20.data[i][j] + bmats.B_12_20.data[i][j] + bmats.B_13_20.data[i][j] + bmats.B_14_20.data[i][j] + bmats.B_5_20.data[i][j] + bmats.B_6_20.data[i][j] + bmats.B_7_20.data[i][j] + bmats.B_8_20.data[i][j];
        }
    }
    return 0;
}
