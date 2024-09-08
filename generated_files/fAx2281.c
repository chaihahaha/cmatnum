#include "fAx2281.h"

inline int fAx2281(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2281.data[i][j] = -bmats.A_2_1.data[i][j] - bmats.A_2_10.data[i][j] - bmats.A_2_11.data[i][j] - bmats.A_2_2.data[i][j] - bmats.A_2_3.data[i][j] - bmats.A_2_4.data[i][j] - bmats.A_2_5.data[i][j] - bmats.A_2_8.data[i][j] - bmats.A_2_9.data[i][j];
        }
    }
    return 0;
}
