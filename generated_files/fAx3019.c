#include "fAx3019.h"

inline int fAx3019(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3019.data[i][j] = -bmats.A_10_17.data[i][j] - bmats.A_10_18.data[i][j] - bmats.A_10_19.data[i][j] - bmats.A_10_21.data[i][j] - bmats.A_10_22.data[i][j] - bmats.A_10_23.data[i][j] - bmats.A_10_24.data[i][j] - bmats.A_10_26.data[i][j] - bmats.A_10_27.data[i][j] - bmats.A_10_28.data[i][j] - bmats.A_10_29.data[i][j] - bmats.A_10_30.data[i][j] - bmats.A_10_31.data[i][j] - bmats.A_10_32.data[i][j] + bmats.Ax2836.data[i][j];
        }
    }
    return 0;
}
