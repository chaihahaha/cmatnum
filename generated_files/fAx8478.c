#include "fAx8478.h"

inline int fAx8478(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8478.data[i][j] = -bmats.A_15_17.data[i][j] - bmats.A_15_18.data[i][j] - bmats.A_15_19.data[i][j] - bmats.A_15_20.data[i][j] - bmats.A_15_21.data[i][j] - bmats.A_15_24.data[i][j] - bmats.A_15_25.data[i][j] - bmats.A_15_26.data[i][j] - bmats.A_15_27.data[i][j] - bmats.A_15_28.data[i][j] - bmats.A_15_29.data[i][j] - bmats.A_15_30.data[i][j] - bmats.A_15_31.data[i][j] - bmats.A_15_32.data[i][j] + bmats.Ax722.data[i][j];
        }
    }
    return 0;
}
