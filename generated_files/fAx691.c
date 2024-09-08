#include "fAx691.h"

inline int fAx691(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax691.data[i][j] = bmats.A_29_1.data[i][j] + bmats.A_29_10.data[i][j] + bmats.A_29_11.data[i][j] + bmats.A_29_12.data[i][j] + bmats.A_29_13.data[i][j] + bmats.A_29_14.data[i][j] + bmats.A_29_2.data[i][j] + bmats.A_29_3.data[i][j] + bmats.A_29_4.data[i][j] + bmats.A_29_5.data[i][j] + bmats.A_29_6.data[i][j] + bmats.A_29_7.data[i][j] + bmats.A_29_8.data[i][j] + bmats.A_29_9.data[i][j];
        }
    }
    return 0;
}
