#include "fAx758.h"

inline int fAx758(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax758.data[i][j] = bmats.A_6_1.data[i][j] + bmats.A_6_10.data[i][j] + bmats.A_6_11.data[i][j] + bmats.A_6_2.data[i][j] + bmats.A_6_3.data[i][j] + bmats.A_6_6.data[i][j] + bmats.A_6_7.data[i][j] + bmats.A_6_8.data[i][j] + bmats.A_6_9.data[i][j];
        }
    }
    return 0;
}
