#include "fAx2393.h"

inline int fAx2393(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2393.data[i][j] = -bmats.A_28_1.data[i][j] - bmats.A_28_11.data[i][j] - bmats.A_28_12.data[i][j] - bmats.A_28_13.data[i][j] - bmats.A_28_14.data[i][j] - bmats.A_28_15.data[i][j] - bmats.A_28_16.data[i][j] - bmats.A_28_2.data[i][j] - bmats.A_28_3.data[i][j] - bmats.A_28_4.data[i][j] - bmats.A_28_5.data[i][j] - bmats.A_28_6.data[i][j] - bmats.A_28_7.data[i][j] - bmats.A_28_8.data[i][j] + bmats.Ax2320.data[i][j];
        }
    }
    return 0;
}
