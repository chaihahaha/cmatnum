#include "fAx4834.h"

inline int fAx4834(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4834.data[i][j] = -bmats.A_1_17.data[i][j] - bmats.A_1_18.data[i][j] - bmats.A_1_21.data[i][j] - bmats.A_1_22.data[i][j] - bmats.A_1_23.data[i][j] - bmats.A_1_24.data[i][j] - bmats.A_1_25.data[i][j] - bmats.A_1_26.data[i][j] - bmats.A_1_27.data[i][j] - bmats.A_1_28.data[i][j] - bmats.A_1_29.data[i][j] - bmats.A_1_30.data[i][j] - bmats.A_1_31.data[i][j] - bmats.A_1_32.data[i][j] + bmats.Ax4768.data[i][j];
        }
    }
    return 0;
}