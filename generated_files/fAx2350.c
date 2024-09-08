#include "fAx2350.h"

inline int fAx2350(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2350.data[i][j] = -bmats.A_7_1.data[i][j] - bmats.A_7_10.data[i][j] - bmats.A_7_11.data[i][j] - bmats.A_7_2.data[i][j] - bmats.A_7_3.data[i][j] - bmats.A_7_6.data[i][j] - bmats.A_7_8.data[i][j] - bmats.A_7_9.data[i][j];
        }
    }
    return 0;
}
