#include "fAx8340.h"

inline int fAx8340(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8340.data[i][j] = -bmats.A_26_17.data[i][j] - bmats.A_26_19.data[i][j] - bmats.A_26_23.data[i][j] - bmats.A_26_24.data[i][j] - bmats.A_26_25.data[i][j] - bmats.A_26_27.data[i][j] - bmats.A_26_31.data[i][j] - bmats.A_26_32.data[i][j];
        }
    }
    return 0;
}
