#include "fAx1352.h"

inline int fAx1352(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1352.data[i][j] = bmats.A_15_1.data[i][j] + bmats.A_15_10.data[i][j] + bmats.A_15_11.data[i][j] + bmats.A_15_4.data[i][j] + bmats.A_15_5.data[i][j] + bmats.A_15_6.data[i][j] + bmats.A_15_7.data[i][j] + bmats.A_15_8.data[i][j] + bmats.A_15_9.data[i][j];
        }
    }
    return 0;
}
