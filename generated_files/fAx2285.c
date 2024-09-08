#include "fAx2285.h"

inline int fAx2285(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2285.data[i][j] = -bmats.A_3_1.data[i][j] - bmats.A_3_10.data[i][j] - bmats.A_3_11.data[i][j] - bmats.A_3_2.data[i][j] - bmats.A_3_3.data[i][j] - bmats.A_3_4.data[i][j] - bmats.A_3_5.data[i][j] - bmats.A_3_8.data[i][j] - bmats.A_3_9.data[i][j];
        }
    }
    return 0;
}
