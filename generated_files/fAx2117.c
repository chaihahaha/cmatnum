#include "fAx2117.h"

inline int fAx2117(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2117.data[i][j] = -bmats.A_13_17.data[i][j] - bmats.A_13_19.data[i][j] - bmats.A_13_20.data[i][j] - bmats.A_13_21.data[i][j] - bmats.A_13_22.data[i][j] - bmats.A_13_24.data[i][j] - bmats.A_13_25.data[i][j] - bmats.A_13_26.data[i][j] - bmats.A_13_27.data[i][j] - bmats.A_13_28.data[i][j] - bmats.A_13_29.data[i][j] - bmats.A_13_30.data[i][j] - bmats.A_13_31.data[i][j] - bmats.A_13_32.data[i][j] + bmats.Ax1867.data[i][j];
        }
    }
    return 0;
}
