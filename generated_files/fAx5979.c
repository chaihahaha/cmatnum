#include "fAx5979.h"

inline int fAx5979(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax5979.data[i][j] = -bmats.A_32_18.data[i][j] - bmats.A_32_19.data[i][j] - bmats.A_32_20.data[i][j] - bmats.A_32_21.data[i][j] - bmats.A_32_22.data[i][j] - bmats.A_32_23.data[i][j] - bmats.A_32_24.data[i][j] - bmats.A_32_25.data[i][j] - bmats.A_32_26.data[i][j] - bmats.A_32_27.data[i][j] - bmats.A_32_28.data[i][j] - bmats.A_32_29.data[i][j] - bmats.A_32_30.data[i][j];
        }
    }
    return 0;
}
