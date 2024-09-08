#include "fAx4102.h"

inline int fAx4102(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4102.data[i][j] = bmats.A_6_1.data[i][j] + bmats.A_6_10.data[i][j] + bmats.A_6_11.data[i][j] + bmats.A_6_12.data[i][j] + bmats.A_6_13.data[i][j] + bmats.A_6_14.data[i][j] + bmats.A_6_15.data[i][j] + bmats.A_6_16.data[i][j] + bmats.A_6_2.data[i][j] + bmats.A_6_5.data[i][j] + bmats.A_6_6.data[i][j] + bmats.A_6_7.data[i][j] + bmats.A_6_8.data[i][j] + bmats.A_6_9.data[i][j];
        }
    }
    return 0;
}
