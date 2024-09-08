#include "fAx2008.h"

inline int fAx2008(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2008.data[i][j] = -bmats.A_9_1.data[i][j] - bmats.A_9_2.data[i][j] - bmats.A_9_3.data[i][j] - bmats.A_9_4.data[i][j] - bmats.A_9_5.data[i][j] - bmats.A_9_6.data[i][j] - bmats.A_9_7.data[i][j] - bmats.A_9_8.data[i][j] - bmats.A_9_9.data[i][j];
        }
    }
    return 0;
}
