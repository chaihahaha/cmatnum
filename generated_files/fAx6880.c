#include "fAx6880.h"

inline int fAx6880(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6880.data[i][j] = -bmats.A_25_17.data[i][j] - bmats.A_25_19.data[i][j] - bmats.A_25_20.data[i][j] - bmats.A_25_21.data[i][j] - bmats.A_25_22.data[i][j] - bmats.A_25_23.data[i][j] - bmats.A_25_24.data[i][j] - bmats.A_25_26.data[i][j] - bmats.A_25_27.data[i][j] - bmats.A_25_28.data[i][j];
        }
    }
    return 0;
}