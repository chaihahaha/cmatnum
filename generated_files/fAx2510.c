#include "fAx2510.h"

inline int fAx2510(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2510.data[i][j] = 11*bmats.A_10_1.data[i][j] - bmats.A_10_10.data[i][j] - bmats.A_10_11.data[i][j] - bmats.A_10_2.data[i][j] - bmats.A_10_3.data[i][j] - bmats.A_10_4.data[i][j] - bmats.A_10_5.data[i][j] - bmats.A_10_6.data[i][j] - bmats.A_10_7.data[i][j] - bmats.A_10_8.data[i][j] - bmats.A_10_9.data[i][j];
        }
    }
    return 0;
}
