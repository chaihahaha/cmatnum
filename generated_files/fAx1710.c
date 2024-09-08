#include "fAx1710.h"

inline int fAx1710(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1710.data[i][j] = -bmats.A_6_17.data[i][j] - bmats.A_6_18.data[i][j] - bmats.A_6_19.data[i][j] - bmats.A_6_20.data[i][j] - bmats.A_6_21.data[i][j] - bmats.A_6_22.data[i][j] - bmats.A_6_23.data[i][j] - bmats.A_6_24.data[i][j] - bmats.A_6_25.data[i][j] - bmats.A_6_26.data[i][j] - bmats.A_6_27.data[i][j] - bmats.A_6_28.data[i][j] - bmats.A_6_29.data[i][j] - bmats.A_6_31.data[i][j] - bmats.A_6_32.data[i][j];
        }
    }
    return 0;
}
