#include "fAx6138.h"

inline int fAx6138(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6138.data[i][j] = -bmats.A_20_17.data[i][j] - bmats.A_20_22.data[i][j] - bmats.A_20_23.data[i][j] - bmats.A_20_24.data[i][j] - bmats.A_20_25.data[i][j] - bmats.A_20_26.data[i][j] - bmats.A_20_27.data[i][j] - bmats.A_20_31.data[i][j] - bmats.A_20_32.data[i][j];
        }
    }
    return 0;
}