#include "fAx6429.h"

inline int fAx6429(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6429.data[i][j] = -bmats.A_22_18.data[i][j] - bmats.A_22_19.data[i][j] - bmats.A_22_20.data[i][j] - bmats.A_22_21.data[i][j] - bmats.A_22_23.data[i][j] - bmats.A_22_24.data[i][j] - bmats.A_22_25.data[i][j] - bmats.A_22_26.data[i][j] - bmats.A_22_27.data[i][j] - bmats.A_22_28.data[i][j] - bmats.A_22_31.data[i][j] - bmats.A_22_32.data[i][j];
        }
    }
    return 0;
}