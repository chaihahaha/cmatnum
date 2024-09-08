#include "fAx2169.h"

inline int fAx2169(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2169.data[i][j] = -bmats.A_4_1.data[i][j] - bmats.A_4_10.data[i][j] - bmats.A_4_11.data[i][j] - bmats.A_4_2.data[i][j] - bmats.A_4_3.data[i][j] - bmats.A_4_4.data[i][j] - bmats.A_4_5.data[i][j] - bmats.A_4_6.data[i][j] - bmats.A_4_7.data[i][j];
        }
    }
    return 0;
}
