#include "fAx2437.h"

inline int fAx2437(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2437.data[i][j] = -bmats.A_6_1.data[i][j] - bmats.A_6_10.data[i][j] - bmats.A_6_11.data[i][j] - bmats.A_6_4.data[i][j] - bmats.A_6_5.data[i][j] - bmats.A_6_6.data[i][j] - bmats.A_6_7.data[i][j] - bmats.A_6_8.data[i][j] - bmats.A_6_9.data[i][j];
        }
    }
    return 0;
}
