#include "fAx8486.h"

inline int fAx8486(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8486.data[i][j] = -bmats.A_15_17.data[i][j] - bmats.A_15_18.data[i][j] - bmats.A_15_19.data[i][j] - bmats.A_15_20.data[i][j] - bmats.A_15_21.data[i][j] - bmats.A_15_22.data[i][j] - bmats.A_15_23.data[i][j] - bmats.A_15_24.data[i][j] - bmats.A_15_25.data[i][j] - bmats.A_15_28.data[i][j] - bmats.A_15_29.data[i][j] - bmats.A_15_30.data[i][j] - bmats.A_15_31.data[i][j] - bmats.A_15_32.data[i][j] + bmats.Ax722.data[i][j];
        }
    }
    return 0;
}
