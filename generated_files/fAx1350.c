#include "fAx1350.h"

inline int fAx1350(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1350.data[i][j] = bmats.A_14_1.data[i][j] + bmats.A_14_10.data[i][j] + bmats.A_14_11.data[i][j] + bmats.A_14_4.data[i][j] + bmats.A_14_5.data[i][j] + bmats.A_14_6.data[i][j] + bmats.A_14_7.data[i][j] + bmats.A_14_8.data[i][j] + bmats.A_14_9.data[i][j];
        }
    }
    return 0;
}
